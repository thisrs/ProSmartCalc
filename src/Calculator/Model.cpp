#include "Model.h"

using namespace s21;
// Default Getters & Setters

[[nodiscard]] double Lexeme::GetValue() const { return value_; }
[[nodiscard]] lexeme_type Lexeme::GetLexemeType() const { return lexeme_type_; }
[[nodiscard]] rpn_priority Lexeme::GetRpnPriority() const {
  return rpn_priority_;
}

void Lexeme::SetValue(double value) { value_ = value; }

// Char to Lexeme fields

rpn_priority Lexeme::CharToPriority(const char **expression) {
  rpn_priority priority;

  switch (**expression) {
    case '/':
    case '%':
    case '*':
      priority = MID;
      break;

    case '^':
      priority = HIGH;
      break;

    case '(':
    case ')':
      priority = VERY_HIGH;
      break;

    default:
      priority = LOW;
      break;
  }

  return priority;
}

lexeme_type Lexeme::CharToType(const char **expression) {
  lexeme_type type;
  switch (**expression) {
    case '+':
      type = PLUS;
      break;
    case '-':
      type = MINUS;
      break;
    case '/':
      type = DIVIDE;
      break;
    case '*':
      type = MULTIPLY;
      break;
    case '^':
      type = POWER;
      break;
    case '%':
      type = MODULATE;
      break;
    case '(':
      type = LEFT;
      break;
    case ')':
      type = RIGHT;
      break;
  }
  return type;
}

// Reverse to stack RPN Support Functions

void Calculator::set_x(const char **expression) {
  this->final.push(Lexeme(0, X, LOW));
  (*expression)++;
}

void Calculator::set_number(const char **expression) {
  char valid_chars[] = "1234567890.";
  char number_buffer[BUFF_SIZE] = {'\0'};

  for (int i = 0; **expression && strchr(valid_chars, **expression);
       i++, (*expression)++) {
    number_buffer[i] = **expression;
  }

  this->final.push(Lexeme(strtod(number_buffer, nullptr), NUMBER, LOW));
}

void Calculator::set_unary_minus(const char **expression) {
  if (**expression == '(') {
    this->buffer.push(Lexeme(0, LEFT, VERY_HIGH));
    (*expression)++;
  }
  this->final.push(Lexeme(0, NUMBER, LOW));
  (*expression)++;

  if (**expression == 'x')
    set_x(expression);
  else
    set_number(expression);

  this->final.push(Lexeme(0, MINUS, LOW));
}

void Calculator::set_function(const char **expression) {
  char func_buff[5] = {'\0'};
  for (int i = 0; i < (int)strlen(func_buff) || **expression != '(';
       (*expression)++, i++) {
    func_buff[i] = **expression;
  }
  if (!strcmp(func_buff, "cos"))
    this->buffer.push(Lexeme(0, COS, HIGH));
  else if (!strcmp(func_buff, "sin"))
    this->buffer.push(Lexeme(0, SIN, HIGH));
  else if (!strcmp(func_buff, "tan"))
    this->buffer.push(Lexeme(0, TAN, HIGH));
  else if (!strcmp(func_buff, "acos"))
    this->buffer.push(Lexeme(0, ACOS, HIGH));
  else if (!strcmp(func_buff, "asin"))
    this->buffer.push(Lexeme(0, ASIN, HIGH));
  else if (!strcmp(func_buff, "atan"))
    this->buffer.push(Lexeme(0, ATAN, HIGH));
  else if (!strcmp(func_buff, "sqrt"))
    this->buffer.push(Lexeme(0, SQRT, HIGH));
  else if (!strcmp(func_buff, "ln"))
    this->buffer.push(Lexeme(0, LN, HIGH));
  else if (!strcmp(func_buff, "log"))
    this->buffer.push(Lexeme(0, LOG, HIGH));
}

void Calculator::set_operator(const char **expression) {
  bool buff_is_empty = this->buffer.empty();

  if (**expression == ')') {
    do {
      if (this->buffer.top().GetLexemeType() != LEFT)
        this->final.push(Lexeme(0, this->buffer.top().GetLexemeType(),
                                this->buffer.top().GetRpnPriority()));
      if (!this->buffer.empty()) this->buffer.pop();
      if (!this->buffer.empty()) break;
    } while (this->buffer.top().GetLexemeType() != LEFT);
    if (!this->buffer.empty()) this->buffer.pop();
  } else if (buff_is_empty ||
             Lexeme::CharToPriority(expression) >
                 this->buffer.top().GetRpnPriority() ||
             this->buffer.top().GetLexemeType() == LEFT) {
    this->buffer.push(Lexeme(0, Lexeme::CharToType(expression),
                             Lexeme::CharToPriority(expression)));
  } else {
    if (this->buffer.top().GetLexemeType() != RIGHT &&
        this->buffer.top().GetLexemeType() != LEFT)
      this->final.push(Lexeme(0, this->buffer.top().GetLexemeType(),
                              this->buffer.top().GetRpnPriority()));
    this->buffer.pop();
    this->buffer.push(Lexeme(0, Lexeme::CharToType(expression),
                             Lexeme::CharToPriority(expression)));
  }

  if (**expression) (*expression)++;
}

