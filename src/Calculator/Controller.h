#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QVector>
#include <exception>
#include <vector>

#include "Model.h"

namespace s21 {
// Controller Interface
class Controller {
  const char *expression;
  Calculator calcModel;
  QVector<double> x, y;
  double result{};
  status status;

 public:
  // Constructor
  explicit Controller(const char *expression);
  // Controller Func
  void CheckString();
  ::s21::status getStatus();
  [[nodiscard]] double getDoubleResult();
  QVector<double> getX();
  QVector<double> getY();
  void getResult();
};
}  // namespace s21
#endif  // CONTROLLER_H
