#include "s21_math.h"

#include <check.h>
#include <math.h>
#include <stdlib.h>

/*S21_ABS_TEST*/

START_TEST(s21_abs_test_1) { ck_assert_int_eq(s21_abs(-3), abs(-3)); }
END_TEST

START_TEST(s21_abs_test_2) { ck_assert_int_eq(s21_abs(0), abs(0)); }
END_TEST

START_TEST(s21_abs_test_3) { ck_assert_int_eq(s21_abs(3), abs(3)); }
END_TEST

START_TEST(s21_abs_test_4) {
  ck_assert_int_eq(s21_abs((int)NAN), abs((int)NAN));
}
END_TEST

START_TEST(s21_abs_test_5) {
  ck_assert_int_eq(s21_abs((int)-INFINITY), abs((int)-INFINITY));
}
END_TEST

START_TEST(s21_abs_test_6) {
  ck_assert_int_eq(s21_abs((int)INFINITY), abs((int)INFINITY));
}
END_TEST

Suite *abs_suite(void) {
  Suite *s;
  TCase *tc_values;
  s = suite_create("abs(x)");

  tc_values = tcase_create("values");
  tcase_add_test(tc_values, s21_abs_test_1);
  tcase_add_test(tc_values, s21_abs_test_2);
  tcase_add_test(tc_values, s21_abs_test_3);
  tcase_add_test(tc_values, s21_abs_test_4);
  tcase_add_test(tc_values, s21_abs_test_5);
  tcase_add_test(tc_values, s21_abs_test_6);
  suite_add_tcase(s, tc_values);
  return s;
}

/*S21_ACOS_TEST*/

START_TEST(s21_acos_test_1) { ck_assert_double_eq(s21_acos(0), acos(0)); }
END_TEST

START_TEST(s21_acos_test_2) {
  ck_assert_double_nan(s21_acos(3));
  ck_assert_double_nan(acos(3));
}
END_TEST

START_TEST(s21_acos_test_3) {
  ck_assert_double_nan(s21_acos(-3));
  ck_assert_double_nan(acos(-3));
}
END_TEST

START_TEST(s21_acos_test_4) {
  ck_assert_double_nan(s21_acos(NAN));
  ck_assert_double_nan(acos(NAN));
}
END_TEST

START_TEST(s21_acos_test_5) {
  ck_assert_double_nan(s21_acos(-INFINITY));
  ck_assert_double_nan(acos(-INFINITY));
}
END_TEST

START_TEST(s21_acos_test_6) {
  ck_assert_double_nan(s21_acos(INFINITY));
  ck_assert_double_nan(acos(INFINITY));
}
END_TEST

START_TEST(s21_acos_test_7) { ck_assert_double_eq(s21_acos(-1), acos(-1)); }
END_TEST

START_TEST(s21_acos_test_8) { ck_assert_double_eq(s21_acos(1), acos(1)); }
END_TEST

START_TEST(s21_acos_test_9) {
  ck_assert_double_eq_tol(s21_acos(0.2), acos(0.2), 0.000001);
}
END_TEST

START_TEST(s21_acos_test_10) {
  ck_assert_double_eq_tol(s21_acos(-0.2), acos(-0.2), 0.000001);
}
END_TEST

Suite *acos_suite(void) {
  Suite *s;
  TCase *tc_values;
  s = suite_create("acos(x)");

  tc_values = tcase_create("values");
  tcase_add_test(tc_values, s21_acos_test_1);
  tcase_add_test(tc_values, s21_acos_test_2);
  tcase_add_test(tc_values, s21_acos_test_3);
  tcase_add_test(tc_values, s21_acos_test_4);
  tcase_add_test(tc_values, s21_acos_test_5);
  tcase_add_test(tc_values, s21_acos_test_6);
  tcase_add_test(tc_values, s21_acos_test_7);
  tcase_add_test(tc_values, s21_acos_test_8);
  tcase_add_test(tc_values, s21_acos_test_9);
  tcase_add_test(tc_values, s21_acos_test_10);
  suite_add_tcase(s, tc_values);
  return s;
}

/*S21_ASIN_TEST*/

START_TEST(s21_asin_test_1) { ck_assert_double_eq(s21_asin(0), asin(0)); }
END_TEST

START_TEST(s21_asin_test_2) {
  ck_assert_double_nan(s21_asin(3));
  ck_assert_double_nan(asin(3));
}
END_TEST

START_TEST(s21_asin_test_3) {
  ck_assert_double_nan(s21_asin(-3));
  ck_assert_double_nan(asin(-3));
}
END_TEST

START_TEST(s21_asin_test_4) {
  ck_assert_double_nan(s21_asin(NAN));
  ck_assert_double_nan(asin(NAN));
}
END_TEST

START_TEST(s21_asin_test_5) {
  ck_assert_double_nan(s21_asin(-INFINITY));
  ck_assert_double_nan(asin(-INFINITY));
}
END_TEST

START_TEST(s21_asin_test_6) {
  ck_assert_double_nan(s21_asin(INFINITY));
  ck_assert_double_nan(asin(INFINITY));
}
END_TEST

START_TEST(s21_asin_test_7) { ck_assert_double_eq(s21_asin(-1), asin(-1)); }
END_TEST

START_TEST(s21_asin_test_8) { ck_assert_double_eq(s21_asin(1), asin(1)); }
END_TEST

START_TEST(s21_asin_test_9) {
  ck_assert_double_eq_tol(s21_asin(0.2), asin(0.2), 0.000001);
}
END_TEST

START_TEST(s21_asin_test_10) {
  ck_assert_double_eq_tol(s21_asin(-0.2), asin(-0.2), 0.000001);
}
END_TEST

