#ifndef S21_CALC_H
#define S21_CALC_H

#include "s21_stack.h"

#define S21_NAN 0.0 / 0.0

#define S21_IS_NULL(x) (x < 1e-8 && x > -1e-8)

char *dijkstra_algorithm(char *input);  // shunting-yard algorithm (from Infix
                                        // notation in Postfix notation)
int priority(char oper);                // determination of operator priority
char trigonometry(char input_1, char input_2);
Data calculation(char *input, Data x_value);
Data calc_trigonometry(char function, Data X);
Data calc_math(Data value_1, Data value_2, char operand);
int isNumber(char input_1);
int validation(char *input);
#endif
