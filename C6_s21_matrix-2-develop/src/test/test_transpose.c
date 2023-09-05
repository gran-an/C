#include "s21_matrix_test.h"

START_TEST(s21_transpose_test_1) {  //  Матрица А 0 столбцов
  int rows = rand() % 100 + 1;
  int columns = 0;

  matrix_t test_A = {0};
  matrix_t test_result = {0};
  s21_create_matrix(rows, columns, &test_A);

  ck_assert_int_eq(s21_transpose(&test_A, &test_result), INCORRECT);

  s21_remove_matrix(&test_A);
}
END_TEST

START_TEST(s21_transpose_test_2) {  //  Матрица А 0 строк
  int rows = 0;
  int columns = rand() % 100 + 1;

  matrix_t test_A = {0};
  matrix_t test_result = {0};
  s21_create_matrix(rows, columns, &test_A);

  ck_assert_int_eq(s21_transpose(&test_A, &test_result), INCORRECT);

  s21_remove_matrix(&test_A);
}
END_TEST

START_TEST(s21_transpose_test_3) {  //  Корректные данные (положительные)
  int rows = rand() % 100 + 1;
  int columns = rand() % 100 + 1;

  matrix_t test_A = {0};
  matrix_t test_result = {0};
  s21_create_matrix(rows, columns, &test_A);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      test_A.matrix[i][j] = rand() % 100 + 1;
    }
  }

  ck_assert_int_eq(s21_transpose(&test_A, &test_result), OK);

  s21_remove_matrix(&test_A);
  s21_remove_matrix(&test_result);
}
END_TEST

START_TEST(s21_transpose_test_4) {  //  Корректные данные (A матрица с
                                    //  отрицательными значениями)
  int rows = rand() % 100 + 1;
  int columns = rand() % 100 + 1;

  matrix_t test_A = {0};
  matrix_t test_result = {0};
  s21_create_matrix(rows, columns, &test_A);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      test_A.matrix[i][j] = -(rand() % 100 + 1);
    }
  }

  ck_assert_int_eq(s21_transpose(&test_A, &test_result), OK);

  s21_remove_matrix(&test_A);
  s21_remove_matrix(&test_result);
}
END_TEST

Suite *transpose_suite() {
  Suite *s = suite_create("s21_transpose");
  TCase *tc_values = tcase_create("Values");

  tcase_add_test(tc_values, s21_transpose_test_1);
  tcase_add_test(tc_values, s21_transpose_test_2);
  tcase_add_test(tc_values, s21_transpose_test_3);
  tcase_add_test(tc_values, s21_transpose_test_4);

  suite_add_tcase(s, tc_values);
  return s;
}