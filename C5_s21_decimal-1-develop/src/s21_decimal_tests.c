#include "s21_decimal_tests.h"

int main(void) {
  int fail = 0;

  Suite *s21_decimal_tests[] = {s21_test_negate(),
                                s21_test_floor(),
                                s21_test_round(),
                                s21_test_truncate(),
                                s21_test_float_to_decimal(),
                                s21_test_int_to_decimal(),
                                s21_test_decimal_to_int(),
                                s21_test_decimal_to_float(),
                                s21_test_not_equal(),
                                s21_test_equal(),
                                s21_test_greater(),
                                s21_test_less(),
                                s21_test_greater_or_equal(),
                                s21_test_less_or_equal(),
                                s21_test_add(),
                                s21_test_mul(),
                                s21_test_div(),
                                s21_test_sub(),
                                NULL};

  for (Suite **test_suite = s21_decimal_tests; *test_suite; test_suite++) {
    SRunner *test_set_runner = srunner_create(*test_suite);
    srunner_set_fork_status(test_set_runner, CK_NOFORK);
    srunner_run_all(test_set_runner, CK_NORMAL);  // спасает от утечек
    fail += srunner_ntests_failed(test_set_runner);
    srunner_free(test_set_runner);
  }

  return fail == 0 ? EXIT_SUCCESS : EXIT_FAILURE;
}