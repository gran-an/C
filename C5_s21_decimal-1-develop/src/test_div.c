#include "s21_decimal_tests.h"

START_TEST(div_1) {
  s21_decimal a = init(0, 0, 0, 0, 954);
  s21_decimal b = init(0, 0, 0, 0, 954);
  s21_decimal res;
  int ret_code = s21_div(a, b, &res);
  ck_assert_uint_eq(res.bits[0], 1);
  ck_assert_uint_eq(res.bits[1], 0);
  ck_assert_uint_eq(res.bits[2], 0);
  ck_assert_uint_eq(res.bits[3], 0);
  ck_assert_int_eq(ret_code, 0);
}
END_TEST

START_TEST(div_2) {
  s21_decimal a = init(0, 0, 123, 456, 789);
  s21_decimal b = init(0, 0, 987, 654, 321);
  s21_decimal res = {{1}};
  int ret_code = s21_div(a, b, &res);
  ck_assert_uint_eq(res.bits[0], 2158280007);
  ck_assert_uint_eq(res.bits[1], 1588863214);
  ck_assert_uint_eq(res.bits[2], 67556670);
  ck_assert_uint_eq(res.bits[3], 1835008);
  ck_assert_int_eq(ret_code, 0);
}
END_TEST

START_TEST(div_3) {
  s21_decimal a = init(0, 1, 123456, 123456, 123456);
  s21_decimal b = init(0, 4, 987654, 987654, 987654);
  s21_decimal res;
  int ret_code = s21_div(a, b, &res);
  ck_assert_uint_eq(res.bits[0], 901371980);
  ck_assert_uint_eq(res.bits[1], 953391370);
  ck_assert_uint_eq(res.bits[2], 677622241);
  ck_assert_uint_eq(res.bits[3], 1703936);
  ck_assert_int_eq(ret_code, 0);
}
END_TEST

START_TEST(div_4) {
  s21_decimal a = init(1, 15, 123456, 123456, 123456);
  s21_decimal b = init(0, 10, 987654, 987654, 987654);
  s21_decimal res;
  int ret_code = s21_div(a, b, &res);
  ck_assert_uint_eq(res.bits[0], 2670207839);
  ck_assert_uint_eq(res.bits[1], 2672505698);
  ck_assert_uint_eq(res.bits[2], 677);
  ck_assert_uint_eq(res.bits[3], 2149318656);
  ck_assert_int_eq(ret_code, 0);
}
END_TEST

START_TEST(div_5) {
  s21_decimal a = init(0, 20, 123456, 123456, 123456);
  s21_decimal b = init(1, 28, 987654, 987654, 987654);
  s21_decimal res;
  int ret_code = s21_div(a, b, &res);
  ck_assert_uint_eq(res.bits[0], 901371980);
  ck_assert_uint_eq(res.bits[1], 953391370);
  ck_assert_uint_eq(res.bits[2], 677622241);
  ck_assert_uint_eq(res.bits[3], 2148859904);
  ck_assert_int_eq(ret_code, 0);
}
END_TEST

START_TEST(div_6) {
  s21_decimal a = S21_DECIMAL_PI;
  s21_decimal b = init(0, 8, 585566669, 2065135430, 909324176);
  s21_decimal res;
  int ret_code = s21_div(a, b, &res);
  ck_assert_uint_eq(res.bits[0], 290839776);
  ck_assert_uint_eq(res.bits[1], 0);
  ck_assert_uint_eq(res.bits[2], 0);
  ck_assert_uint_eq(res.bits[3], 1835008);
  ck_assert_int_eq(ret_code, 0);
}
END_TEST

START_TEST(div_7) {
  s21_decimal a = init(0, 25, 242776514, 74774519, 394946377);
  s21_decimal b = init(0, 20, 1894517808, 1765076176, 33985678);
  s21_decimal res;
  int ret_code = s21_div(a, b, &res);
  ck_assert_uint_eq(res.bits[0], 878124734);
  ck_assert_uint_eq(res.bits[1], 2944355682);
  ck_assert_uint_eq(res.bits[2], 694);
  ck_assert_uint_eq(res.bits[3], 1835008);
  ck_assert_int_eq(ret_code, 0);
}
END_TEST

START_TEST(div_8) {
  s21_decimal a = init(0, 1, 372689380, 207666326, 25559965);
  s21_decimal b = init(0, 28, 209900245, 577952791, 221887505);
  s21_decimal res;
  int ret_code = s21_div(a, b, &res);
  ck_assert_uint_eq(res.bits[0], 234919675);
  ck_assert_uint_eq(res.bits[1], 3528368113);
  ck_assert_uint_eq(res.bits[2], 962530165);
  ck_assert_uint_eq(res.bits[3], 65536);
  ck_assert_int_eq(ret_code, 0);
}
END_TEST

START_TEST(div_9) {
  s21_decimal a = init(0, 0, INT32_MAX, INT32_MAX, INT32_MAX);
  s21_decimal b = init(0, 1, 0, 0, 1);
  s21_decimal res;
  int ret_code = s21_div(a, b, &res);
  ck_assert_int_eq(ret_code, 1);
}
END_TEST

Suite *s21_test_div() {
  Suite *test_set = suite_create("s21_div");
  TCase *test_group = tcase_create("s21_div_test_group");

  tcase_add_test(test_group, div_1);
  tcase_add_test(test_group, div_2);
  tcase_add_test(test_group, div_3);
  tcase_add_test(test_group, div_4);
  tcase_add_test(test_group, div_5);
  tcase_add_test(test_group, div_6);
  tcase_add_test(test_group, div_7);
  tcase_add_test(test_group, div_8);
  tcase_add_test(test_group, div_9);

  suite_add_tcase(test_set, test_group);

  return test_set;
}