#ifndef GREP_H
#define GREP_H
#include <stdio.h>

void non_flag(char *argv[], FILE *file);
void flag_e(char *argv[], FILE *file);
void flag_i(char *argv[], FILE *file);
void flag_v(char *argv[], FILE *file);
void flag_c(char *argv[], FILE *file);
void flag_l(char *argv[]);
void flag_n(char *argv[], FILE *file);
void flag_h(char *argv[]);
void flag_s(char *argv[], FILE *file);
void flag_f(char *argv[]);
void flag_o(char *argv[], FILE *file);

#endif