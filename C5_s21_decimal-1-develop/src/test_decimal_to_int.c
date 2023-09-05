#include "s21_decimal_tests.h"

START_TEST(decimal_to_int_1) {
  s21_decimal src = init(0, 1, 0, 0, 123);
  int dest;
  int return_code = s21_from_decimal_to_int(src, &dest);
  ck_assert_int_eq(dest, 12);
  ck_assert_int_eq(return_code, 0);
}
END_TEST

START_TEST(decimal_to_int_2) {
  s21_decimal src = init(0, 2, 0, 0, 954);
  int dest;
  int return_code = s21_from_decimal_to_int(src, &dest);
  ck_assert_int_eq(dest, 9);
  ck_assert_int_eq(return_code, 0);
}
END_TEST

START_TEST(decimal_to_int_3) {
  s21_decimal src = init(1, 4, 0, 0, 100054);
  int dest;
  int return_code = s21_from_decimal_to_int(src, &dest);
  ck_assert_int_eq(dest, -10);
  ck_assert_int_eq(return_code, 0);
}
END_TEST

START_TEST(decimal_to_int_4) {
  s21_decimal src = init(0, 5, 0, 1000024, 1000024);
  int dest;
  int return_code = s21_from_decimal_to_int(src, &dest);
  ck_assert_int_eq(return_code, 1);
}
END_TEST

START_TEST(decimal_to_int_5) {
  s21_decimal src = init(1, 5, 1000000, 2000099, 1000099);
  int dest;
  int return_code = s21_from_decimal_to_int(src, &dest);
  ck_assert_int_eq(return_code, 1);
}
END_TEST

START_TEST(decimal_to_int_6) {
  s21_decimal src = init(1, 3, 123, 123, 123);
  int dest;
  int return_code = s21_from_decimal_to_int(src, &dest);
  ck_assert_int_eq(return_code, 1);
}
END_TEST

START_TEST(decimal_to_int_7) {
  s21_decimal src = init(0, 3, 0, 0, 123456);
  int dest;
  int return_code = s21_from_decimal_to_int(src, &dest);
  ck_assert_int_eq(dest, 123);
  ck_assert_int_eq(return_code, 0);
}
END_TEST

START_TEST(decimal_to_int_8) {
  s21_decimal src = init(1, 30, 1, 1, 1);
  int dest;
  int return_code = s21_from_decimal_to_int(src, &dest);
  ck_assert_int_eq(return_code, 1);
}
END_TEST

START_TEST(decimal_to_int_9) {
  s21_decimal src = {{1, 1, 1, 1000}};
  int dest;
  int return_code = s21_from_decimal_to_int(src, &dest);
  ck_assert_int_eq(return_code, 1);
}
END_TEST

Suite *s21_test_decimal_to_int() {
  Suite *test_set = suite_create("s21_decimal_to_int");
  TCase *test_group = tcase_create("s21_decimal_to_int_test_group");

  tcase_add_test(test_group, decimal_to_int_1);
  tcase_add_test(test_group, decimal_to_int_2);
  tcase_add_test(test_group, decimal_to_int_3);
  tcase_add_test(test_group, decimal_to_int_4);
  tcase_add_test(test_group, decimal_to_int_5);
  tcase_add_test(test_group, decimal_to_int_6);
  tcase_add_test(test_group, decimal_to_int_7);
  tcase_add_test(test_group, decimal_to_int_8);
  tcase_add_test(test_group, decimal_to_int_9);

  suite_add_tcase(test_set, test_group);

  return test_set;
}