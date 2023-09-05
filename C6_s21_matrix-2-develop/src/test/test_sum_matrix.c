#include "s21_matrix_test.h"

START_TEST(s21_sum_matrix_test_1) {  //  Разное количество столбцов
  int rows = rand() % 100 + 1;
  int columns = rand() % 100 + 1;

  matrix_t test_A = {0};
  matrix_t test_B = {0};
  matrix_t test_result = {0};
  s21_create_matrix(rows, columns, &test_A);
  s21_create_matrix(columns, rows, &test_B);

  ck_assert_int_eq(s21_sum_matrix(&test_A, &test_B, &test_result), ERROR);

  s21_remove_matrix(&test_A);
  s21_remove_matrix(&test_B);
}
END_TEST

START_TEST(s21_sum_matrix_test_2) {  //  Матрица А 0 строк
  int rows = 0;
  int columns = rand() % 100 + 1;

  matrix_t test_A = {0};
  matrix_t test_B = {0};
  matrix_t test_result = {0};
  s21_create_matrix(rows, columns, &test_A);
  s21_create_matrix(columns, columns, &test_B);

  ck_assert_int_eq(s21_sum_matrix(&test_A, &test_B, &test_result), INCORRECT);

  s21_remove_matrix(&test_A);
  s21_remove_matrix(&test_B);
}
END_TEST

START_TEST(s21_sum_matrix_test_3) {  //  Корректные данные
  int rows = rand() % 100 + 1;
  int columns = rand() % 100 + 1;

  matrix_t test_A = {0};
  matrix_t test_B = {0};
  matrix_t test_result = {0};
  s21_create_matrix(rows, columns, &test_A);
  s21_create_matrix(rows, columns, &test_B);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      test_A.matrix[i][j] = rand() % 100 + 1;
      test_B.matrix[i][j] = rand() % 100 + 1;
    }
  }

  ck_assert_int_eq(s21_sum_matrix(&test_A, &test_B, &test_result), OK);

  s21_remove_matrix(&test_A);
  s21_remove_matrix(&test_B);
  s21_remove_matrix(&test_result);
}
END_TEST

START_TEST(s21_sum_matrix_test_4) {  //  Корректные данные ( матрица А с
                                     //  отрицательныи значениями)
  int rows = rand() % 100 + 1;
  int columns = rand() % 100 + 1;

  matrix_t test_A = {0};
  matrix_t test_B = {0};
  matrix_t test_result = {0};
  s21_create_matrix(rows, columns, &test_A);
  s21_create_matrix(rows, columns, &test_B);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      test_A.matrix[i][j] = -(rand() % 100 + 1);
      test_B.matrix[i][j] = rand() % 100 + 1;
    }
  }

  ck_assert_int_eq(s21_sum_matrix(&test_A, &test_B, &test_result), OK);

  s21_remove_matrix(&test_A);
  s21_remove_matrix(&test_B);
  s21_remove_matrix(&test_result);
}
END_TEST

Suite *sum_matrix_suite() {
  Suite *s = suite_create("s21_sum_matrix");
  TCase *tc_values = tcase_create("Values");

  tcase_add_test(tc_values, s21_sum_matrix_test_1);
  tcase_add_test(tc_values, s21_sum_matrix_test_2);
  tcase_add_test(tc_values, s21_sum_matrix_test_3);
  tcase_add_test(tc_values, s21_sum_matrix_test_4);

  suite_add_tcase(s, tc_values);
  return s;
}