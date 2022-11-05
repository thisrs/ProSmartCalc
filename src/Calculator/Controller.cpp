#include "Controller.h"

using namespace s21;

Controller::Controller(const char *expression) {
  this->expression = expression;
  this->calcModel = Calculator();
}

void Controller::CheckString() {
  this->status = Calculator::check_expression(this->expression);
}

::status Controller::getStatus() { return this->status; }

double Controller::getDoubleResult() { return this->result; }

QVector<double> Controller::getX() { return this->x; }

QVector<double> Controller::getY() { return this->y; }

void Controller::getResult() {
  this->CheckString();

  switch (this->status) {
    case GRAPH:
      for (int X = -9; X <= 9; ++X) {
        this->x.push_back(X);

        this->calcModel.parse_string(this->expression);
        this->y.push_back(this->calcModel.calc(X));
      }
      break;

    case NORMAL:
      this->calcModel.parse_string(this->expression);
      this->result = this->calcModel.calc();
      break;
  }
}
