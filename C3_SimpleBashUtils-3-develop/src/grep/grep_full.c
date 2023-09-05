#include <stdio.h>
#include <string.h>

#include "../common/com.h"
#include "grep.h"

int main(int argc, char *argv[]) {
  int a = argc;
  a++;
  if (pruf_grep(argv[1]) == 0) {
    FILE *file = fopen(argv[2], "r");
    if (file != NULL) {
      non_flag(argv, file);
      fclose(file);
    } else {
      printf("\033[01;31mError! File not found!");
    }
  }
  if (pruf_grep(argv[1]) != 0) {
    FILE *file = fopen(argv[3], "r");
    if (file != NULL) {
      switch (pruf_grep(argv[1])) {
        case 1:
          flag_e(argv, file);
          break;
        case 2:
          flag_i(argv, file);
          break;
        case 3:
          flag_v(argv, file);
          break;
        case 4:
          flag_c(argv, file);
          break;
        case 5:
          flag_l(argv);
          break;
        case 6:
          flag_n(argv, file);
          break;
        case 7:
          flag_h(argv);
          break;
        case 8:
          flag_s(argv, file);
          break;
        case 9:
          flag_f(argv);
          break;
        case 10:
          flag_o(argv, file);
          break;
        default:
          printf("\033[01;31mError! Option not found!");
          break;
      }
      fclose(file);
    } else if (pruf_grep(argv[1]) != 8) {
      printf("\033[01;31mError! File not found!");
    }
  }
  return 0;
}