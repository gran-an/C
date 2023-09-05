#include <stdio.h>
#include <string.h>

#include "../common/com.h"
#include "cat.h"

int main(int argc, char *argv[]) {
  int a = argc;
  a++;
  int flag = pruf_cat(argv[1]);
  if (flag == 0) {
    FILE *file = fopen(argv[1], "r");
    if (file != NULL) {
      non_flag(file);
      fclose(file);
    } else {
      printf("\033[01;31mError! File not found!");
    }
  }
  if (flag != 0) {
    FILE *file = fopen(argv[2], "r");
    if (file != NULL) {
      switch (flag) {
        case 1:
          flag_b(file);
          break;
        case 2:
          flag_e(file, argv[1]);
          break;
        case 3:
          flag_n(file);
          break;
        case 4:
          flag_s(file);
          break;
        case 5:
          flag_T(file, argv[1]);
          break;
        case 6:
          flag_V(file);
          break;
        default:
          printf("\033[01;31mError! Option not found!");
          break;
      }
      fclose(file);
    } else {
      printf("\033[01;31mError! File not found!");
    }
  }
  return 0;
}