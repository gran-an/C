#include "s21_decimal_tests.h"

START_TEST(mul_1) {
  s21_decimal a = init(0, 0, 0, 0, 954);
  s21_decimal b = init(0, 0, 0, 0, 954);
  s21_decimal res;
  int ret_code = s21_mul(a, b, &res);
  ck_assert_uint_eq(res.bits[0], 910116);
  ck_assert_uint_eq(res.bits[1], 0);
  ck_assert_uint_eq(res.bits[2], 0);
  ck_assert_uint_eq(res.bits[3], 0);
  ck_assert_int_eq(ret_code, 0);
}
END_TEST

START_TEST(mul_2) {
  s21_decimal a = init(0, 0, 123, 456, 789);
  s21_decimal b = init(0, 0, 987, 654, 321);
  s21_decimal res = {{1}};
  int ret_code = s21_mul(a, b, &res);
  ck_assert_int_eq(ret_code, 1);
}
END_TEST

START_TEST(mul_3) {
  s21_decimal a = init(0, 1, 0, 123456, 123456);
  s21_decimal b = init(0, 4, 0, 987654, 987654);
  s21_decimal res;
  int ret_code = s21_mul(a, b, &res);
  ck_assert_uint_eq(res.bits[0], 3452701116);
  ck_assert_uint_eq(res.bits[1], 3469428395);
  ck_assert_uint_eq(res.bits[2], 1219318122);
  ck_assert_uint_eq(res.bits[3], 196608);
  ck_assert_int_eq(ret_code, 0);
}
END_TEST

START_TEST(mul_4) {
  s21_decimal a = init(1, 15, 123456, 123456, 123456);
  s21_decimal b = init(0, 10, 987654, 987654, 987654);
  s21_decimal res;
  int ret_code = s21_mul(a, b, &res);
  ck_assert_uint_eq(res.bits[0], 2604039317);
  ck_assert_uint_eq(res.bits[1], 2521679043);
  ck_assert_uint_eq(res.bits[2], 2249244935);
  ck_assert_uint_eq(res.bits[3], 2147745792);
  ck_assert_int_eq(ret_code, 0);
}
END_TEST

START_TEST(mul_5) {
  s21_decimal a = init(0, 20, 123456, 123456, 123456);
  s21_decimal b = init(1, 28, 987654, 987654, 987654);
  s21_decimal res;
  int ret_code = s21_mul(a, b, &res);
  ck_assert_uint_eq(res.bits[0], 2604039317);
  ck_assert_uint_eq(res.bits[1], 2521679043);
  ck_assert_uint_eq(res.bits[2], 2249244935);
  ck_assert_uint_eq(res.bits[3], 2149253120);
  ck_assert_int_eq(ret_code, 0);
}
END_TEST

START_TEST(mul_6) {
  s21_decimal a = S21_DECIMAL_PI;
  s21_decimal b = S21_DECIMAL_PI;
  s21_decimal res;
  int ret_code = s21_mul(a, b, &res);
  ck_assert_uint_eq(res.bits[0], 3747862135);
  ck_assert_uint_eq(res.bits[1], 2841889338);
  ck_assert_uint_eq(res.bits[2], 535032326);
  ck_assert_uint_eq(res.bits[3], 1769472);
  ck_assert_int_eq(ret_code, 0);
}
END_TEST

START_TEST(mul_7) {
  s21_decimal a = init(0, 25, 242776514, 74774519, 394946377);
  s21_decimal b = init(0, 20, 1894517808, 1765076176, 33985678);
  s21_decimal res;
  int ret_code = s21_mul(a, b, &res);
  ck_assert_uint_eq(res.bits[0], 3170667597);
  ck_assert_uint_eq(res.bits[1], 2091889893);
  ck_assert_uint_eq(res.bits[2], 848447717);
  ck_assert_uint_eq(res.bits[3], 1114112);
  ck_assert_int_eq(ret_code, 0);
}
END_TEST

START_TEST(mul_8) {
  s21_decimal a = init(0, 1, 372689380, 207666326, 25559965);
  s21_decimal b = init(0, 28, 209900245, 577952791, 221887505);
  s21_decimal res;
  int ret_code = s21_mul(a, b, &res);
  ck_assert_uint_eq(res.bits[0], 3763701075);
  ck_assert_uint_eq(res.bits[1], 1681131751);
  ck_assert_uint_eq(res.bits[2], 1443044373);
  ck_assert_uint_eq(res.bits[3], 131072);
  ck_assert_int_eq(ret_code, 0);
}
END_TEST

START_TEST(mul_9) {
  s21_decimal a = init(0, 1, 0, 0, 512);
  s21_decimal b = init(0, 28, 0, 0, 256);
  s21_decimal res;
  int ret_code = s21_mul(a, b, &res);
  ck_assert_uint_eq(res.bits[0], 13107);
  ck_assert_uint_eq(res.bits[1], 0);
  ck_assert_uint_eq(res.bits[2], 0);
  ck_assert_uint_eq(res.bits[3], 1835008);
  ck_assert_int_eq(ret_code, 0);
}
END_TEST

Suite *s21_test_mul() {
  Suite *test_set = suite_create("s21_mul");
  TCase *test_group = tcase_create("s21_mul_test_group");

  tcase_add_test(test_group, mul_1);
  tcase_add_test(test_group, mul_2);
  tcase_add_test(test_group, mul_3);
  tcase_add_test(test_group, mul_4);
  tcase_add_test(test_group, mul_5);
  tcase_add_test(test_group, mul_6);
  tcase_add_test(test_group, mul_7);
  tcase_add_test(test_group, mul_8);
  tcase_add_test(test_group, mul_9);

  suite_add_tcase(test_set, test_group);

  return test_set;
}
