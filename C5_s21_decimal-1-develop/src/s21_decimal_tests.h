#ifndef S21_DECIMAL_TESTS_H
#define S21_DECIMAL_TESTS_H

#include <check.h>
#include <stdio.h>
#include <stdlib.h>

#include "s21_decimal.h"

Suite *s21_test_negate();
Suite *s21_test_floor();
Suite *s21_test_round();
Suite *s21_test_truncate();

Suite *s21_test_float_to_decimal();
Suite *s21_test_int_to_decimal();
Suite *s21_test_decimal_to_int();
Suite *s21_test_decimal_to_float();

Suite *s21_test_not_equal();
Suite *s21_test_equal();
Suite *s21_test_greater();
Suite *s21_test_less();
Suite *s21_test_greater_or_equal();
Suite *s21_test_less_or_equal();

Suite *s21_test_add();
Suite *s21_test_mul();
Suite *s21_test_div();
Suite *s21_test_sub();

#endif