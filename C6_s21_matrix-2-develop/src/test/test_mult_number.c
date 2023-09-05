#include "s21_matrix_test.h"

START_TEST(s21_mult_number_test_1) {  //  Корректные данные (положительные)
  int rows = rand() % 100 + 1;
  int columns = rand() % 100 + 1;

  matrix_t test_A = {0};
  double num = rand() % 100 + 1;
  matrix_t test_result = {0};
  s21_create_matrix(rows, columns, &test_A);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      test_A.matrix[i][j] = rand() % 100 + 1;
    }
  }

  ck_assert_int_eq(s21_mult_number(&test_A, num, &test_result), OK);

  s21_remove_matrix(&test_A);
  s21_remove_matrix(&test_result);
}
END_TEST

START_TEST(s21_mult_number_test_2) {  //  Матрица А 0 строк
  int rows = 0;
  int columns = rand() % 100 + 1;

  matrix_t test_A = {0};
  double test_B = 0;
  matrix_t test_result = {0};
  s21_create_matrix(rows, columns, &test_A);

  ck_assert_int_eq(s21_mult_number(&test_A, test_B, &test_result), INCORRECT);

  s21_remove_matrix(&test_A);
  s21_remove_matrix(&test_result);
}
END_TEST

START_TEST(s21_mult_number_test_3) {  //  Корректные данные (все отрицательные)
  int rows = rand() % 100 + 1;
  int columns = rand() % 100 + 1;

  matrix_t test_A = {0};
  double num = -(rand() % 100 + 1);
  matrix_t test_result = {0};
  s21_create_matrix(rows, columns, &test_A);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      test_A.matrix[i][j] = -(rand() % 100 + 1);
    }
  }

  ck_assert_int_eq(s21_mult_number(&test_A, num, &test_result), OK);

  s21_remove_matrix(&test_A);
  s21_remove_matrix(&test_result);
}
END_TEST

START_TEST(s21_mult_number_test_4) {  //  Корректные данные (часть
                                      //  отрицательная, часть положительная)
  int rows = rand() % 100 + 1;
  int columns = rand() % 100 + 1;

  matrix_t test_A = {0};
  double num = -(rand() % 100 + 1);
  matrix_t test_result = {0};
  s21_create_matrix(rows, columns, &test_A);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      test_A.matrix[i][j] = rand() % 100 + 1;
    }
  }

  ck_assert_int_eq(s21_mult_number(&test_A, num, &test_result), OK);

  s21_remove_matrix(&test_A);
  s21_remove_matrix(&test_result);
}
END_TEST

Suite *mult_number_suite() {
  Suite *s = suite_create("s21_mult_number");
  TCase *tc_values = tcase_create("Values");

  tcase_add_test(tc_values, s21_mult_number_test_1);
  tcase_add_test(tc_values, s21_mult_number_test_2);
  tcase_add_test(tc_values, s21_mult_number_test_3);
  tcase_add_test(tc_values, s21_mult_number_test_4);

  suite_add_tcase(s, tc_values);
  return s;
}