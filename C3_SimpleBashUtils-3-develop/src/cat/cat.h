#ifndef CAT_H
#define CAT_H
#include <stdio.h>

void non_flag(FILE* file);
void flag_b(FILE* file);
void flag_e(FILE* file, char* name);
void flag_n(FILE* file);
void flag_T(FILE* file, char* name);
void flag_V(FILE* file);
void flag_s(FILE* file);
int swap(char* str, int len, int count, int j);
int swap_2(char* str, int len, int count, int j, int temp);
int swap_4(char* str, int len, int count, int j, int temp);

#endif