Suite *asin_suite(void) {
  Suite *s;
  TCase *tc_values;
  s = suite_create("asin(x)");

  tc_values = tcase_create("values");
  tcase_add_test(tc_values, s21_asin_test_1);
  tcase_add_test(tc_values, s21_asin_test_2);
  tcase_add_test(tc_values, s21_asin_test_3);
  tcase_add_test(tc_values, s21_asin_test_4);
  tcase_add_test(tc_values, s21_asin_test_5);
  tcase_add_test(tc_values, s21_asin_test_6);
  tcase_add_test(tc_values, s21_asin_test_7);
  tcase_add_test(tc_values, s21_asin_test_8);
  tcase_add_test(tc_values, s21_asin_test_9);
  tcase_add_test(tc_values, s21_asin_test_10);
  suite_add_tcase(s, tc_values);
  return s;
}

/*S21_ATAN_TEST*/

START_TEST(s21_atan_test_1) { ck_assert_double_eq(s21_atan(0), atan(0)); }
END_TEST

START_TEST(s21_atan_test_2) {
  ck_assert_double_eq_tol(s21_atan(3), atan(3), 0.000001);
}
END_TEST

START_TEST(s21_atan_test_3) {
  ck_assert_double_eq_tol(s21_atan(-3), atan(-3), 0.000001);
}
END_TEST

START_TEST(s21_atan_test_4) {
  ck_assert_double_nan(s21_atan(NAN));
  ck_assert_double_nan(atan(NAN));
}
END_TEST

START_TEST(s21_atan_test_5) {
  ck_assert_double_eq_tol(s21_atan(-INFINITY), atan(-INFINITY), 0.000001);
}
END_TEST

START_TEST(s21_atan_test_6) {
  ck_assert_double_eq_tol(s21_atan(INFINITY), atan(INFINITY), 0.000001);
}
END_TEST

START_TEST(s21_atan_test_7) {
  ck_assert_double_eq_tol(s21_atan(-1), atan(-1), 0.000001);
}
END_TEST

START_TEST(s21_atan_test_8) {
  ck_assert_double_eq_tol(s21_atan(1), atan(1), 0.000001);
}
END_TEST

START_TEST(s21_atan_test_9) {
  ck_assert_double_eq_tol(s21_atan(0.2), atan(0.2), 0.000001);
}
END_TEST

START_TEST(s21_atan_test_10) {
  ck_assert_double_eq_tol(s21_atan(-0.2), atan(-0.2), 0.000001);
}
END_TEST

START_TEST(s21_atan_test_11) {
  long double arr[] = {14.96, -25.1235, 0.23464, 0, 1, -1};
  for (int i = 0; i < 6; i++)
    ck_assert_double_eq_tol(s21_atan(arr[i]), atan(arr[i]), 0.000001);
}
END_TEST

Suite *atan_suite(void) {
  Suite *s;
  TCase *tc_values;
  s = suite_create("atan(x)");

  tc_values = tcase_create("values");
  tcase_add_test(tc_values, s21_atan_test_1);
  tcase_add_test(tc_values, s21_atan_test_2);
  tcase_add_test(tc_values, s21_atan_test_3);
  tcase_add_test(tc_values, s21_atan_test_4);
  tcase_add_test(tc_values, s21_atan_test_5);
  tcase_add_test(tc_values, s21_atan_test_6);
  tcase_add_test(tc_values, s21_atan_test_7);
  tcase_add_test(tc_values, s21_atan_test_8);
  tcase_add_test(tc_values, s21_atan_test_9);
  tcase_add_test(tc_values, s21_atan_test_10);
  tcase_add_test(tc_values, s21_atan_test_11);
  suite_add_tcase(s, tc_values);
  return s;
}

/*S21_CEIL_TEST*/

START_TEST(s21_ceil_test_1) { ck_assert_double_eq(s21_ceil(0), ceil(0)); }
END_TEST

START_TEST(s21_ceil_test_2) {
  ck_assert_double_eq_tol(s21_ceil(3), ceil(3), 0.000001);
}
END_TEST

START_TEST(s21_ceil_test_3) {
  ck_assert_double_eq_tol(s21_ceil(-3), ceil(-3), 0.000001);
}
END_TEST

START_TEST(s21_ceil_test_4) {
  ck_assert_double_nan(s21_ceil(NAN));
  ck_assert_double_nan(ceil(NAN));
}
END_TEST

START_TEST(s21_ceil_test_5) {
  ck_assert_double_infinite(s21_ceil(-INFINITY));
  ck_assert_double_infinite(ceil(-INFINITY));
}
END_TEST

START_TEST(s21_ceil_test_6) {
  ck_assert_double_infinite(s21_ceil(INFINITY));
  ck_assert_double_infinite(ceil(INFINITY));
}
END_TEST

START_TEST(s21_ceil_test_7) {
  ck_assert_double_eq_tol(s21_ceil(-1), ceil(-1), 0.000001);
}
END_TEST

START_TEST(s21_ceil_test_8) {
  ck_assert_double_eq_tol(s21_ceil(1), ceil(1), 0.000001);
}
END_TEST

START_TEST(s21_ceil_test_9) {
  ck_assert_double_eq_tol(s21_ceil(0.2), ceil(0.2), 0.000001);
}
END_TEST

START_TEST(s21_ceil_test_10) {
  ck_assert_double_eq(s21_ceil(-0.2), ceil(-0.2));
}
END_TEST

START_TEST(s21_ceil_test_11) { ck_assert_double_eq(s21_ceil(0.7), ceil(0.7)); }
END_TEST

