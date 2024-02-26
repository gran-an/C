#include "headers/s21_calc.h"

#include <check.h>
#include <math.h>
#include <stdlib.h>

START_TEST(test_smart_calc_1) {  // '+' && '-' && '*'
  char input[256] = "17+2*2-8";
  double result = calculation(input, 0);
  ck_assert_double_eq(result, 17 + 2 * 2 - 8);
}
END_TEST

START_TEST(test_smart_calc_2) {  // '^' && '/'
  char input[256] = "5^2/4";
  double result = calculation(input, 0);
  ck_assert_double_eq(result, 6.25);
}
END_TEST

START_TEST(test_smart_calc_3) {  // unary '-' && '()'
  char input[256] = "-5+7*(-9*7/8)";
  double result = calculation(input, 0);
  ck_assert_double_eq_tol(result, -60.125, 0.001);
}
END_TEST

START_TEST(test_smart_calc_4) {  // 'mod' && '%'
  char input[256] = "(43mod8*6)%4";
  double result = calculation(input, 0);
  ck_assert_double_eq(result, 2.0);
}
END_TEST

START_TEST(test_smart_calc_5) {  // sin
  char input[256] = "6/sin(23)";
  double result = calculation(input, 0);
  ck_assert_double_eq_tol(result, 6 / sin(23), 0.000001);
}
END_TEST

START_TEST(test_smart_calc_6) {  // cos
  char input[256] = "7*cos(9)";
  double result = calculation(input, 0);
  ck_assert_double_eq_tol(result, 7 * cos(9), 0.000001);
}
END_TEST

START_TEST(test_smart_calc_7) {  // tan
  char input[256] = "9*tan(98)";
  double result = calculation(input, 0);
  ck_assert_double_eq_tol(result, 9 * tan(98), 0.000001);
}
END_TEST

START_TEST(test_smart_calc_8) {  // asin
  char input[256] = "76+asin(0.76)";
  double result = calculation(input, 0);
  ck_assert_double_eq_tol(result, 76 + asin(0.76), 0.000001);
}
END_TEST

START_TEST(test_smart_calc_9) {  // asin NAN
  char input[256] = "76+asin(25)";
  double result = calculation(input, 0);
  ck_assert_double_nan(result);
  ck_assert_double_nan(76 + asin(25));
}
END_TEST

START_TEST(test_smart_calc_10) {  // acos
  char input[256] = "102345(acos(0.01))";
  double result = calculation(input, 0);
  ck_assert_double_eq_tol(result, 102345 * (acos(0.01)), 0.000001);
}
END_TEST

START_TEST(test_smart_calc_11) {  // acos NAN
  char input[256] = "7.8*acos(67)";
  double result = calculation(input, 0);
  ck_assert_double_nan(result);
  ck_assert_double_nan(7.8 * acos(67));
}
END_TEST

START_TEST(test_smart_calc_12) {  // atan
  char input[256] = "10/(atan(0.32))";
  double result = calculation(input, 0);
  ck_assert_double_eq_tol(result, 10 / (atan(0.32)), 0.000001);
}
END_TEST

START_TEST(test_smart_calc_13) {  // sqrt
  char input[256] = "sqrt(57)/8";
  double result = calculation(input, 0);
  ck_assert_double_eq_tol(result, sqrt(57) / 8, 0.000001);
}
END_TEST

START_TEST(test_smart_calc_14) {  // ln
  char input[256] = "ln(57)*7-98+12(5*9)";
  double result = calculation(input, 0);
  ck_assert_double_eq_tol(result, log(57) * 7 - 98 + 12 * (5 * 9), 0.000001);
}
END_TEST

START_TEST(test_smart_calc_15) {  // log10
  char input[256] = "log(12345676)/67";
  double result = calculation(input, 0);
  ck_assert_double_eq_tol(result, log10(12345676) / 67, 0.000001);
}
END_TEST

START_TEST(test_smart_calc_16) {  // 'X' && '^'
  char input[256] = "4^5.213*sin(X)";
  double result = calculation(input, 6);
  ck_assert_double_eq_tol(result, pow(4, 5.213) * sin(6), 0.000001);
}
END_TEST

START_TEST(test_smart_calc_17) {  // 'x'
  char input[256] = "atan(X)+7(-12)";
  double result = calculation(input, 6124);
  ck_assert_double_eq_tol(result, atan(6124) + 7 * (-12), 0.000001);
}
END_TEST

START_TEST(test_smart_calc_18) {  // 'x'
  char input[256] = "(sin(X))^(sin(56))";
  double result = calculation(input, 64.6);
  ck_assert_double_eq_tol(result, pow(sin(64.6), sin(56)), 0.000001);
}
END_TEST

