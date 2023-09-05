#include "grep.h"

#include <regex.h>
#include <stdio.h>
#include <string.h>

#include "../common/com.h"

void non_flag(char *argv[], FILE *file) {
  char str[10000];
  char *pattern = argv[1];
  regex_t preg;
  if (regcomp(&preg, pattern, REG_EXTENDED) == 0) {
    while (fgets(str, 10000, file) != NULL) {
      if (regexec(&preg, str, 0, NULL, 0) == 0) {
        printf("%s", str);
        transfer(str);
      }
    }
    regfree(&preg);
  } else {
    printf("\033[01;31mError!");
  }
}

void flag_e(char *argv[], FILE *file) {
  char str[10000];
  char *pattern = argv[2];
  regex_t preg;
  if (regcomp(&preg, pattern, REG_EXTENDED) == 0) {
    while (fgets(str, 10000, file) != NULL) {
      if (regexec(&preg, str, 0, NULL, 0) == 0) {
        printf("%s", str);
        transfer(str);
      }
    }
    regfree(&preg);
  } else {
    printf("\033[01;31mError!");
  }
}

void flag_i(char *argv[], FILE *file) {
  char str[10000];
  char *pattern = argv[2];
  regex_t preg;
  if (regcomp(&preg, pattern, REG_ICASE) == 0) {
    while (fgets(str, 10000, file) != NULL) {
      if (regexec(&preg, str, 0, NULL, 0) == 0) {
        printf("%s", str);
        transfer(str);
      }
    }
    regfree(&preg);
  } else {
    printf("\033[01;31mError!");
  }
}

void flag_v(char *argv[], FILE *file) {
  char str[10000];
  char *pattern = argv[2];
  regex_t preg;
  if (regcomp(&preg, pattern, REG_EXTENDED) == 0) {
    while (fgets(str, 10000, file) != NULL) {
      if (regexec(&preg, str, 0, NULL, 0) != 0) {
        printf("%s", str);
        transfer(str);
      }
    }
    regfree(&preg);
  } else {
    printf("\033[01;31mError!");
  }
}

void flag_c(char *argv[], FILE *file) {
  char str[10000];
  char *pattern = argv[2];
  regex_t preg;
  int count = 0;
  if (regcomp(&preg, pattern, REG_EXTENDED) == 0) {
    while (fgets(str, 10000, file) != NULL) {
      if (regexec(&preg, str, 0, NULL, 0) == 0) {
        count++;
      }
    }
    printf("%d\n", count);
    regfree(&preg);
  } else {
    printf("\033[01;31mError!");
  }
}

void flag_l(char *argv[]) {
  char str[10000];
  char *pattern = argv[2];
  regex_t preg;
  for (int i = 3; argv[i] != NULL; i++) {
    int end = 0;
    FILE *file = fopen(argv[i], "r");
    if (regcomp(&preg, pattern, REG_EXTENDED) != 0 && end == 0) {
      printf("\033[01;31mError!");
      end++;
    }
    if (file != NULL) {
      while (fgets(str, 10000, file) != NULL) {
        if (regexec(&preg, str, 0, NULL, 0) == 0 && end == 0) {
          printf("%s\n", argv[i]);
          end++;
        }
      }
      regfree(&preg);
      fclose(file);
    } else {
      printf("\033[01;31mError! File not found!");
    }
  }
}

void flag_n(char *argv[], FILE *file) {
  char str[10000];
  char *pattern = argv[2];
  int k = 0;
  regex_t preg;
  if (regcomp(&preg, pattern, REG_EXTENDED) != 0) {
    printf("\033[01;31mError!");
  }
  while (fgets(str, 10000, file) != NULL) {
    k++;
    if (regexec(&preg, str, 0, NULL, 0) == 0) {
      printf("%d:%s", k, str);
      transfer(str);
    }
  }
  regfree(&preg);
}

void flag_h(char *argv[]) {
  char str[10000];
  char *pattern = argv[2];
  regex_t preg;
  for (int i = 3; argv[i] != NULL; i++) {
    int end = 0;
    FILE *file = fopen(argv[i], "r");
    if (regcomp(&preg, pattern, REG_EXTENDED) == 0 && end == 0) {
      if (file != NULL) {
        while (fgets(str, 10000, file) != NULL) {
          if (regexec(&preg, str, 0, NULL, 0) == 0) {
            printf("%s", str);
            transfer(str);
          }
        }
        regfree(&preg);
        fclose(file);
      } else {
        printf("\033[01;31mError! File not found!");
      }
    } else {
      printf("\033[01;31mError!");
    }
  }
}

void flag_s(char *argv[], FILE *file) {
  char str[10000];
  char *pattern = argv[2];
  regex_t preg;
  for (int i = 0; i != 1; i++) {
    int end = 0;
    if (regcomp(&preg, pattern, REG_EXTENDED) != 0 && end == 0) {
      end++;
    }
    while (fgets(str, 10000, file) != NULL) {
      if (regexec(&preg, str, 0, NULL, 0) == 0 && end == 0) {
        printf("%s", str);
        transfer(str);
      }
    }
    regfree(&preg);
  }
}

void flag_f(char *argv[]) {
  char pat[10000];
  char str[10000];
  regex_t preg;
  int flag = help(argv[2]);
  FILE *file = fopen(argv[3], "r");
  if (file != NULL) {
    for (int i = 0; fgets(str, 10000, file) != NULL; i++) {
      int end = 0;
      FILE *pattern = fopen(argv[2], "r");
      while (fgets(pat, 10000, pattern) != NULL) {
        string(pat);
        if (regcomp(&preg, pat, REG_EXTENDED) != 0 && end == 0) {
          printf("\033[01;31mError_1!");
          end++;
        }
        if (regexec(&preg, str, 0, NULL, 0) == 0 && flag == 0 && end == 0) {
          printf("%s", str);
          transfer(str);
          end++;
        } else if (flag == 1 && end == 0) {
          printf("%s", str);
          end++;
          transfer(str);
        }
        regfree(&preg);
      }
      fclose(pattern);
    }
    fclose(file);
  } else {
    printf("\033[01;31mError! File not found!");
  }
}

void flag_o(char *argv[], FILE *file) {
  char str[10000];
  char *pattern = argv[2];
  regex_t preg;
  if (regcomp(&preg, pattern, REG_EXTENDED) != 0) {
    printf("\033[01;31mError!");
  }
  while (fgets(str, 256, file) != NULL) {
    if (regexec(&preg, str, 0, NULL, 0) == 0) {
      for_flag_o(str, argv[2]);
    }
  }
  regfree(&preg);
}