Suite *ceil_suite(void) {
  Suite *s;
  TCase *tc_values;
  s = suite_create("ceil(x)");

  tc_values = tcase_create("values");
  tcase_add_test(tc_values, s21_ceil_test_1);
  tcase_add_test(tc_values, s21_ceil_test_2);
  tcase_add_test(tc_values, s21_ceil_test_3);
  tcase_add_test(tc_values, s21_ceil_test_4);
  tcase_add_test(tc_values, s21_ceil_test_5);
  tcase_add_test(tc_values, s21_ceil_test_6);
  tcase_add_test(tc_values, s21_ceil_test_7);
  tcase_add_test(tc_values, s21_ceil_test_8);
  tcase_add_test(tc_values, s21_ceil_test_9);
  tcase_add_test(tc_values, s21_ceil_test_10);
  tcase_add_test(tc_values, s21_ceil_test_11);
  suite_add_tcase(s, tc_values);
  return s;
}

/*S21_COS_TEST*/

START_TEST(s21_cos_test_1) { ck_assert_double_eq(s21_cos(0), cos(0)); }
END_TEST

START_TEST(s21_cos_test_2) {
  ck_assert_double_eq_tol(s21_cos(3), cos(3), 0.000001);
}
END_TEST

START_TEST(s21_cos_test_3) {
  ck_assert_double_eq_tol(s21_cos(-3), cos(-3), 0.000001);
}
END_TEST

START_TEST(s21_cos_test_4) {
  ck_assert_double_nan(s21_cos(NAN));
  ck_assert_double_nan(cos(NAN));
}
END_TEST

START_TEST(s21_cos_test_5) {
  ck_assert_double_nan(s21_cos(-INFINITY));
  ck_assert_double_nan(cos(-INFINITY));
}
END_TEST

START_TEST(s21_cos_test_6) {
  ck_assert_double_nan(s21_cos(INFINITY));
  ck_assert_double_nan(cos(INFINITY));
}
END_TEST

START_TEST(s21_cos_test_7) {
  ck_assert_double_eq_tol(s21_cos(-1), cos(-1), 0.000001);
}
END_TEST

START_TEST(s21_cos_test_8) {
  ck_assert_double_eq_tol(s21_cos(1), cos(1), 0.000001);
}
END_TEST

START_TEST(s21_cos_test_9) {
  ck_assert_double_eq_tol(s21_cos(0.223), cos(0.223), 0.000001);
}
END_TEST

START_TEST(s21_cos_test_10) {
  ck_assert_double_eq_tol(s21_cos(-0.2), cos(-0.2), 0.000001);
}
END_TEST

START_TEST(s21_cos_test_11) {
  ck_assert_double_eq_tol(s21_cos(15.45), cos(15.45), 0.000001);
}
END_TEST

START_TEST(s21_cos_test_12) {
  ck_assert_double_eq_tol(s21_cos(-15.45), cos(-15.45), 0.000001);
}
END_TEST

START_TEST(s21_cos_test_13) {
  ck_assert_double_eq_tol(s21_cos(10234.23), cos(10234.23), 0.000001);
}
END_TEST

Suite *cos_suite(void) {
  Suite *s;
  TCase *tc_values;
  s = suite_create("cos(x)");

  tc_values = tcase_create("values");
  tcase_add_test(tc_values, s21_cos_test_1);
  tcase_add_test(tc_values, s21_cos_test_2);
  tcase_add_test(tc_values, s21_cos_test_3);
  tcase_add_test(tc_values, s21_cos_test_4);
  tcase_add_test(tc_values, s21_cos_test_5);
  tcase_add_test(tc_values, s21_cos_test_6);
  tcase_add_test(tc_values, s21_cos_test_7);
  tcase_add_test(tc_values, s21_cos_test_8);
  tcase_add_test(tc_values, s21_cos_test_9);
  tcase_add_test(tc_values, s21_cos_test_10);
  tcase_add_test(tc_values, s21_cos_test_11);
  tcase_add_test(tc_values, s21_cos_test_12);
  tcase_add_test(tc_values, s21_cos_test_13);
  suite_add_tcase(s, tc_values);
  return s;
}

/*S21_EXP_TEST*/

START_TEST(s21_exp_test_1) { ck_assert_double_eq(s21_exp(0), exp(0)); }
END_TEST

START_TEST(s21_exp_test_2) {
  ck_assert_double_eq_tol(s21_exp(2.23), exp(2.23), 0.000001);
}
END_TEST

START_TEST(s21_exp_test_3) {
  ck_assert_double_eq_tol(s21_exp(-3), exp(-3), 0.000001);
}
END_TEST

START_TEST(s21_exp_test_4) {
  ck_assert_double_nan(s21_exp(NAN));
  ck_assert_double_nan(exp(NAN));
}
END_TEST

START_TEST(s21_exp_test_5) {
  ck_assert_double_eq(s21_exp(-INFINITY), exp(-INFINITY));
}
END_TEST

START_TEST(s21_exp_test_6) {
  ck_assert_double_eq(s21_exp(INFINITY), exp(INFINITY));
}
END_TEST

START_TEST(s21_exp_test_7) {
  ck_assert_double_eq_tol(s21_exp(-1), exp(-1), 0.000001);
}
END_TEST

START_TEST(s21_exp_test_8) {
  ck_assert_double_eq_tol(s21_exp(1), exp(1), 0.000001);
}
END_TEST

START_TEST(s21_exp_test_9) {
  ck_assert_double_eq_tol(s21_exp(0.223), exp(0.223), 0.000001);
}
END_TEST

START_TEST(s21_exp_test_10) {
  ck_assert_double_eq_tol(s21_exp(-0.2), exp(-0.2), 0.000001);
}
END_TEST

START_TEST(s21_exp_test_11) {
  ck_assert_double_eq_tol(s21_exp(2.45), exp(2.45), 0.000001);
}
END_TEST

