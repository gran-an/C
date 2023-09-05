#include "com.h"

#include <stdio.h>
#include <string.h>

int pruf_cat(char *arg) {
  int flag = 10;
  int end = 0;
  for (int i = 0; i != 1; i++) {
    if ((strcmp(arg, "-b") == 0 ||
         strncmp(arg, "--number-nonblank", 17) == 0) &&
        end == 0) {
      flag = 1;
      end++;
    }

    if ((strcmp(arg, "-e") == 0 || strcmp(arg, "-E") == 0 ||
         strcmp(arg, "-ev") == 0 || strcmp(arg, "-ve") == 0) &&
        end == 0) {
      flag = 2;
      end++;
    }

    if ((strcmp(arg, "-n") == 0 || ((strlen(arg) == strlen("--number")) &&
                                    strcmp(arg, "--number") == 0)) &&
        end == 0) {
      flag = 3;
      end++;
    }

    if ((strcmp(arg, "-s") == 0 || strncmp(arg, "--squeeze-blank", 15) == 0) &&
        end == 0) {
      flag = 4;
      end++;
    }

    if ((strcmp(arg, "-t") == 0 || strcmp(arg, "-T") == 0 ||
         strcmp(arg, "-vt") == 0 || strcmp(arg, "-tv") == 0) &&
        end == 0) {
      flag = 5;
      end++;
    }
    if (strcmp(arg, "-v") == 0 && end == 0) {
      flag = 6;
      end++;
    }
    if (strcmp(arg, "-") != 0 && end == 0) {
      flag = 0;
      end++;
    }
  }
  return flag;
}

int pruf_grep(char *arg) {
  int flag = 0;
  for (int i = 0; i != 1; i++) {
    if (strcmp(arg, "-e") == 0 || strcmp(arg, "-E") == 0 ||
        strcmp(arg, "-I") == 0 || strcmp(arg, "-S") == 0) {
      flag = 1;
      break;
    }
    if (strcmp(arg, "-i") == 0) {
      flag = 2;
      break;
    }
    if (strcmp(arg, "-v") == 0) {
      flag = 3;
      break;
    }
    if (strcmp(arg, "-c") == 0) {
      flag = 4;
      break;
    }
    if (strcmp(arg, "-l") == 0) {
      flag = 5;
      break;
    }
    if (strcmp(arg, "-n") == 0) {
      flag = 6;
      break;
    }
    if (strcmp(arg, "-h") == 0) {
      flag = 7;
      break;
    }
    if (strcmp(arg, "-s") == 0) {
      flag = 8;
      break;
    }
    if (strcmp(arg, "-f") == 0) {
      flag = 9;
      break;
    }
    if (strcmp(arg, "-o") == 0) {
      flag = 10;
      break;
    }
  }
  return flag;
}

int help(char *name) {
  int flag = 0;
  char srav[10000];
  FILE *prob = fopen(name, "r");
  for (int i = 0; fgets(srav, 256, prob) != NULL; i++) {
    if (strcmp(srav, "\n") == 0) {
      flag = 1;
    }
  }
  fclose(prob);
  return flag;
}

void string(char *str) {
  for (int i = 0; str[i] != '\0'; i++) {
    if (str[i] == '\n') {
      str[i] = '\0';
      break;
    }
  }
}

void for_flag_o(char *str, char *buff) {
  int count = 0;
  int len = strlen(buff);
  for (int i = 0; str[i] != '\0'; i++) {
    if (str[i] == buff[count]) {
      count++;
    }
    if (count == len) {
      printf("%s\n", buff);
      count = 0;
      continue;
    }
  }
}

void transfer(char *str) {
  int flag = 0;
  for (int i = 0; str[i] != '\0'; i++) {
    if (str[i] == '\n') {
      flag++;
    }
  }
  if (flag == 0) {
    printf("\n");
  }
}