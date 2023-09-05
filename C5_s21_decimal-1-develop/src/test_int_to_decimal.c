#include "s21_decimal_tests.h"

START_TEST(int_to_decimal_1) {
  int src = 256;
  s21_decimal dest;
  int return_code = s21_from_int_to_decimal(src, &dest);
  ck_assert_uint_eq(dest.bits[0], 256);
  ck_assert_uint_eq(dest.bits[1], 0);
  ck_assert_uint_eq(dest.bits[2], 0);
  ck_assert_uint_eq(dest.bits[3], 0);
  ck_assert_int_eq(return_code, 0);
}
END_TEST

START_TEST(int_to_decimal_2) {
  int src = -1028;
  s21_decimal dest;
  int return_code = s21_from_int_to_decimal(src, &dest);
  ck_assert_uint_eq(dest.bits[0], 1028);
  ck_assert_uint_eq(dest.bits[1], 0);
  ck_assert_uint_eq(dest.bits[2], 0);
  ck_assert_uint_eq(dest.bits[3], 2147483648);
  ck_assert_int_eq(return_code, 0);
}
END_TEST

START_TEST(int_to_decimal_3) {
  int src = 587389358;
  s21_decimal dest;
  int return_code = s21_from_int_to_decimal(src, &dest);
  ck_assert_uint_eq(dest.bits[0], 587389358);
  ck_assert_uint_eq(dest.bits[1], 0);
  ck_assert_uint_eq(dest.bits[2], 0);
  ck_assert_uint_eq(dest.bits[3], 0);
  ck_assert_int_eq(return_code, 0);
}
END_TEST

START_TEST(int_to_decimal_4) {
  int src = -31213231;
  s21_decimal dest;
  int return_code = s21_from_int_to_decimal(src, &dest);
  ck_assert_uint_eq(dest.bits[0], 31213231);
  ck_assert_uint_eq(dest.bits[1], 0);
  ck_assert_uint_eq(dest.bits[2], 0);
  ck_assert_uint_eq(dest.bits[3], 2147483648);
  ck_assert_int_eq(return_code, 0);
}
END_TEST

START_TEST(int_to_decimal_5) {
  int src = -123456;
  s21_decimal dest;
  int return_code = s21_from_int_to_decimal(src, &dest);
  ck_assert_uint_eq(dest.bits[0], 123456);
  ck_assert_uint_eq(dest.bits[1], 0);
  ck_assert_uint_eq(dest.bits[2], 0);
  ck_assert_uint_eq(dest.bits[3], 2147483648);
  ck_assert_int_eq(return_code, 0);
}
END_TEST

START_TEST(int_to_decimal_6) {
  int src = 3;
  s21_decimal dest;
  int return_code = s21_from_int_to_decimal(src, &dest);
  ck_assert_uint_eq(dest.bits[0], 3);
  ck_assert_uint_eq(dest.bits[1], 0);
  ck_assert_uint_eq(dest.bits[2], 0);
  ck_assert_uint_eq(dest.bits[3], 0);
  ck_assert_int_eq(return_code, 0);
}
END_TEST

START_TEST(int_to_decimal_7) {
  int src = -718281828;
  s21_decimal dest;
  int return_code = s21_from_int_to_decimal(src, &dest);
  ck_assert_uint_eq(dest.bits[0], 718281828);
  ck_assert_uint_eq(dest.bits[1], 0);
  ck_assert_uint_eq(dest.bits[2], 0);
  ck_assert_uint_eq(dest.bits[3], 2147483648);
  ck_assert_int_eq(return_code, 0);
}
END_TEST

START_TEST(int_to_decimal_8) {
  int src = 0;
  s21_decimal dest;
  int return_code = s21_from_int_to_decimal(src, &dest);
  ck_assert_uint_eq(dest.bits[0], 0);
  ck_assert_uint_eq(dest.bits[1], 0);
  ck_assert_uint_eq(dest.bits[2], 0);
  ck_assert_uint_eq(dest.bits[3], 0);
  ck_assert_int_eq(return_code, 0);
}
END_TEST

START_TEST(int_to_decimal_9) {
  int src = -16524;
  s21_decimal dest;
  int return_code = s21_from_int_to_decimal(src, &dest);
  ck_assert_uint_eq(dest.bits[0], 16524);
  ck_assert_uint_eq(dest.bits[1], 0);
  ck_assert_uint_eq(dest.bits[2], 0);
  ck_assert_uint_eq(dest.bits[3], 2147483648);
  ck_assert_int_eq(return_code, 0);
}
END_TEST

Suite *s21_test_int_to_decimal() {
  Suite *test_set = suite_create("s21_int_to_decimal");
  TCase *test_group = tcase_create("s21_int_to_decimal_test_group");

  tcase_add_test(test_group, int_to_decimal_1);
  tcase_add_test(test_group, int_to_decimal_2);
  tcase_add_test(test_group, int_to_decimal_3);
  tcase_add_test(test_group, int_to_decimal_4);
  tcase_add_test(test_group, int_to_decimal_5);
  tcase_add_test(test_group, int_to_decimal_6);
  tcase_add_test(test_group, int_to_decimal_7);
  tcase_add_test(test_group, int_to_decimal_8);
  tcase_add_test(test_group, int_to_decimal_9);

  suite_add_tcase(test_set, test_group);

  return test_set;
}