START_TEST(s21_exp_test_12) {
  ck_assert_double_eq_tol(s21_exp(0.14), exp(0.14), 0.000001);
}
END_TEST

START_TEST(s21_exp_test_13) {
  ck_assert_double_eq_tol(s21_exp(-0.14), exp(-0.14), 0.000001);
}
END_TEST

Suite *exp_suite(void) {
  Suite *s;
  TCase *tc_values;
  s = suite_create("exp(x)");

  tc_values = tcase_create("values");
  tcase_add_test(tc_values, s21_exp_test_1);
  tcase_add_test(tc_values, s21_exp_test_2);
  tcase_add_test(tc_values, s21_exp_test_3);
  tcase_add_test(tc_values, s21_exp_test_4);
  tcase_add_test(tc_values, s21_exp_test_5);
  tcase_add_test(tc_values, s21_exp_test_6);
  tcase_add_test(tc_values, s21_exp_test_7);
  tcase_add_test(tc_values, s21_exp_test_8);
  tcase_add_test(tc_values, s21_exp_test_9);
  tcase_add_test(tc_values, s21_exp_test_10);
  tcase_add_test(tc_values, s21_exp_test_11);
  tcase_add_test(tc_values, s21_exp_test_12);
  tcase_add_test(tc_values, s21_exp_test_13);
  suite_add_tcase(s, tc_values);
  return s;
}

/*S21_FABS_TEST*/

START_TEST(s21_fabs_test_1) { ck_assert_double_eq(s21_fabs(0.), fabs(0.)); }
END_TEST

START_TEST(s21_fabs_test_2) {
  ck_assert_double_eq_tol(s21_fabs(3.), fabs(3.), 0.000001);
}
END_TEST

START_TEST(s21_fabs_test_3) {
  ck_assert_double_eq_tol(s21_fabs(-3.), fabs(-3.), 0.000001);
}
END_TEST

START_TEST(s21_fabs_test_4) {
  ck_assert_double_nan(s21_fabs(NAN));
  ck_assert_double_nan(fabs(NAN));
}
END_TEST

START_TEST(s21_fabs_test_5) {
  ck_assert_double_eq(s21_fabs(-INFINITY), fabs(-INFINITY));
}
END_TEST

START_TEST(s21_fabs_test_6) {
  ck_assert_double_eq(s21_fabs(INFINITY), fabs(INFINITY));
}
END_TEST

START_TEST(s21_fabs_test_7) {
  ck_assert_double_eq_tol(s21_fabs(-1.), fabs(-1.), 0.000001);
}
END_TEST

START_TEST(s21_fabs_test_8) {
  ck_assert_double_eq_tol(s21_fabs(1.), fabs(1.), 0.000001);
}
END_TEST

START_TEST(s21_fabs_test_9) {
  ck_assert_double_eq_tol(s21_fabs(0.223), fabs(0.223), 0.000001);
}
END_TEST

START_TEST(s21_fabs_test_10) {
  ck_assert_double_eq_tol(s21_fabs(-0.2), fabs(-0.2), 0.000001);
}
END_TEST

START_TEST(s21_fabs_test_11) {
  ck_assert_double_eq_tol(s21_fabs(15.45), fabs(15.45), 0.000001);
}
END_TEST

START_TEST(s21_fabs_test_12) {
  ck_assert_double_eq_tol(s21_fabs(M_PI), fabs(M_PI), 0.000001);
}
END_TEST

START_TEST(s21_fabs_test_13) {
  ck_assert_double_eq_tol(s21_fabs(-M_PI), fabs(-M_PI), 0.000001);
}
END_TEST

Suite *fabs_suite(void) {
  Suite *s;
  TCase *tc_values;
  s = suite_create("fabs(x)");

  tc_values = tcase_create("values");
  tcase_add_test(tc_values, s21_fabs_test_1);
  tcase_add_test(tc_values, s21_fabs_test_2);
  tcase_add_test(tc_values, s21_fabs_test_3);
  tcase_add_test(tc_values, s21_fabs_test_4);
  tcase_add_test(tc_values, s21_fabs_test_5);
  tcase_add_test(tc_values, s21_fabs_test_6);
  tcase_add_test(tc_values, s21_fabs_test_7);
  tcase_add_test(tc_values, s21_fabs_test_8);
  tcase_add_test(tc_values, s21_fabs_test_9);
  tcase_add_test(tc_values, s21_fabs_test_10);
  tcase_add_test(tc_values, s21_fabs_test_11);
  tcase_add_test(tc_values, s21_fabs_test_12);
  tcase_add_test(tc_values, s21_fabs_test_13);
  suite_add_tcase(s, tc_values);
  return s;
}

/*S21_FLOOR_TEST*/

START_TEST(s21_floor_test_1) { ck_assert_double_eq(s21_floor(0), floor(0)); }
END_TEST

START_TEST(s21_floor_test_2) {
  ck_assert_double_eq_tol(s21_floor(3.2356), floor(3.2356), 0.000001);
}
END_TEST

START_TEST(s21_floor_test_3) {
  ck_assert_double_eq_tol(s21_floor(-3.1113), floor(-3.1113), 0.000001);
}
END_TEST

START_TEST(s21_floor_test_4) {
  ck_assert_double_nan(s21_floor(NAN));
  ck_assert_double_nan(floor(NAN));
}
END_TEST

START_TEST(s21_floor_test_5) {
  ck_assert_double_eq(s21_floor(INFINITY), floor(INFINITY));
}
END_TEST

START_TEST(s21_floor_test_6) {
  ck_assert_double_eq(s21_floor(-INFINITY), floor(-INFINITY));
}
END_TEST

START_TEST(s21_floor_test_7) {
  ck_assert_double_eq_tol(s21_floor(-1), floor(-1), 0.000001);
}
END_TEST

