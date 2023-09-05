#include "s21_matrix_test.h"

int main(void) {
  int fail = 0;

  Suite *s21_matrix_tests[] = {
      create_matrix_suite(), eq_matrix_suite(),   sum_matrix_suite(),
      sub_matrix_suite(),    mult_number_suite(), mult_matrix_suite(),
      transpose_suite(),     determinant_suite(), calc_complements_suite(),
      inverse_matrix_suite()};

  for (Suite **test_suite = s21_matrix_tests; *test_suite; test_suite++) {
    SRunner *test_set_runner = srunner_create(*test_suite);
    srunner_set_fork_status(test_set_runner, CK_NOFORK);
    srunner_run_all(test_set_runner, CK_NORMAL);  // спасает от утечек
    fail += srunner_ntests_failed(test_set_runner);
    srunner_free(test_set_runner);
  }

  return fail == 0 ? EXIT_SUCCESS : EXIT_FAILURE;
}
