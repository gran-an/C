#include "s21_decimal_tests.h"

START_TEST(decimal_to_float_1) {
  s21_decimal src = init(0, 1, 0, 0, 123);
  float dest;
  int return_code = s21_from_decimal_to_float(src, &dest);
  ck_assert_float_eq(dest, 12.3);
  ck_assert_int_eq(return_code, 0);
}
END_TEST

START_TEST(decimal_to_float_2) {
  s21_decimal src = init(0, 2, 0, 0, 954);
  float dest;
  int return_code = s21_from_decimal_to_float(src, &dest);
  ck_assert_float_eq(dest, 9.54);
  ck_assert_int_eq(return_code, 0);
}
END_TEST

START_TEST(decimal_to_float_3) {
  s21_decimal src = init(1, 4, 0, 0, 100054);
  float dest;
  int return_code = s21_from_decimal_to_float(src, &dest);
  ck_assert_float_eq(dest, -10.0054);
  ck_assert_int_eq(return_code, 0);
}
END_TEST

START_TEST(decimal_to_float_4) {
  s21_decimal src = init(0, 5, 0, 1000024, 1000024);
  float dest;
  int return_code = s21_from_decimal_to_float(src, &dest);
  ck_assert_float_eq(dest, 42950703762.15128);
  ck_assert_int_eq(return_code, 0);
}
END_TEST

START_TEST(decimal_to_float_5) {
  s21_decimal src = init(1, 5, 0, 2000099, 1000099);
  float dest;
  int return_code = s21_from_decimal_to_float(src, &dest);
  ck_assert_float_eq(dest, -8.59036E+10);
  ck_assert_int_eq(return_code, 0);
}
END_TEST

START_TEST(decimal_to_float_6) {
  s21_decimal src = init(1, 3, 123, 123, 123);
  float dest;
  int return_code = s21_from_decimal_to_float(src, &dest);
  ck_assert_float_eq(dest, -2.2689496E+18);
  ck_assert_int_eq(return_code, 0);
}
END_TEST

START_TEST(decimal_to_float_7) {
  s21_decimal src = init(0, 0, 0, 0, 123456);
  float dest;
  int return_code = s21_from_decimal_to_float(src, &dest);
  ck_assert_float_eq(dest, 123456);
  ck_assert_int_eq(return_code, 0);
}
END_TEST

START_TEST(decimal_to_float_8) {
  s21_decimal src = init(1, 30, 1, 1, 1);
  float dest;
  int return_code = s21_from_decimal_to_float(src, &dest);
  ck_assert_int_eq(return_code, 1);
}
END_TEST

START_TEST(decimal_to_float_9) {
  s21_decimal src = {{1, 1, 1, 1000}};
  float dest;
  int return_code = s21_from_decimal_to_float(src, &dest);
  ck_assert_int_eq(return_code, 1);
}
END_TEST

Suite *s21_test_decimal_to_float() {
  Suite *test_set = suite_create("s21_decimal_to_float");
  TCase *test_group = tcase_create("s21_decimal_to_float_test_group");

  tcase_add_test(test_group, decimal_to_float_1);
  tcase_add_test(test_group, decimal_to_float_2);
  tcase_add_test(test_group, decimal_to_float_3);
  tcase_add_test(test_group, decimal_to_float_4);
  tcase_add_test(test_group, decimal_to_float_5);
  tcase_add_test(test_group, decimal_to_float_6);
  tcase_add_test(test_group, decimal_to_float_7);
  tcase_add_test(test_group, decimal_to_float_8);
  tcase_add_test(test_group, decimal_to_float_9);

  suite_add_tcase(test_set, test_group);

  return test_set;
}