START_TEST(s21_floor_test_8) {
  ck_assert_double_eq_tol(s21_floor(1), floor(1), 0.000001);
}
END_TEST

START_TEST(s21_floor_test_9) {
  ck_assert_double_eq_tol(s21_floor(0.223), floor(0.223), 0.000001);
}
END_TEST

START_TEST(s21_floor_test_10) {
  ck_assert_double_eq(s21_floor(-0.2), floor(-0.2));
}
END_TEST

START_TEST(s21_floor_test_11) {
  ck_assert_double_eq_tol(s21_floor(15.45), floor(15.45), 0.000001);
}
END_TEST

START_TEST(s21_floor_test_12) {
  ck_assert_double_eq(s21_floor(M_PI), floor(M_PI));
}
END_TEST

START_TEST(s21_floor_test_13) {
  ck_assert_double_eq_tol(s21_floor(-M_PI), floor(-M_PI), 0.000001);
}
END_TEST

Suite *floor_suite(void) {
  Suite *s;
  TCase *tc_values;
  s = suite_create("floor(x)");

  tc_values = tcase_create("values");
  tcase_add_test(tc_values, s21_floor_test_1);
  tcase_add_test(tc_values, s21_floor_test_2);
  tcase_add_test(tc_values, s21_floor_test_3);
  tcase_add_test(tc_values, s21_floor_test_4);
  tcase_add_test(tc_values, s21_floor_test_5);
  tcase_add_test(tc_values, s21_floor_test_6);
  tcase_add_test(tc_values, s21_floor_test_7);
  tcase_add_test(tc_values, s21_floor_test_8);
  tcase_add_test(tc_values, s21_floor_test_9);
  tcase_add_test(tc_values, s21_floor_test_10);
  tcase_add_test(tc_values, s21_floor_test_11);
  tcase_add_test(tc_values, s21_floor_test_12);
  tcase_add_test(tc_values, s21_floor_test_13);
  suite_add_tcase(s, tc_values);
  return s;
}

/*S21_FMOD_TEST*/

START_TEST(s21_fmod_test_1) {
  ck_assert_double_nan(s21_fmod(0, 0));
  ck_assert_double_nan(fmod(0, 0));
}
END_TEST

START_TEST(s21_fmod_test_2) {
  ck_assert_double_nan(s21_fmod(3.2356, 0));
  ck_assert_double_nan(fmod(3.2356, 0));
}
END_TEST

START_TEST(s21_fmod_test_3) {
  ck_assert_double_eq_tol(s21_fmod(0, -3.1113), fmod(0, -3.1113), 0.000001);
}
END_TEST

START_TEST(s21_fmod_test_4) {
  ck_assert_double_nan(s21_fmod(NAN, NAN));
  ck_assert_double_nan(fmod(NAN, NAN));
}
END_TEST

START_TEST(s21_fmod_test_5) {
  ck_assert_double_nan(s21_fmod(INFINITY, INFINITY));
  ck_assert_double_nan(fmod(INFINITY, INFINITY));
}
END_TEST

START_TEST(s21_fmod_test_6) {
  ck_assert_double_nan(s21_fmod(-INFINITY, -INFINITY));
  ck_assert_double_nan(fmod(-INFINITY, -INFINITY));
}
END_TEST

START_TEST(s21_fmod_test_7) {
  ck_assert_double_eq_tol(s21_fmod(-1, 2), fmod(-1, 2), 0.000001);
}
END_TEST

START_TEST(s21_fmod_test_8) {
  ck_assert_double_eq_tol(s21_fmod(1, INFINITY), fmod(1, INFINITY), 0.000001);
}
END_TEST

START_TEST(s21_fmod_test_9) {
  ck_assert_double_eq(s21_fmod(0.223, 0.1245), fmod(0.223, 0.1245));
}
END_TEST

START_TEST(s21_fmod_test_10) {
  ck_assert_double_eq(s21_fmod(-0.2, -INFINITY), fmod(-0.2, -INFINITY));
}
END_TEST

START_TEST(s21_fmod_test_11) {
  ck_assert_double_nan(s21_fmod(15.45, NAN));
  ck_assert_double_nan(fmod(15.45, NAN));
}
END_TEST

START_TEST(s21_fmod_test_12) {
  ck_assert_double_eq(s21_fmod(M_PI, -INFINITY), fmod(M_PI, -INFINITY));
}
END_TEST

START_TEST(s21_fmod_test_13) {
  ck_assert_double_eq_tol(s21_fmod(-M_PI, INFINITY), fmod(-M_PI, INFINITY),
                          0.000001);
}
END_TEST

Suite *fmod_suite(void) {
  Suite *s;
  TCase *tc_values;
  s = suite_create("fmod(x)");

  tc_values = tcase_create("values");
  tcase_add_test(tc_values, s21_fmod_test_1);
  tcase_add_test(tc_values, s21_fmod_test_2);
  tcase_add_test(tc_values, s21_fmod_test_3);
  tcase_add_test(tc_values, s21_fmod_test_4);
  tcase_add_test(tc_values, s21_fmod_test_5);
  tcase_add_test(tc_values, s21_fmod_test_6);
  tcase_add_test(tc_values, s21_fmod_test_7);
  tcase_add_test(tc_values, s21_fmod_test_8);
  tcase_add_test(tc_values, s21_fmod_test_9);
  tcase_add_test(tc_values, s21_fmod_test_10);
  tcase_add_test(tc_values, s21_fmod_test_11);
  tcase_add_test(tc_values, s21_fmod_test_12);
  tcase_add_test(tc_values, s21_fmod_test_13);
  suite_add_tcase(s, tc_values);
  return s;
}

/*S21_LOG_TEST*/

