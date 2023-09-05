#include "s21_decimal_tests.h"

START_TEST(negate_1) {
  s21_decimal src = init(0, 2, 0, 0, 954);
  s21_decimal dest;
  int return_code = s21_negate(src, &dest);
  ck_assert_uint_eq(dest.bits[0], 954);
  ck_assert_uint_eq(dest.bits[1], 0);
  ck_assert_uint_eq(dest.bits[2], 0);
  ck_assert_uint_eq(dest.bits[3], 2147614720);
  ck_assert_int_eq(return_code, 0);
}
END_TEST

START_TEST(negate_2) {
  s21_decimal src = init(1, 28, 123, 0, 954);
  s21_decimal dest;
  int return_code = s21_negate(src, &dest);
  ck_assert_uint_eq(dest.bits[0], 954);
  ck_assert_uint_eq(dest.bits[1], 0);
  ck_assert_uint_eq(dest.bits[2], 123);
  ck_assert_uint_eq(dest.bits[3], 1835008);
  ck_assert_int_eq(return_code, 0);
}
END_TEST

START_TEST(negate_3) {
  s21_decimal src = init(1, 30, 1, 1, 1);
  s21_decimal dest = {{1}};
  int return_code = s21_negate(src, &dest);
  ck_assert_int_eq(return_code, 1);
}
END_TEST

START_TEST(negate_4) {
  s21_decimal src = {{0, 0, 0, 1000}};
  s21_decimal dest = {{1}};
  int return_code = s21_negate(src, &dest);
  ck_assert_int_eq(return_code, 1);
}
END_TEST

Suite *s21_test_negate() {
  Suite *test_set = suite_create("s21_negate");
  TCase *test_group = tcase_create("s21_negate_test_group");

  tcase_add_test(test_group, negate_1);
  tcase_add_test(test_group, negate_2);
  tcase_add_test(test_group, negate_3);
  tcase_add_test(test_group, negate_4);

  suite_add_tcase(test_set, test_group);

  return test_set;
}