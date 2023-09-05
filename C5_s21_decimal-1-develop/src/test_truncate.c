#include "s21_decimal_tests.h"

START_TEST(truncate_1) {
  s21_decimal src = init(0, 2, 0, 0, 954);
  s21_decimal dest;
  int return_code = s21_truncate(src, &dest);
  ck_assert_uint_eq(dest.bits[0], 9);
  ck_assert_uint_eq(dest.bits[1], 0);
  ck_assert_uint_eq(dest.bits[2], 0);
  ck_assert_uint_eq(dest.bits[3], 0);
  ck_assert_int_eq(return_code, 0);
}
END_TEST

START_TEST(truncate_2) {
  s21_decimal src = init(1, 4, 0, 0, 100054);
  s21_decimal dest;
  int return_code = s21_truncate(src, &dest);
  ck_assert_uint_eq(dest.bits[0], 10);
  ck_assert_uint_eq(dest.bits[1], 0);
  ck_assert_uint_eq(dest.bits[2], 0);
  ck_assert_uint_eq(dest.bits[3], 2147483648);
  ck_assert_int_eq(return_code, 0);
}
END_TEST

START_TEST(truncate_3) {
  s21_decimal src = init(0, 5, 0, 1000024, 1000024);
  s21_decimal dest;
  int return_code = s21_truncate(src, &dest);
  ck_assert_uint_eq(dest.bits[0], 1030802);
  ck_assert_uint_eq(dest.bits[1], 10);
  ck_assert_uint_eq(dest.bits[2], 0);
  ck_assert_uint_eq(dest.bits[3], 0);
  ck_assert_int_eq(return_code, 0);
}
END_TEST

START_TEST(truncate_4) {
  s21_decimal src = init(1, 5, 1000000, 2000099, 1000099);
  s21_decimal dest;
  int return_code = s21_truncate(src, &dest);
  ck_assert_uint_eq(dest.bits[0], 4252027);
  ck_assert_uint_eq(dest.bits[1], 20);
  ck_assert_uint_eq(dest.bits[2], 10);
  ck_assert_uint_eq(dest.bits[3], 2147483648);
  ck_assert_int_eq(return_code, 0);
}
END_TEST

START_TEST(truncate_5) {
  s21_decimal src = init(1, 1, 123, 123, 123);
  s21_decimal dest;
  int return_code = s21_truncate(src, &dest);
  ck_assert_uint_eq(dest.bits[0], 429496741);
  ck_assert_uint_eq(dest.bits[1], 1288490201);
  ck_assert_uint_eq(dest.bits[2], 12);
  ck_assert_uint_eq(dest.bits[3], 2147483648);
  ck_assert_int_eq(return_code, 0);
}
END_TEST

START_TEST(truncate_6) {
  s21_decimal src = init(0, 3, 0, 0, 123456);
  s21_decimal dest;
  int return_code = s21_truncate(src, &dest);
  ck_assert_uint_eq(dest.bits[0], 123);
  ck_assert_uint_eq(dest.bits[1], 0);
  ck_assert_uint_eq(dest.bits[2], 0);
  ck_assert_uint_eq(dest.bits[3], 0);
  ck_assert_int_eq(return_code, 0);
}
END_TEST

START_TEST(truncate_7) {
  s21_decimal src = init(0, 28, 123456, 123456, 123456);
  s21_decimal dest;
  int return_code = s21_truncate(src, &dest);
  ck_assert_uint_eq(dest.bits[0], 0);
  ck_assert_uint_eq(dest.bits[1], 0);
  ck_assert_uint_eq(dest.bits[2], 0);
  ck_assert_uint_eq(dest.bits[3], 0);
  ck_assert_int_eq(return_code, 0);
}
END_TEST

START_TEST(truncate_8) {
  s21_decimal src = init(1, 2, 0, 0, 954);
  s21_decimal dest;
  int return_code = s21_truncate(src, &dest);
  ck_assert_uint_eq(dest.bits[0], 9);
  ck_assert_uint_eq(dest.bits[1], 0);
  ck_assert_uint_eq(dest.bits[2], 0);
  ck_assert_uint_eq(dest.bits[3], 2147483648);
  ck_assert_int_eq(return_code, 0);
}
END_TEST

START_TEST(truncate_9) {
  s21_decimal src = init(1, 2, 429496729, 429496729, 429496729);
  s21_decimal dest;
  int return_code = s21_truncate(src, &dest);
  ck_assert_uint_eq(dest.bits[0], 562640715);
  ck_assert_uint_eq(dest.bits[1], 1249835483);
  ck_assert_uint_eq(dest.bits[2], 4294967);
  ck_assert_uint_eq(dest.bits[3], 2147483648);
  ck_assert_int_eq(return_code, 0);
}
END_TEST

START_TEST(truncate_10) {
  s21_decimal src = init(1, 30, 1, 1, 1);
  s21_decimal dest = {{1}};
  int return_code = s21_truncate(src, &dest);
  ck_assert_int_eq(return_code, 1);
}
END_TEST

START_TEST(truncate_11) {
  s21_decimal src = {{0, 0, 0, 1000}};
  s21_decimal dest = {{1}};
  int return_code = s21_truncate(src, &dest);
  ck_assert_int_eq(return_code, 1);
}
END_TEST

Suite *s21_test_truncate() {
  Suite *test_set = suite_create("s21_truncate");
  TCase *test_group = tcase_create("s21_truncate_test_group");

  tcase_add_test(test_group, truncate_1);
  tcase_add_test(test_group, truncate_2);
  tcase_add_test(test_group, truncate_3);
  tcase_add_test(test_group, truncate_4);
  tcase_add_test(test_group, truncate_5);
  tcase_add_test(test_group, truncate_6);
  tcase_add_test(test_group, truncate_7);
  tcase_add_test(test_group, truncate_8);
  tcase_add_test(test_group, truncate_9);
  tcase_add_test(test_group, truncate_10);
  tcase_add_test(test_group, truncate_11);

  suite_add_tcase(test_set, test_group);

  return test_set;
}