START_TEST(s21_log_test_1) { ck_assert_double_eq(s21_log(0), log(0)); }
END_TEST

START_TEST(s21_log_test_2) {
  ck_assert_double_eq_tol(s21_log(3.2356), log(3.2356), 0.000001);
}
END_TEST

START_TEST(s21_log_test_3) {
  ck_assert_double_nan(s21_log(-3.1113));
  ck_assert_double_nan(log(-3.1113));
}
END_TEST

START_TEST(s21_log_test_4) {
  ck_assert_double_nan(s21_log(NAN));
  ck_assert_double_nan(log(NAN));
}
END_TEST

START_TEST(s21_log_test_5) {
  ck_assert_double_eq(s21_log(INFINITY), log(INFINITY));
}
END_TEST

START_TEST(s21_log_test_6) {
  ck_assert_double_nan(s21_log(-INFINITY));
  ck_assert_double_nan(log(-INFINITY));
}
END_TEST

START_TEST(s21_log_test_7) {
  ck_assert_double_nan(s21_log(-1));
  ck_assert_double_nan(log(-1));
}
END_TEST

START_TEST(s21_log_test_8) {
  ck_assert_double_eq_tol(s21_log(1), log(1), 0.000001);
}
END_TEST

START_TEST(s21_log_test_9) {
  ck_assert_double_eq_tol(s21_log(0.223), log(0.223), 0.000001);
}
END_TEST

START_TEST(s21_log_test_10) {
  ck_assert_double_eq_tol(s21_log(0.2), log(0.2), 0.000001);
}
END_TEST

START_TEST(s21_log_test_11) {
  ck_assert_double_eq_tol(s21_log(15.45), log(15.45), 0.000001);
}
END_TEST

START_TEST(s21_log_test_12) {
  ck_assert_double_eq_tol(s21_log(M_PI), log(M_PI), 0.000001);
}
END_TEST

START_TEST(s21_log_test_13) {
  ck_assert_double_eq_tol(s21_log(2 * M_PI), log(2 * M_PI), 0.000001);
}
END_TEST

Suite *log_suite(void) {
  Suite *s;
  TCase *tc_values;
  s = suite_create("log(x)");

  tc_values = tcase_create("values");
  tcase_add_test(tc_values, s21_log_test_1);
  tcase_add_test(tc_values, s21_log_test_2);
  tcase_add_test(tc_values, s21_log_test_3);
  tcase_add_test(tc_values, s21_log_test_4);
  tcase_add_test(tc_values, s21_log_test_5);
  tcase_add_test(tc_values, s21_log_test_6);
  tcase_add_test(tc_values, s21_log_test_7);
  tcase_add_test(tc_values, s21_log_test_8);
  tcase_add_test(tc_values, s21_log_test_9);
  tcase_add_test(tc_values, s21_log_test_10);
  tcase_add_test(tc_values, s21_log_test_11);
  tcase_add_test(tc_values, s21_log_test_12);
  tcase_add_test(tc_values, s21_log_test_13);
  suite_add_tcase(s, tc_values);
  return s;
}

/*S21_POW_TEST*/

START_TEST(s21_pow_test_1) { ck_assert_double_eq(s21_pow(0, 0), pow(0, 0)); }
END_TEST

START_TEST(s21_pow_test_2) {
  ck_assert_double_eq(s21_pow(3.2356, 0), pow(3.2356, 0));
}
END_TEST

START_TEST(s21_pow_test_3) {
  ck_assert_double_eq(s21_pow(0, -3.1113), pow(0, -3.1113));
}
END_TEST

START_TEST(s21_pow_test_4) {
  ck_assert_double_nan(s21_pow(NAN, NAN));
  ck_assert_double_nan(pow(NAN, NAN));
}
END_TEST

START_TEST(s21_pow_test_5) {
  ck_assert_double_eq(s21_pow(INFINITY, INFINITY), pow(INFINITY, INFINITY));
}
END_TEST

START_TEST(s21_pow_test_6) {
  ck_assert_double_eq(s21_pow(-INFINITY, -INFINITY), pow(-INFINITY, -INFINITY));
}
END_TEST

START_TEST(s21_pow_test_7) {
  ck_assert_double_eq_tol(s21_pow(-1, 2), pow(-1, 2), 0.000001);
}
END_TEST

START_TEST(s21_pow_test_8) {
  ck_assert_double_eq_tol(s21_pow(1, INFINITY), pow(1, INFINITY), 0.000001);
}
END_TEST

START_TEST(s21_pow_test_9) {
  ck_assert_double_eq_tol(s21_pow(0.223, 0.1245), pow(0.223, 0.1245), 0.000001);
}
END_TEST

START_TEST(s21_pow_test_10) {
  ck_assert_double_eq(s21_pow(-0.2, -INFINITY), pow(-0.2, -INFINITY));
}
END_TEST

START_TEST(s21_pow_test_11) {
  ck_assert_double_nan(s21_pow(15.45, NAN));
  ck_assert_double_nan(pow(15.45, NAN));
}
END_TEST

START_TEST(s21_pow_test_12) {
  ck_assert_double_eq_tol(s21_pow(-2, -1), pow(-2, -1), 0.000001);
}
END_TEST

START_TEST(s21_pow_test_13) {
  ck_assert_double_eq_tol(s21_pow(-1, -2), pow(-1, -2), 0.000001);
}
END_TEST

