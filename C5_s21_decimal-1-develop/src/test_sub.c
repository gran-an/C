#include "s21_decimal_tests.h"

START_TEST(sub_1) {
  s21_decimal a = init(0, 0, 0, 0, 954);
  s21_decimal b = init(0, 0, 0, 0, 954);
  s21_decimal res;
  int ret_code = s21_sub(a, b, &res);
  ck_assert_uint_eq(res.bits[0], 0);
  ck_assert_uint_eq(res.bits[1], 0);
  ck_assert_uint_eq(res.bits[2], 0);
  ck_assert_uint_eq(res.bits[3], 0);
  ck_assert_int_eq(ret_code, 0);
}
END_TEST

START_TEST(sub_2) {
  s21_decimal a = init(0, 0, 123, 456, 789);
  s21_decimal b = init(0, 0, 987, 654, 321);
  s21_decimal res;
  int ret_code = s21_sub(a, b, &res);
  ck_assert_uint_eq(res.bits[0], 4294966828);
  ck_assert_uint_eq(res.bits[1], 197);
  ck_assert_uint_eq(res.bits[2], 864);
  ck_assert_uint_eq(res.bits[3], 2147483648);
  ck_assert_int_eq(ret_code, 0);
}
END_TEST

START_TEST(sub_3) {
  s21_decimal a = init(0, 1, 123456, 123456, 123456);
  s21_decimal b = init(0, 4, 987654, 987654, 987654);
  s21_decimal res;
  int ret_code = s21_sub(a, b, &res);
  ck_assert_uint_eq(res.bits[0], 122468346);
  ck_assert_uint_eq(res.bits[1], 122468346);
  ck_assert_uint_eq(res.bits[2], 122468346);
  ck_assert_uint_eq(res.bits[3], 262144);
  ck_assert_int_eq(ret_code, 0);
}
END_TEST

START_TEST(sub_4) {
  s21_decimal a = init(1, 1, 123456, 123456, 123456);
  s21_decimal b = init(0, 4, 987654, 987654, 987654);
  s21_decimal res;
  int ret_code = s21_sub(a, b, &res);
  ck_assert_uint_eq(res.bits[0], 124443654);
  ck_assert_uint_eq(res.bits[1], 124443654);
  ck_assert_uint_eq(res.bits[2], 124443654);
  ck_assert_uint_eq(res.bits[3], 2147745792);
  ck_assert_int_eq(ret_code, 0);
}
END_TEST

START_TEST(sub_5) {
  s21_decimal a = init(0, 4, 123456, 123456, 123456);
  s21_decimal b = init(1, 1, 987654, 987654, 987654);
  s21_decimal res;
  int ret_code = s21_sub(a, b, &res);
  ck_assert_uint_eq(res.bits[0], 987777456);
  ck_assert_uint_eq(res.bits[1], 987777456);
  ck_assert_uint_eq(res.bits[2], 987777456);
  ck_assert_uint_eq(res.bits[3], 262144);
  ck_assert_int_eq(ret_code, 0);
}
END_TEST

START_TEST(sub_6) {
  s21_decimal a = S21_DECIMAL_PI;
  s21_decimal b = S21_DECIMAL_PI;
  s21_decimal res;
  int ret_code = s21_sub(a, b, &res);
  ck_assert_uint_eq(res.bits[0], 0);
  ck_assert_uint_eq(res.bits[1], 0);
  ck_assert_uint_eq(res.bits[2], 0);
  ck_assert_uint_eq(res.bits[3], 0);
  ck_assert_int_eq(ret_code, 0);
}
END_TEST

START_TEST(sub_7) {
  s21_decimal a = init(0, 11, 242776514, 74774519, 394946377);
  s21_decimal b = init(0, 14, 1894517808, 1765076176, 33985678);
  s21_decimal res;
  int ret_code = s21_sub(a, b, &res);
  ck_assert_uint_eq(res.bits[0], 2059338303);
  ck_assert_uint_eq(res.bits[1], 386497045);
  ck_assert_uint_eq(res.bits[2], 2408819962);
  ck_assert_uint_eq(res.bits[3], 786432);
  ck_assert_int_eq(ret_code, 0);
}
END_TEST

START_TEST(sub_8) {
  s21_decimal a = init(0, 1, 372689380, 207666326, 25559965);
  s21_decimal b = init(0, 28, 209900245, 577952791, 221887505);
  s21_decimal res;
  int ret_code = s21_sub(a, b, &res);
  ck_assert_uint_eq(res.bits[0], 255599611);
  ck_assert_uint_eq(res.bits[1], 2076663260);
  ck_assert_uint_eq(res.bits[2], 3726893800);
  ck_assert_uint_eq(res.bits[3], 131072);
  ck_assert_int_eq(ret_code, 0);
}
END_TEST

START_TEST(sub_9) {
  s21_decimal a = init(0, 0, 999999999, 999999999, 999999999);
  s21_decimal b = init(1, 0, 999999999, 999999999, 999999999);
  s21_decimal res;
  int ret_code = s21_sub(a, b, &res);
  ck_assert_uint_eq(res.bits[0], 1999999998);
  ck_assert_uint_eq(res.bits[1], 1999999998);
  ck_assert_uint_eq(res.bits[2], 1999999998);
  ck_assert_uint_eq(res.bits[3], 0);
  ck_assert_int_eq(ret_code, 0);
}
END_TEST

Suite *s21_test_sub() {
  Suite *test_set = suite_create("s21_sub");
  TCase *test_group = tcase_create("s21_sub_test_group");

  tcase_add_test(test_group, sub_1);
  tcase_add_test(test_group, sub_2);
  tcase_add_test(test_group, sub_3);
  tcase_add_test(test_group, sub_4);
  tcase_add_test(test_group, sub_5);
  tcase_add_test(test_group, sub_6);
  tcase_add_test(test_group, sub_7);
  tcase_add_test(test_group, sub_8);
  tcase_add_test(test_group, sub_9);

  suite_add_tcase(test_set, test_group);

  return test_set;
}