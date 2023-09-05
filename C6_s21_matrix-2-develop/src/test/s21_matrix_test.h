#ifndef S21_MATRIX_TEST_H
#define S21_MATRIX_TEST_H

#include <check.h>

#include "../s21_matrix.h"

Suite *create_matrix_suite();
Suite *eq_matrix_suite();
Suite *sum_matrix_suite();
Suite *sub_matrix_suite();
Suite *mult_matrix_suite();
Suite *mult_number_suite();
Suite *transpose_suite();
Suite *determinant_suite();
Suite *calc_complements_suite();
Suite *inverse_matrix_suite();

#endif