// Check functions

status Calculator::check_expression(const char *expression) {
  if (strlen(expression) < 3) throw std::invalid_argument("USE MORE SYMBOLS");

  char normal_symbols[] = "1234567890.+-x ()^%/*cosnitaqrlg";
  status type = NORMAL;
  int brackts1 = 0;
  int brackts2 = 0;
  while (*expression) {
    if(*expression == ')') brackts1++;
    if(*expression == '(') brackts2++;
    if(*expression == ')' && brackts2 == 0) throw std::invalid_argument("INVALID ARGUMENT");
    if (*expression == 'x') type = GRAPH;
    if (!strchr(normal_symbols, *expression)) {
      throw std::invalid_argument("INVALID ARGUMENT");
    }
    expression++;
  }
  if ( brackts1 != brackts2) throw std::invalid_argument("INVALID ARGUMENT");

  return type;
}

// Reverse string to RPN Stack

void Calculator::parse_string(const char *expression) {
  char nums[] = "1234567890";
  char oprtrs[] = "-+*/^()%";
  char funcs[] = "cstal";

  if (expression[0] == '-') set_unary_minus(&expression);

  while (*expression) {
    if (*expression == ' ') {
      expression++;
      continue;
    }
    if (strchr(funcs, *expression)) set_function(&expression);
    if (*expression == 'x') set_x(&expression);
    if (*expression == '(' && *(expression + 1) == '-')
      set_unary_minus(&expression);
    if (strchr(nums, *expression) && *expression) set_number(&expression);
    if (strchr(oprtrs, *expression) && *expression) set_operator(&expression);
  }
  while (!this->buffer.empty()) {
    if (this->buffer.top().GetLexemeType() != RIGHT &&
        this->buffer.top().GetLexemeType() != LEFT)
      this->final.push(Lexeme(this->buffer.top().GetValue(),
                              this->buffer.top().GetLexemeType(),
                              this->buffer.top().GetRpnPriority()));
    this->buffer.pop();
  }
}

// Calc functions

double Calculator::calc(double x_value) {
  while (!this->final.empty()) {
    this->buffer.push(Lexeme(this->final.top().GetValue(),
                             this->final.top().GetLexemeType(),
                             this->final.top().GetRpnPriority()));
    this->final.pop();
  }

  double buff_value = 0;

  while (!this->buffer.empty()) {
    switch (this->buffer.top().GetLexemeType()) {
      case X:
        this->buffer.top().SetValue(x_value);
      case NUMBER:
        this->final.push(Lexeme(this->buffer.top().GetValue(),
                                this->buffer.top().GetLexemeType(),
                                this->buffer.top().GetRpnPriority()));
        this->buffer.pop();
        break;
      case PLUS:
        buff_value = this->final.top().GetValue();
        this->final.pop();
        this->final.top().SetValue(this->final.top().GetValue() + buff_value);
        this->buffer.pop();
        break;
      case MINUS:
        buff_value = this->final.top().GetValue();
        this->final.pop();
        this->final.top().SetValue(this->final.top().GetValue() - buff_value);
        this->buffer.pop();
        break;
      case DIVIDE:
        buff_value = this->final.top().GetValue();
        this->final.pop();
        this->final.top().SetValue(this->final.top().GetValue() / buff_value);
        this->buffer.pop();
        break;
      case MULTIPLY:
        buff_value = this->final.top().GetValue();
        this->final.pop();
        this->final.top().SetValue(this->final.top().GetValue() * buff_value);
        this->buffer.pop();
        break;
      case POWER:
        buff_value = this->final.top().GetValue();
        this->final.pop();
        this->final.top().SetValue(
            pow(this->final.top().GetValue(), buff_value));
        this->buffer.pop();
        break;
      case MODULATE:
        buff_value = this->final.top().GetValue();
        this->final.pop();
        this->final.top().SetValue(
            fmod(this->final.top().GetValue(), buff_value));
        this->buffer.pop();
        break;
      case COS:
        this->final.top().SetValue(cos(this->final.top().GetValue()));
        this->buffer.pop();
        break;
      case SIN:
        this->final.top().SetValue(sin(this->final.top().GetValue()));
        this->buffer.pop();
        break;
      case TAN:
        this->final.top().SetValue(tan(this->final.top().GetValue()));
        this->buffer.pop();
        break;
      case ACOS:
        this->final.top().SetValue(acos(this->final.top().GetValue()));
        this->buffer.pop();
        break;
      case ASIN:
        this->final.top().SetValue(asin(this->final.top().GetValue()));
        this->buffer.pop();
        break;
      case ATAN:
        this->final.top().SetValue(atan(this->final.top().GetValue()));
        this->buffer.pop();
        break;
      case SQRT:
        this->final.top().SetValue(sqrt(this->final.top().GetValue()));
        this->buffer.pop();
        break;
      case LN:
        this->final.top().SetValue(log10(this->final.top().GetValue()));
        this->buffer.pop();
        break;
      case LOG:
        this->final.top().SetValue(log(this->final.top().GetValue()));
        this->buffer.pop();
        break;
      case LEFT:
      case RIGHT:
        break;
    }
  }
  return final.top().GetValue();
}