Suite *pow_suite(void) {
  Suite *s;
  TCase *tc_values;
  s = suite_create("pow(x)");

  tc_values = tcase_create("values");
  tcase_add_test(tc_values, s21_pow_test_1);
  tcase_add_test(tc_values, s21_pow_test_2);
  tcase_add_test(tc_values, s21_pow_test_3);
  tcase_add_test(tc_values, s21_pow_test_4);
  tcase_add_test(tc_values, s21_pow_test_5);
  tcase_add_test(tc_values, s21_pow_test_6);
  tcase_add_test(tc_values, s21_pow_test_7);
  tcase_add_test(tc_values, s21_pow_test_8);
  tcase_add_test(tc_values, s21_pow_test_9);
  tcase_add_test(tc_values, s21_pow_test_10);
  tcase_add_test(tc_values, s21_pow_test_11);
  tcase_add_test(tc_values, s21_pow_test_12);
  tcase_add_test(tc_values, s21_pow_test_13);
  suite_add_tcase(s, tc_values);
  return s;
}

/*S21_SIN_TEST*/

START_TEST(s21_sin_test_1) { ck_assert_double_eq(s21_sin(0), sin(0)); }
END_TEST

START_TEST(s21_sin_test_2) {
  ck_assert_double_eq_tol(s21_sin(3), sin(3), 0.000001);
}
END_TEST

START_TEST(s21_sin_test_3) {
  ck_assert_double_eq_tol(s21_sin(-3), sin(-3), 0.000001);
}
END_TEST

START_TEST(s21_sin_test_4) {
  ck_assert_double_nan(s21_sin(NAN));
  ck_assert_double_nan(sin(NAN));
}
END_TEST

START_TEST(s21_sin_test_5) {
  ck_assert_double_nan(s21_sin(-INFINITY));
  ck_assert_double_nan(sin(-INFINITY));
}
END_TEST

START_TEST(s21_sin_test_6) {
  ck_assert_double_nan(s21_sin(INFINITY));
  ck_assert_double_nan(sin(INFINITY));
}
END_TEST

START_TEST(s21_sin_test_7) {
  ck_assert_double_eq_tol(s21_sin(-1), sin(-1), 0.000001);
}
END_TEST

START_TEST(s21_sin_test_8) {
  ck_assert_double_eq_tol(s21_sin(1), sin(1), 0.000001);
}
END_TEST

START_TEST(s21_sin_test_9) {
  ck_assert_double_eq_tol(s21_sin(0.223), sin(0.223), 0.000001);
}
END_TEST

START_TEST(s21_sin_test_10) {
  ck_assert_double_eq_tol(s21_sin(-0.2), sin(-0.2), 0.000001);
}
END_TEST

START_TEST(s21_sin_test_11) {
  ck_assert_double_eq_tol(s21_sin(15.45), sin(15.45), 0.000001);
}
END_TEST

START_TEST(s21_sin_test_12) {
  ck_assert_double_eq_tol(s21_sin(-15.45), sin(-15.45), 0.000001);
}
END_TEST

START_TEST(s21_sin_test_13) {
  ck_assert_double_eq_tol(s21_sin(123456.23), sin(123456.23), 0.000001);
}
END_TEST

Suite *sin_suite(void) {
  Suite *s;
  TCase *tc_values;
  s = suite_create("sin(x)");

  tc_values = tcase_create("values");
  tcase_add_test(tc_values, s21_sin_test_1);
  tcase_add_test(tc_values, s21_sin_test_2);
  tcase_add_test(tc_values, s21_sin_test_3);
  tcase_add_test(tc_values, s21_sin_test_4);
  tcase_add_test(tc_values, s21_sin_test_5);
  tcase_add_test(tc_values, s21_sin_test_6);
  tcase_add_test(tc_values, s21_sin_test_7);
  tcase_add_test(tc_values, s21_sin_test_8);
  tcase_add_test(tc_values, s21_sin_test_9);
  tcase_add_test(tc_values, s21_sin_test_10);
  tcase_add_test(tc_values, s21_sin_test_11);
  tcase_add_test(tc_values, s21_sin_test_12);
  tcase_add_test(tc_values, s21_sin_test_13);
  suite_add_tcase(s, tc_values);
  return s;
}

/*S21_SQRT_TEST*/

START_TEST(s21_sqrt_test_1) { ck_assert_double_eq(s21_sqrt(0), sqrt(0)); }
END_TEST

START_TEST(s21_sqrt_test_2) {
  ck_assert_double_eq_tol(s21_sqrt(3), sqrt(3), 0.000001);
}
END_TEST

START_TEST(s21_sqrt_test_3) {
  ck_assert_double_nan(s21_sqrt(-3));
  ck_assert_double_nan(sqrt(-3));
}
END_TEST

START_TEST(s21_sqrt_test_4) {
  ck_assert_double_nan(s21_sqrt(NAN));
  ck_assert_double_nan(sqrt(NAN));
}
END_TEST

START_TEST(s21_sqrt_test_5) {
  ck_assert_double_nan(s21_sqrt(-INFINITY));
  ck_assert_double_nan(sqrt(-INFINITY));
}
END_TEST

START_TEST(s21_sqrt_test_6) {
  ck_assert_double_eq(s21_sqrt(INFINITY), sqrt(INFINITY));
}
END_TEST

START_TEST(s21_sqrt_test_7) {
  ck_assert_double_nan(s21_sqrt(-1));
  ck_assert_double_nan(sqrt(-1));
}
END_TEST

START_TEST(s21_sqrt_test_8) {
  ck_assert_double_eq_tol(s21_sqrt(1), sqrt(1), 0.000001);
}
END_TEST

START_TEST(s21_sqrt_test_9) {
  ck_assert_double_eq_tol(s21_sqrt(0.223), sqrt(0.223), 0.000001);
}
END_TEST

START_TEST(s21_sqrt_test_10) {
  ck_assert_double_nan(s21_sqrt(-0.2));
  ck_assert_double_nan(sqrt(-0.2));
}
END_TEST

START_TEST(s21_sqrt_test_11) {
  ck_assert_double_eq_tol(s21_sqrt(1.45), sqrt(1.45), 0.000001);
}
END_TEST

