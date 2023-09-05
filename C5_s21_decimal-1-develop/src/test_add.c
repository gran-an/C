#include "s21_decimal_tests.h"

START_TEST(add_1) {
  s21_decimal a = init(0, 0, 0, 0, 954);
  s21_decimal b = init(0, 0, 0, 0, 954);
  s21_decimal res;
  int ret_code = s21_add(a, b, &res);
  ck_assert_uint_eq(res.bits[0], 1908);
  ck_assert_uint_eq(res.bits[1], 0);
  ck_assert_uint_eq(res.bits[2], 0);
  ck_assert_uint_eq(res.bits[3], 0);
  ck_assert_int_eq(ret_code, 0);
}
END_TEST

START_TEST(add_2) {
  s21_decimal a = init(0, 0, 123, 456, 789);
  s21_decimal b = init(0, 0, 987, 654, 321);
  s21_decimal res;
  int ret_code = s21_add(a, b, &res);
  ck_assert_uint_eq(res.bits[0], 1110);
  ck_assert_uint_eq(res.bits[1], 1110);
  ck_assert_uint_eq(res.bits[2], 1110);
  ck_assert_uint_eq(res.bits[3], 0);
  ck_assert_int_eq(ret_code, 0);
}
END_TEST

START_TEST(add_3) {
  s21_decimal a = init(0, 1, 123456, 123456, 123456);
  s21_decimal b = init(0, 4, 987654, 987654, 987654);
  s21_decimal res;
  int ret_code = s21_add(a, b, &res);
  ck_assert_uint_eq(res.bits[0], 124443654);
  ck_assert_uint_eq(res.bits[1], 124443654);
  ck_assert_uint_eq(res.bits[2], 124443654);
  ck_assert_uint_eq(res.bits[3], 262144);
  ck_assert_int_eq(ret_code, 0);
}
END_TEST

START_TEST(add_4) {
  s21_decimal a = init(1, 1, 123456, 123456, 123456);
  s21_decimal b = init(0, 4, 987654, 987654, 987654);
  s21_decimal res;
  int ret_code = s21_add(a, b, &res);
  ck_assert_uint_eq(res.bits[0], 122468346);
  ck_assert_uint_eq(res.bits[1], 122468346);
  ck_assert_uint_eq(res.bits[2], 122468346);
  ck_assert_uint_eq(res.bits[3], 2147745792);
  ck_assert_int_eq(ret_code, 0);
}
END_TEST

START_TEST(add_5) {
  s21_decimal a = init(0, 4, 123456, 123456, 123456);
  s21_decimal b = init(1, 1, 987654, 987654, 987654);
  s21_decimal res;
  int ret_code = s21_add(a, b, &res);
  ck_assert_uint_eq(res.bits[0], 987530544);
  ck_assert_uint_eq(res.bits[1], 987530544);
  ck_assert_uint_eq(res.bits[2], 987530544);
  ck_assert_uint_eq(res.bits[3], 2147745792);
  ck_assert_int_eq(ret_code, 0);
}
END_TEST

START_TEST(add_6) {
  s21_decimal a = S21_DECIMAL_PI;
  s21_decimal b = S21_DECIMAL_PI;
  s21_decimal res;
  int ret_code = s21_add(a, b, &res);
  ck_assert_uint_eq(res.bits[0], 2204941904);
  ck_assert_uint_eq(res.bits[1], 371749130);
  ck_assert_uint_eq(res.bits[2], 3406121580);
  ck_assert_uint_eq(res.bits[3], 1835008);
  ck_assert_int_eq(ret_code, 0);
}
END_TEST

START_TEST(add_7) {
  s21_decimal a = init(0, 11, 242776514, 74774519, 394946377);
  s21_decimal b = init(0, 14, 1894517808, 1765076176, 33985678);
  s21_decimal res;
  int ret_code = s21_add(a, b, &res);
  ck_assert_uint_eq(res.bits[0], 1544621941);
  ck_assert_uint_eq(res.bits[1], 1108993336);
  ck_assert_uint_eq(res.bits[2], 2446710318);
  ck_assert_uint_eq(res.bits[3], 786432);
  ck_assert_int_eq(ret_code, 0);
}
END_TEST

START_TEST(add_8) {
  s21_decimal a = init(0, 1, 372689380, 207666326, 25559965);
  s21_decimal b = init(0, 28, 209900245, 577952791, 221887505);
  s21_decimal res;
  int ret_code = s21_add(a, b, &res);
  ck_assert_uint_eq(res.bits[0], 255599689);
  ck_assert_uint_eq(res.bits[1], 2076663260);
  ck_assert_uint_eq(res.bits[2], 3726893800);
  ck_assert_uint_eq(res.bits[3], 131072);
  ck_assert_int_eq(ret_code, 0);
}
END_TEST

START_TEST(add_9) {
  s21_decimal a = init(0, 0, 999999999, 999999999, 999999999);
  s21_decimal b = init(0, 0, 999999999, 999999999, 999999999);
  s21_decimal res;
  int ret_code = s21_add(a, b, &res);
  ck_assert_uint_eq(res.bits[0], 1999999998);
  ck_assert_uint_eq(res.bits[1], 1999999998);
  ck_assert_uint_eq(res.bits[2], 1999999998);
  ck_assert_uint_eq(res.bits[3], 0);
  ck_assert_int_eq(ret_code, 0);
}
END_TEST

START_TEST(add_10) {
  s21_decimal a = init(0, 1, 0xFFFFFFFF, 0, 0);
  s21_decimal b = init(0, 1, 0xFFFFFFFF, 0, 0);
  s21_decimal res;
  int ret_code = s21_add(a, b, &res);
  ck_assert_uint_eq(res.bits[0], 0);
  ck_assert_uint_eq(res.bits[1], 0);
  ck_assert_uint_eq(res.bits[2], 4294967294);
  ck_assert_uint_eq(res.bits[3], 65536);
  ck_assert_int_eq(ret_code, 1);
}
END_TEST

Suite *s21_test_add() {
  Suite *test_set = suite_create("s21_add");
  TCase *test_group = tcase_create("s21_add_test_group");

  tcase_add_test(test_group, add_1);
  tcase_add_test(test_group, add_2);
  tcase_add_test(test_group, add_3);
  tcase_add_test(test_group, add_4);
  tcase_add_test(test_group, add_5);
  tcase_add_test(test_group, add_6);
  tcase_add_test(test_group, add_7);
  tcase_add_test(test_group, add_8);
  tcase_add_test(test_group, add_9);
  tcase_add_test(test_group, add_10);

  suite_add_tcase(test_set, test_group);

  return test_set;
}