#include "s21_decimal_tests.h"

START_TEST(float_to_decimal_1) {
  float src = 256.64;
  s21_decimal dest;
  int return_code = s21_from_float_to_decimal(src, &dest);
  ck_assert_uint_eq(dest.bits[0], 25664);
  ck_assert_uint_eq(dest.bits[1], 0);
  ck_assert_uint_eq(dest.bits[2], 0);
  ck_assert_uint_eq(dest.bits[3], 131072);
  ck_assert_int_eq(return_code, 0);
}
END_TEST

START_TEST(float_to_decimal_2) {
  float src = -1028.7563;
  s21_decimal dest;
  int return_code = s21_from_float_to_decimal(src, &dest);
  ck_assert_uint_eq(dest.bits[0], 1028756);
  ck_assert_uint_eq(dest.bits[1], 0);
  ck_assert_uint_eq(dest.bits[2], 0);
  ck_assert_uint_eq(dest.bits[3], 2147680256);
  ck_assert_int_eq(return_code, 0);
}
END_TEST

START_TEST(float_to_decimal_3) {
  float src = 0.0000000256;
  s21_decimal dest;
  int return_code = s21_from_float_to_decimal(src, &dest);
  ck_assert_uint_eq(dest.bits[0], 256);
  ck_assert_uint_eq(dest.bits[1], 0);
  ck_assert_uint_eq(dest.bits[2], 0);
  ck_assert_uint_eq(dest.bits[3], 655360);
  ck_assert_int_eq(return_code, 0);
}
END_TEST

START_TEST(float_to_decimal_4) {
  float src = 1429787.3121323132900000;
  s21_decimal dest;
  int return_code = s21_from_float_to_decimal(src, &dest);
  ck_assert_uint_eq(dest.bits[0], 1429787);
  ck_assert_uint_eq(dest.bits[1], 0);
  ck_assert_uint_eq(dest.bits[2], 0);
  ck_assert_uint_eq(dest.bits[3], 0);
  ck_assert_int_eq(return_code, 0);
}
END_TEST

START_TEST(float_to_decimal_5) {
  float src = -123456.000000099;
  s21_decimal dest;
  int return_code = s21_from_float_to_decimal(src, &dest);
  ck_assert_uint_eq(dest.bits[0], 123456);
  ck_assert_uint_eq(dest.bits[1], 0);
  ck_assert_uint_eq(dest.bits[2], 0);
  ck_assert_uint_eq(dest.bits[3], 2147483648);
  ck_assert_int_eq(return_code, 0);
}
END_TEST

START_TEST(float_to_decimal_6) {
  float src = 3.1415926535;
  s21_decimal dest;
  int return_code = s21_from_float_to_decimal(src, &dest);
  ck_assert_uint_eq(dest.bits[0], 3141593);
  ck_assert_uint_eq(dest.bits[1], 0);
  ck_assert_uint_eq(dest.bits[2], 0);
  ck_assert_uint_eq(dest.bits[3], 393216);
  ck_assert_int_eq(return_code, 0);
}
END_TEST

START_TEST(float_to_decimal_7) {
  float src = 2.7182818284590451;
  s21_decimal dest;
  int return_code = s21_from_float_to_decimal(src, &dest);
  ck_assert_uint_eq(dest.bits[0], 2718282);
  ck_assert_uint_eq(dest.bits[1], 0);
  ck_assert_uint_eq(dest.bits[2], 0);
  ck_assert_uint_eq(dest.bits[3], 393216);
  ck_assert_int_eq(return_code, 0);
}
END_TEST

START_TEST(float_to_decimal_8) {
  float src = 0;
  s21_decimal dest;
  int return_code = s21_from_float_to_decimal(src, &dest);
  ck_assert_uint_eq(dest.bits[0], 0);
  ck_assert_uint_eq(dest.bits[1], 0);
  ck_assert_uint_eq(dest.bits[2], 0);
  ck_assert_uint_eq(dest.bits[3], 0);
  ck_assert_int_eq(return_code, 0);
}
END_TEST

START_TEST(float_to_decimal_9) {
  float src = -16524;
  s21_decimal dest;
  int return_code = s21_from_float_to_decimal(src, &dest);
  ck_assert_uint_eq(dest.bits[0], 16524);
  ck_assert_uint_eq(dest.bits[1], 0);
  ck_assert_uint_eq(dest.bits[2], 0);
  ck_assert_uint_eq(dest.bits[3], 2147483648);
  ck_assert_int_eq(return_code, 0);
}
END_TEST

Suite *s21_test_float_to_decimal() {
  Suite *test_set = suite_create("s21_float_to_decimal");
  TCase *test_group = tcase_create("s21_float_to_decimal_test_group");

  tcase_add_test(test_group, float_to_decimal_1);
  tcase_add_test(test_group, float_to_decimal_2);
  tcase_add_test(test_group, float_to_decimal_3);
  tcase_add_test(test_group, float_to_decimal_4);
  tcase_add_test(test_group, float_to_decimal_5);
  tcase_add_test(test_group, float_to_decimal_6);
  tcase_add_test(test_group, float_to_decimal_7);
  tcase_add_test(test_group, float_to_decimal_8);
  tcase_add_test(test_group, float_to_decimal_9);

  suite_add_tcase(test_set, test_group);

  return test_set;
}