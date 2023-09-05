#include "cat.h"

#include <stdio.h>
#include <string.h>

#include "../common/com.h"

const char* non_print[255] = {
    [0] = "^@",      [1] = "^A",     [2] = "^B",     [3] = "^C",
    [4] = "^D",      [5] = "^E",     [6] = "^F",     [7] = "^G",
    [8] = "^H",      [9] = "^I",     [10] = "\n",    [11] = "^K",
    [12] = "^L",     [13] = "^M",    [14] = "^N",    [15] = "^O",
    [16] = "^P",     [17] = "^Q",    [18] = "^R",    [19] = "^S",
    [20] = "^T",     [21] = "^U",    [22] = "^V",    [23] = "^W",
    [24] = "^X",     [25] = "^Y",    [26] = "^Z",    [27] = "^[",
    [28] = "^\\",    [29] = "^]",    [30] = "^^",    [31] = "^_",
    [32] = " ",      [33] = "!",     [34] = "\"",    [35] = "#",
    [36] = "$",      [37] = "%",     [38] = "&",     [39] = "'",
    [40] = "(",      [41] = ")",     [42] = "*",     [43] = "+",
    [44] = ",",      [45] = "-",     [46] = ".",     [47] = "/",
    [48] = "0",      [49] = "1",     [50] = "2",     [51] = "3",
    [52] = "4",      [53] = "5",     [54] = "6",     [55] = "7",
    [56] = "8",      [57] = "9",     [58] = ":",     [59] = ";",
    [60] = "<",      [61] = "=",     [62] = ">",     [63] = "?",
    [64] = "@",      [65] = "A",     [66] = "B",     [67] = "C",
    [68] = "D",      [69] = "E",     [70] = "F",     [71] = "G",
    [72] = "H",      [73] = "I",     [74] = "J",     [75] = "K",
    [76] = "L",      [77] = "M",     [78] = "N",     [79] = "O",
    [80] = "P",      [81] = "Q",     [82] = "R",     [83] = "S",
    [84] = "T",      [85] = "U",     [86] = "V",     [87] = "W",
    [88] = "X",      [89] = "Y",     [90] = "Z",     [91] = "[",
    [92] = "\\",     [93] = "]",     [94] = "^",     [95] = "_",
    [96] = "`",      [97] = "a",     [98] = "b",     [99] = "c",
    [100] = "d",     [101] = "e",    [102] = "f",    [103] = "g",
    [104] = "h",     [105] = "i",    [106] = "j",    [107] = "k",
    [108] = "l",     [109] = "m",    [110] = "n",    [111] = "o",
    [112] = "p",     [113] = "q",    [114] = "r",    [115] = "s",
    [116] = "t",     [117] = "u",    [118] = "v",    [119] = "w",
    [120] = "x",     [121] = "y",    [122] = "z",    [123] = "{",
    [124] = "|",     [125] = "}",    [126] = "~",    [127] = "^?",
    [128] = "M-^@",  [129] = "M-^A", [130] = "M-^B", [131] = "M-^C",
    [132] = "M-^D",  [133] = "M-^E", [134] = "M-^F", [135] = "M-^G",
    [136] = "M-^H",  [137] = "M-^I", [138] = "M-^J", [139] = "M-^K",
    [140] = "M-^L",  [141] = "M-^M", [142] = "M-^N", [143] = "M-^O",
    [144] = "M-^P",  [145] = "M-^Q", [146] = "M-^R", [147] = "M-^S",
    [148] = "M-^T",  [149] = "M-^U", [150] = "M-^V", [151] = "M-^W",
    [152] = "M-^X",  [153] = "M-^Y", [154] = "M-^Z", [155] = "M-^[",
    [156] = "M-^\\", [157] = "M-^]", [158] = "M-^^", [159] = "M-^_"};

void non_flag(FILE* file) {
  char str[10000];
  while (fgets(str, 10000, file) != NULL) {
    printf("%s", str);
  }
}