START_TEST(test_smart_calc_19) {  // 'x'
  char input[256] = "68/8(+78-90)";
  double result = calculation(input, 0);
  ck_assert_double_eq_tol(result, (double)68 / 8 * (+78 - 90), 0.000001);
}
END_TEST

/* INCORRECT INPUT */

START_TEST(test_smart_calc_20) {
  char input[256] = "*(5)";
  double result = calculation(input, 0);
  ck_assert_double_nan(result);
}
END_TEST

START_TEST(test_smart_calc_21) {
  char input[256] = "56-8*9+5)";
  double result = calculation(input, 0);
  ck_assert_double_nan(result);
}
END_TEST

START_TEST(test_smart_calc_22) {
  char input[256] = "fdkngsl";
  double result = calculation(input, 0);
  ck_assert_double_nan(result);
}
END_TEST

START_TEST(test_smart_calc_23) {
  char input[256] = "log()";
  double result = calculation(input, 0);
  ck_assert_double_nan(result);
}
END_TEST

START_TEST(test_smart_calc_24) {
  char input[256] = "56+";
  double result = calculation(input, 0);
  ck_assert_double_nan(result);
}
END_TEST

START_TEST(test_smart_calc_25) {
  char input[256] = "56&9";
  double result = calculation(input, 0);
  ck_assert_double_nan(result);
}
END_TEST

START_TEST(test_smart_calc_26) {
  char input[256] = "56*/9";
  double result = calculation(input, 0);
  ck_assert_double_nan(result);
}
END_TEST

START_TEST(test_smart_calc_27) {
  char input[256] = "67(-56=9)";
  double result = calculation(input, 0);
  ck_assert_double_nan(result);
}
END_TEST

START_TEST(test_smart_calc_28) {
  char input[256] = "";
  double result = calculation(input, 0);
  ck_assert_double_nan(result);
}
END_TEST

START_TEST(test_smart_calc_29) {
  char input[256] = " ";
  double result = calculation(input, 0);
  ck_assert_double_nan(result);
}
END_TEST

END_TEST

Suite *test_calc(void) {
  Suite *s;
  TCase *tc_values;
  s = suite_create("test_calc");

  tc_values = tcase_create("values");
  tcase_add_test(tc_values, test_smart_calc_1);
  tcase_add_test(tc_values, test_smart_calc_2);
  tcase_add_test(tc_values, test_smart_calc_3);
  tcase_add_test(tc_values, test_smart_calc_4);
  tcase_add_test(tc_values, test_smart_calc_5);
  tcase_add_test(tc_values, test_smart_calc_6);
  tcase_add_test(tc_values, test_smart_calc_7);
  tcase_add_test(tc_values, test_smart_calc_8);
  tcase_add_test(tc_values, test_smart_calc_9);
  tcase_add_test(tc_values, test_smart_calc_10);
  tcase_add_test(tc_values, test_smart_calc_11);
  tcase_add_test(tc_values, test_smart_calc_12);
  tcase_add_test(tc_values, test_smart_calc_13);
  tcase_add_test(tc_values, test_smart_calc_14);
  tcase_add_test(tc_values, test_smart_calc_15);
  tcase_add_test(tc_values, test_smart_calc_16);
  tcase_add_test(tc_values, test_smart_calc_17);
  tcase_add_test(tc_values, test_smart_calc_18);
  tcase_add_test(tc_values, test_smart_calc_19);
  tcase_add_test(tc_values, test_smart_calc_20);
  tcase_add_test(tc_values, test_smart_calc_21);
  tcase_add_test(tc_values, test_smart_calc_22);
  tcase_add_test(tc_values, test_smart_calc_23);
  tcase_add_test(tc_values, test_smart_calc_24);
  tcase_add_test(tc_values, test_smart_calc_25);
  tcase_add_test(tc_values, test_smart_calc_26);
  tcase_add_test(tc_values, test_smart_calc_27);
  tcase_add_test(tc_values, test_smart_calc_28);
  tcase_add_test(tc_values, test_smart_calc_29);
  suite_add_tcase(s, tc_values);
  return s;
}

void case_test(Suite *s, int *fail) {
  SRunner *runner = srunner_create(s);
  srunner_set_fork_status(runner, CK_NOFORK);
  srunner_run_all(runner, CK_NORMAL);
  *fail = srunner_ntests_failed(runner);
  srunner_free(runner);
}

int main() {
  int fail = 0;
  case_test(test_calc(), &fail);
  return fail;
}
