#ifndef SMARTCALC2__MODEL_H_
#define SMARTCALC2__MODEL_H_

#include <cmath>
#include <cstring>
#include <exception>
#include <stack>
#include <stdexcept>

namespace s21 {

constexpr size_t BUFF_SIZE = 256;

// Expression status
enum status {
  NORMAL,
  GRAPH,
};

enum lexeme_type {
  NUMBER = 0,
  X = 1,
  PLUS = 2,
  MINUS = 3,
  DIVIDE = 4,
  MULTIPLY = 5,
  POWER = 6,
  MODULATE = 7,
  COS = 8,
  SIN = 9,
  TAN = 10,
  ACOS = 11,
  ASIN = 12,
  ATAN = 13,
  SQRT = 14,
  LN = 15,
  LOG = 16,
  LEFT = 17,
  RIGHT = 18,
};

enum rpn_priority { LOW = 0, MID = 1, HIGH = 2, VERY_HIGH = 3 };

class Lexeme {
  double value_;
  lexeme_type lexeme_type_;
  rpn_priority rpn_priority_;

 public:
  Lexeme(double value, lexeme_type lexeme_type, rpn_priority rpn_priority)
      : value_(value), lexeme_type_(lexeme_type), rpn_priority_(rpn_priority) {}
  // Default Getters & Setters

  [[nodiscard]] double GetValue() const;
  [[nodiscard]] lexeme_type GetLexemeType() const;
  [[nodiscard]] rpn_priority GetRpnPriority() const;

  void SetValue(double value);

  // Char to Lexeme fields

  static rpn_priority CharToPriority(const char **expression);

  static lexeme_type CharToType(const char **expression);
};

class Calculator {
 private:
  std::stack<Lexeme> buffer;
  std::stack<Lexeme> final;

  // Reverse to stack RPN Support Functions

  void set_x(const char **expression);

  void set_number(const char **expression);

  void set_unary_minus(const char **expression);

  void set_function(const char **expression);

  void set_operator(const char **expression);

 public:
  // Check functions

  static status check_expression(const char *expression);

  // Reverse string to RPN Stack

  void parse_string(const char *expression);

  // Calc functions

  double calc(double x_value = 0);
};

}  // namespace s21

#endif  // SMARTCALC2__MODEL_H_



