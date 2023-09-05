#include "s21_decimal_tests.h"

START_TEST(less_1) {
  s21_decimal a = init(0, 2, 0, 0, 954);
  s21_decimal b = init(0, 2, 0, 0, 954);
  ck_assert_int_eq(s21_is_less(a, b), 0);
}
END_TEST

START_TEST(less_2) {
  s21_decimal a = init(0, 2, 91054, 0, 1);
  s21_decimal b = init(0, 2, 91054, 0, 954);
  ck_assert_int_eq(s21_is_less(a, b), 1);
}
END_TEST

START_TEST(less_3) {
  s21_decimal a = init(0, 2, 0, 0, 10000);
  s21_decimal b = init(0, 0, 0, 0, 100);
  ck_assert_int_eq(s21_is_less(a, b), 0);
}
END_TEST

START_TEST(less_4) {
  s21_decimal a = init(1, 0, 10000, 0, 10000);
  s21_decimal b = init(0, 3, 10000, 523, 100);
  ck_assert_int_eq(s21_is_less(a, b), 1);
}
END_TEST

START_TEST(less_5) {
  s21_decimal a = init(1, 4, 4444, 3333, 2222);
  s21_decimal b = init(0, 4, 4444, 3333, 2222);
  ck_assert_int_eq(s21_is_less(a, b), 1);
}
END_TEST

START_TEST(less_6) {
  s21_decimal a = init(1, 4, 123, 456, 789);
  s21_decimal b = init(1, 4, 987, 654, 321);
  ck_assert_int_eq(s21_is_less(a, b), 0);
}
END_TEST

START_TEST(less_7) {
  s21_decimal a = init(1, 20, 0, 0, 0);
  s21_decimal b = init(0, 5, 0, 0, 0);
  ck_assert_int_eq(s21_is_less(a, b), 1);
}
END_TEST

START_TEST(less_8) {
  s21_decimal a = init(0, 3, 10000, 1, 0);
  s21_decimal b = init(0, 3, 0, 1, 10000);
  ck_assert_int_eq(s21_is_less(a, b), 0);
}
END_TEST

START_TEST(less_9) {
  s21_decimal a = init(0, 28, 0, 0, 0);
  s21_decimal b = init(0, 6, 0, 0, 0);
  ck_assert_int_eq(s21_is_less(a, b), 0);
}
END_TEST

START_TEST(less_10) {
  s21_decimal a = init(1, 0, 0, 0, 0);
  s21_decimal b = init(0, 0, 0, 0, 0);
  ck_assert_int_eq(s21_is_less(a, b), 1);
}
END_TEST

START_TEST(less_11) {
  s21_decimal a = init(0, 2, 564, 46565, 79889);
  s21_decimal b = init(0, 3, 564, 46565, 79889);
  ck_assert_int_eq(s21_is_less(a, b), 0);
}
END_TEST

START_TEST(less_12) {
  s21_decimal a = init(0, 4, 0, 2048, 954);
  s21_decimal b = init(0, 4, 0, 2048, 954);
  ck_assert_int_eq(s21_is_less(a, b), 0);
}
END_TEST

START_TEST(less_13) {
  s21_decimal a = init(0, 10, 64, 0, 0);
  s21_decimal b = init(0, 10, 64, 0, 0);
  ck_assert_int_eq(s21_is_less(a, b), 0);
}
END_TEST

START_TEST(less_14) {
  s21_decimal a = init(1, 0, 0, 4064, 0);
  s21_decimal b = init(1, 0, 0, 4064, 0);
  ck_assert_int_eq(s21_is_less(a, b), 0);
}
END_TEST

START_TEST(less_15) {
  s21_decimal a = init(0, 0, 40, 0, 1);
  s21_decimal b = init(0, 0, 40, 0, 1);
  ck_assert_int_eq(s21_is_less(a, b), 0);
}
END_TEST

START_TEST(less_16) {
  s21_decimal a = init(1, 5, 987, 654, 321);
  s21_decimal b = init(1, 5, 123, 456, 789);
  ck_assert_int_eq(s21_is_less(a, b), 1);
}
END_TEST

Suite *s21_test_less() {
  Suite *test_set = suite_create("s21_less");
  TCase *test_group = tcase_create("s21_less_test_group");

  tcase_add_test(test_group, less_1);
  tcase_add_test(test_group, less_2);
  tcase_add_test(test_group, less_3);
  tcase_add_test(test_group, less_4);
  tcase_add_test(test_group, less_5);
  tcase_add_test(test_group, less_6);
  tcase_add_test(test_group, less_7);
  tcase_add_test(test_group, less_8);
  tcase_add_test(test_group, less_9);
  tcase_add_test(test_group, less_10);
  tcase_add_test(test_group, less_11);
  tcase_add_test(test_group, less_12);
  tcase_add_test(test_group, less_13);
  tcase_add_test(test_group, less_14);
  tcase_add_test(test_group, less_15);
  tcase_add_test(test_group, less_16);

  suite_add_tcase(test_set, test_group);

  return test_set;
}