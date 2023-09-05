#include "s21_matrix_test.h"

START_TEST(s21_eq_matrix_test_1) {  //  Разные значения элементов матрицы
  int rows = rand() % 100 + 1;
  int columns = rand() % 100 + 1;
  matrix_t test_A = {0};
  matrix_t test_B = {0};
  s21_create_matrix(rows, columns, &test_A);
  s21_create_matrix(rows, columns, &test_B);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      test_A.matrix[i][j] = i;
      test_B.matrix[i][j] = j;
    }
  }

  ck_assert_int_eq(s21_eq_matrix(&test_A, &test_B), FAILURE);

  s21_remove_matrix(&test_A);
  s21_remove_matrix(&test_B);
}
END_TEST

START_TEST(s21_eq_matrix_test_2) {  //  Полное совпадение
  int rows = rand() % 100 + 1;
  int columns = rand() % 100 + 1;
  matrix_t test_A = {0};
  matrix_t test_B = {0};
  s21_create_matrix(rows, columns, &test_A);
  s21_create_matrix(rows, columns, &test_B);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      test_A.matrix[i][j] = i;
      test_B.matrix[i][j] = i;
    }
  }

  ck_assert_int_eq(s21_eq_matrix(&test_A, &test_B), SUCCESS);

  s21_remove_matrix(&test_A);
  s21_remove_matrix(&test_B);
}
END_TEST

START_TEST(s21_eq_matrix_test_3) {  //  Разное количество столбцов
  int rows = rand() % 100 + 1;
  int columns = rand() % 100 + 1;
  matrix_t test_A = {0};
  matrix_t test_B = {0};
  s21_create_matrix(rows, columns, &test_A);
  s21_create_matrix(columns, rows, &test_B);

  ck_assert_int_eq(s21_eq_matrix(&test_A, &test_B), FAILURE);

  s21_remove_matrix(&test_A);
  s21_remove_matrix(&test_B);
}
END_TEST

Suite *eq_matrix_suite() {
  Suite *s = suite_create("s21_eq_matrix");
  TCase *tc_values = tcase_create("Values");

  tcase_add_test(tc_values, s21_eq_matrix_test_1);
  tcase_add_test(tc_values, s21_eq_matrix_test_2);
  tcase_add_test(tc_values, s21_eq_matrix_test_3);

  suite_add_tcase(s, tc_values);
  return s;
}
