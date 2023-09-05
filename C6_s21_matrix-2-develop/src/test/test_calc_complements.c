#include "s21_matrix_test.h"

START_TEST(s21_calc_complements_test_1) {  //  Матрица А 0 столбцов
  int rows = rand() % 100 + 1;
  int columns = 0;

  matrix_t test_A = {0};
  matrix_t test_result = {0};
  s21_create_matrix(rows, columns, &test_A);

  ck_assert_int_eq(s21_calc_complements(&test_A, &test_result), INCORRECT);

  s21_remove_matrix(&test_A);
}
END_TEST

START_TEST(s21_calc_complements_test_2) {  //  Матрица А не квадратная
  int rows = rand() % 100 + 1;
  int columns = rand() % 100 + 1;

  matrix_t test_A = {0};
  matrix_t test_result = {0};
  s21_create_matrix(rows, columns, &test_A);

  ck_assert_int_eq(s21_calc_complements(&test_A, &test_result), ERROR);

  s21_remove_matrix(&test_A);
}
END_TEST

START_TEST(s21_calc_complements_test_3) {  //  Корректные данные (положительные)
  int rows = 3;

  matrix_t test_A = {0};
  matrix_t test_result = {0};
  s21_create_matrix(rows, rows, &test_A);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < rows; j++) {
      test_A.matrix[i][j] = rand() % 100 + 1;
    }
  }

  ck_assert_int_eq(s21_calc_complements(&test_A, &test_result), OK);

  s21_remove_matrix(&test_A);
  s21_remove_matrix(&test_result);
}
END_TEST

START_TEST(s21_calc_complements_test_4) {  //  Корректные данные (A матрица с
                                           //  отрицательными значениями)
  int rows = 4;

  matrix_t test_A = {0};
  matrix_t test_result = {0};
  s21_create_matrix(rows, rows, &test_A);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < rows; j++) {
      test_A.matrix[i][j] = -(rand() % 100 + 1);
    }
  }

  ck_assert_int_eq(s21_calc_complements(&test_A, &test_result), OK);

  s21_remove_matrix(&test_A);
  s21_remove_matrix(&test_result);
}
END_TEST

START_TEST(s21_calc_complements_test_5) {  //  Корректные данные (A матрица с
                                           //  отрицательными значениями)
  int rows = 5;

  matrix_t test_A = {0};
  matrix_t test_result = {0};
  s21_create_matrix(rows, rows, &test_A);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < rows; j++) {
      test_A.matrix[i][j] = -(rand() % 100 + 1);
    }
  }

  ck_assert_int_eq(s21_calc_complements(&test_A, &test_result), OK);

  s21_remove_matrix(&test_A);
  s21_remove_matrix(&test_result);
}
END_TEST

START_TEST(s21_calc_complements_test_6) {  //  Корректные данные (A матрица с
                                           //  отрицательными значениями)
  int rows = 6;

  matrix_t test_A = {0};
  matrix_t test_result = {0};
  s21_create_matrix(rows, rows, &test_A);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < rows; j++) {
      test_A.matrix[i][j] = -(rand() % 100 + 1);
    }
  }

  ck_assert_int_eq(s21_calc_complements(&test_A, &test_result), OK);

  s21_remove_matrix(&test_A);
  s21_remove_matrix(&test_result);
}
END_TEST

START_TEST(s21_calc_complements_test_7) {  //  Корректные данные (A матрица с
                                           //  отрицательными значениями)
  int rows = 7;

  matrix_t test_A = {0};
  matrix_t test_result = {0};
  s21_create_matrix(rows, rows, &test_A);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < rows; j++) {
      test_A.matrix[i][j] = -(rand() % 100 + 1);
    }
  }

  ck_assert_int_eq(s21_calc_complements(&test_A, &test_result), OK);

  s21_remove_matrix(&test_A);
  s21_remove_matrix(&test_result);
}
END_TEST

Suite *calc_complements_suite() {
  Suite *s = suite_create("s21_calc_complements");
  TCase *tc_values = tcase_create("Values");

  tcase_add_test(tc_values, s21_calc_complements_test_1);
  tcase_add_test(tc_values, s21_calc_complements_test_2);
  tcase_add_test(tc_values, s21_calc_complements_test_3);
  tcase_add_test(tc_values, s21_calc_complements_test_4);
  tcase_add_test(tc_values, s21_calc_complements_test_5);
  tcase_add_test(tc_values, s21_calc_complements_test_6);
  tcase_add_test(tc_values, s21_calc_complements_test_7);

  suite_add_tcase(s, tc_values);
  return s;
}