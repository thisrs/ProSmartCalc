#include <cmath>

#include "Model.h"
#include "gtest/gtest.h"
using s21::Calculator;

TEST(ModelTEST, Functions_1) {
  Calculator my;
  const char *expression = "10+5";

  my.parse_string(expression);
  double result = my.calc();
  EXPECT_DOUBLE_EQ(result, 10 + 5);
}

TEST(ModelTEST, Functions_2) {
  Calculator my;
  const char *expression = "-10+25";

  my.parse_string(expression);
  double result = my.calc();
  EXPECT_DOUBLE_EQ(result, -10 + 25);
}

TEST(ModelTEST, Functions_3) {
  Calculator my;
  const char *expression = "25*5+(2-3)+2/44";

  my.parse_string(expression);
  int result = my.calc();
  EXPECT_EQ(result, 25 * 5 + (2 - 3) + 2 / 44);
}

TEST(ModelTEST, Functions_4) {
  Calculator my;
  const char *expression = "sin(5/2)*cos(-2+19)";

  my.parse_string(expression);
  double result = my.calc();
  double result2 = sin(5 / 2) * cos(-2 + 19);
  EXPECT_EQ((int)result, (int)result2);
}

TEST(InputTEST, Function_1) {
  try {
    Calculator::check_expression("dasdasdsadas+12");
  } catch (std::exception &ex) {
    EXPECT_STREQ("INVALID ARGUMENT", ex.what());
  }
}

TEST(InputTEST, Function_2) {
  try {
    Calculator::check_expression("12+5+z");
  } catch (std::exception &ex) {
    EXPECT_STREQ("INVALID ARGUMENT", ex.what());
  }
}