START_TEST(s21_sqrt_test_12) {
  ck_assert_double_eq_tol(s21_sqrt(3.14), sqrt(3.14), 0.000001);
}
END_TEST

START_TEST(s21_sqrt_test_13) {
  ck_assert_double_nan(s21_sqrt(-0.12));
  ck_assert_double_nan(sqrt(-0.12));
}
END_TEST

Suite *sqrt_suite(void) {
  Suite *s;
  TCase *tc_values;
  s = suite_create("sqrt(x)");

  tc_values = tcase_create("values");
  tcase_add_test(tc_values, s21_sqrt_test_1);
  tcase_add_test(tc_values, s21_sqrt_test_2);
  tcase_add_test(tc_values, s21_sqrt_test_3);
  tcase_add_test(tc_values, s21_sqrt_test_4);
  tcase_add_test(tc_values, s21_sqrt_test_5);
  tcase_add_test(tc_values, s21_sqrt_test_6);
  tcase_add_test(tc_values, s21_sqrt_test_7);
  tcase_add_test(tc_values, s21_sqrt_test_8);
  tcase_add_test(tc_values, s21_sqrt_test_9);
  tcase_add_test(tc_values, s21_sqrt_test_10);
  tcase_add_test(tc_values, s21_sqrt_test_11);
  tcase_add_test(tc_values, s21_sqrt_test_12);
  tcase_add_test(tc_values, s21_sqrt_test_13);
  suite_add_tcase(s, tc_values);
  return s;
}

/*S21_TAN_TEST*/

START_TEST(s21_tan_test_1) { ck_assert_double_eq(s21_tan(0), tan(0)); }
END_TEST

START_TEST(s21_tan_test_2) {
  ck_assert_double_eq_tol(s21_tan(3), tan(3), 0.000001);
}
END_TEST

START_TEST(s21_tan_test_3) {
  ck_assert_double_eq_tol(s21_tan(-3), tan(-3), 0.000001);
}
END_TEST

START_TEST(s21_tan_test_4) {
  ck_assert_double_nan(s21_tan(NAN));
  ck_assert_double_nan(tan(NAN));
}
END_TEST

START_TEST(s21_tan_test_5) {
  ck_assert_double_nan(s21_tan(-INFINITY));
  ck_assert_double_nan(tan(-INFINITY));
}
END_TEST

START_TEST(s21_tan_test_6) {
  ck_assert_double_nan(s21_tan(INFINITY));
  ck_assert_double_nan(tan(INFINITY));
}
END_TEST

START_TEST(s21_tan_test_7) {
  ck_assert_double_eq_tol(s21_tan(-1), tan(-1), 0.000001);
}
END_TEST

START_TEST(s21_tan_test_8) {
  ck_assert_double_eq_tol(s21_tan(1), tan(1), 0.000001);
}
END_TEST

START_TEST(s21_tan_test_9) {
  ck_assert_double_eq_tol(s21_tan(0.223), tan(0.223), 0.000001);
}
END_TEST

START_TEST(s21_tan_test_10) {
  ck_assert_double_eq_tol(s21_tan(-0.2), tan(-0.2), 0.000001);
}
END_TEST

START_TEST(s21_tan_test_11) {
  ck_assert_double_eq_tol(s21_tan(15.45), tan(15.45), 0.000001);
}
END_TEST

START_TEST(s21_tan_test_12) {
  ck_assert_double_eq_tol(s21_tan(M_PI), tan(M_PI), 0.000001);
}
END_TEST

START_TEST(s21_tan_test_13) {
  ck_assert_double_eq_tol(s21_tan(-M_PI), tan(-M_PI), 0.000001);
}
END_TEST

Suite *tan_suite(void) {
  Suite *s;
  TCase *tc_values;
  s = suite_create("tan(x)");

  tc_values = tcase_create("values");
  tcase_add_test(tc_values, s21_tan_test_1);
  tcase_add_test(tc_values, s21_tan_test_2);
  tcase_add_test(tc_values, s21_tan_test_3);
  tcase_add_test(tc_values, s21_tan_test_4);
  tcase_add_test(tc_values, s21_tan_test_5);
  tcase_add_test(tc_values, s21_tan_test_6);
  tcase_add_test(tc_values, s21_tan_test_7);
  tcase_add_test(tc_values, s21_tan_test_8);
  tcase_add_test(tc_values, s21_tan_test_9);
  tcase_add_test(tc_values, s21_tan_test_10);
  tcase_add_test(tc_values, s21_tan_test_11);
  tcase_add_test(tc_values, s21_tan_test_12);
  tcase_add_test(tc_values, s21_tan_test_13);
  suite_add_tcase(s, tc_values);
  return s;
}

void case_test(Suite *s, int *fail) {
  SRunner *runner = srunner_create(s);
  srunner_set_fork_status(runner, CK_NOFORK);
  srunner_run_all(runner, CK_NORMAL);
  *fail = srunner_ntests_failed(runner);
  srunner_free(runner);
}

int main() {
  int fail = 0;
  case_test(abs_suite(), &fail);
  case_test(acos_suite(), &fail);
  case_test(asin_suite(), &fail);
  case_test(atan_suite(), &fail);
  case_test(ceil_suite(), &fail);
  case_test(cos_suite(), &fail);
  case_test(exp_suite(), &fail);
  case_test(fabs_suite(), &fail);
  case_test(floor_suite(), &fail);
  case_test(fmod_suite(), &fail);
  case_test(log_suite(), &fail);
  case_test(pow_suite(), &fail);
  case_test(sin_suite(), &fail);
  case_test(sqrt_suite(), &fail);
  case_test(tan_suite(), &fail);
  return fail;
}
