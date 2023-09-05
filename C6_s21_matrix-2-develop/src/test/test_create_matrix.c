#include "s21_matrix_test.h"

START_TEST(s21_create_matrix_test_1) {  //  Совпадения строк и стобцов в матрице
                                        //  с заданным количеством
  int rows = rand() % 100 + 1;
  int columns = rand() % 100 + 1;
  matrix_t test = {0};
  s21_create_matrix(rows, columns, &test);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      test.matrix[i][j] = 0;
      ck_assert_int_eq(0, test.matrix[i][j]);
    }
  }

  ck_assert_int_eq(test.rows, rows);
  ck_assert_int_eq(test.columns, columns);

  s21_remove_matrix(&test);
}
END_TEST

START_TEST(s21_create_matrix_test_2) {  //  Количество строк = 0
  int rows = 0;
  int columns = rand() % 100 + 1;
  matrix_t test = {0};

  ck_assert_int_eq(s21_create_matrix(rows, columns, &test), INCORRECT);

  s21_remove_matrix(&test);
}
END_TEST

START_TEST(s21_create_matrix_test_3) {  //  Количество столбцов = 0
  int rows = rand() % 100 + 1;
  int columns = 0;
  matrix_t test = {0};

  ck_assert_int_eq(s21_create_matrix(rows, columns, &test), INCORRECT);

  s21_remove_matrix(&test);
}
END_TEST

START_TEST(s21_create_matrix_test_4) {  //  При создании матрицы вывод ОК
  int rows = 1;
  int columns = 1;
  matrix_t test = {0};

  ck_assert_int_eq(s21_create_matrix(rows, columns, &test), OK);

  s21_remove_matrix(&test);
}
END_TEST

Suite *create_matrix_suite() {
  Suite *s = suite_create("s21_create_matrix");
  TCase *tc_values = tcase_create("Values");

  tcase_add_test(tc_values, s21_create_matrix_test_1);
  tcase_add_test(tc_values, s21_create_matrix_test_2);
  tcase_add_test(tc_values, s21_create_matrix_test_3);
  tcase_add_test(tc_values, s21_create_matrix_test_4);

  suite_add_tcase(s, tc_values);
  return s;
}