void flag_b(FILE* file) {
  char str[10000];
  int k = 1;
  for (int i = 0; fgets(str, 10000, file) != NULL; i++) {
    if (strcmp(str, "\n") != 0) {
      printf("%6.d\t", k);
      k++;
      printf("%s", str);
      continue;
    }
    printf("%s", str);
  }
}
void flag_e(FILE* file, char* name) {
  char str[10000];
  for (int i = 0; fgets(str, 10000, file) != NULL; i++) {
    char* pointer = strpbrk(str, "\n");
    if (pointer != NULL) {
      *pointer = '$';
      *(pointer + 1) = '\n';
      *(pointer + 2) = '\0';
    }
    int count_1 = 0;
    int len = strlen(str);
    if (strcmp(name, "-E") != 0) {
      for (int j = 0; str[j] != '\0'; j++) {
        unsigned char tmp = str[j];
        if (tmp <= 8 || (tmp >= 11 && tmp <= 31)) {
          count_1 = swap_2(str, len, count_1, j, tmp);
        } else if (tmp >= 127 && tmp <= 159) {
          count_1 = swap_4(str, len, count_1, j, tmp);
        }
      }
    }
    printf("%s", str);
  }
}

void flag_n(FILE* file) {
  char str[10000];
  int k = 1;
  for (int i = 0; fgets(str, 10000, file) != NULL; i++) {
    printf("%6.d\t", k);
    k++;
    printf("%s", str);
  }
}

void flag_s(FILE* file) {
  char str[10000];
  int count = 0;
  for (int i = 0; fgets(str, 10000, file) != NULL; i++) {
    if (strcmp(str, "\n") == 0) {
      count++;
      if (count < 2) {
        printf("%s", str);
      }
      continue;
    }
    count = 0;
    printf("%s", str);
  }
}

void flag_T(FILE* file, char* name) {
  int count = 0;
  char str[10000];
  for (int i = 0; fgets(str, 10000, file) != NULL; i++) {
    int len = strlen(str);
    for (int j = 0; j < len; j++) {
      if (str[j] == '\t') {
        count = swap(str, len, count, j);
      }
    }
    int count_1 = 0;
    len = strlen(str);
    if (strcmp(name, "-T") != 0) {
      for (int j = 0; str[j] != '\0'; j++) {
        unsigned char tmp = str[j];
        if (tmp <= 8 || (tmp >= 11 && tmp <= 31)) {
          count_1 = swap_2(str, len, count_1, j, tmp);
        } else if (tmp >= 127 && tmp <= 159) {
          count_1 = swap_4(str, len, count_1, j, tmp);
        }
      }
    }
    printf("%s", str);
  }
}

void flag_V(FILE* file) {
  char str[10000];
  int count = 0;
  for (int i = 0; fgets(str, 10000, file) != NULL; i++) {
    int len = strlen(str);
    for (int j = 0; str[j] != '\0'; j++) {
      unsigned char tmp = str[j];
      if (tmp <= 8 || (tmp >= 11 && tmp <= 31)) {
        count = swap_2(str, len, count, j, tmp);
      } else if (tmp >= 127 && tmp <= 159) {
        count = swap_4(str, len, count, j, tmp);
      }
    }
    printf("%s", str);
  }
}

int swap_2(char* str, int len, int count, int j, int temp) {
  str[len + 1 + count] = '\0';
  for (int k = len + 1 + count; k > j + 1; k--) {
    str[k] = str[k - 1];
  }
  str[j] = non_print[temp][0];
  str[j + 1] = non_print[temp][1];
  count++;
  return count;
}

int swap_4(char* str, int len, int count, int j, int temp) {
  str[len + 3 + count] = '\0';
  for (int k = len + 3 + count; k > j + 3; k--) {
    str[k] = str[k - 3];
  }
  str[j] = non_print[temp][0];
  str[j + 1] = non_print[temp][1];
  str[j + 2] = non_print[temp][2];
  str[j + 3] = non_print[temp][3];
  count = count + 3;
  return count;
}

int swap(char* str, int len, int count, int j) {
  str[len + 1 + count] = '\0';
  for (int k = len + 1 + count; k > j + 1; k--) {
    str[k] = str[k - 1];
  }
  str[j] = '^';
  str[j + 1] = 'I';
  count++;
  return count;
}
