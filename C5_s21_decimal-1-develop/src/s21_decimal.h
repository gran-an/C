#ifndef S21_DECIMAL_H
#define S21_DECIMAL_H

#include <iso646.h>
#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BITS_COUNT 32

#define S21_DECIMAL_E                                 \
  ((s21_decimal){{0b10000101011110101110110101011001, \
                  0b11101011111011001101111000110101, \
                  0b1010111110101010001100110101011,  \
                  0x1C0000}})  // 27182818284590452353602874713 / 10^28
#define S21_DECIMAL_PI                               \
  ((s21_decimal){{0x41B65F28, 0xB143885, 0x6582A536, \
                  0x1C0000}})  // 31415926535897932384626433832 / 10^28
#define PI_MUL_E {{0x17D37395, 0xD5652506, 0x1B97E70F, 0x1B0000}};
#define S21_DECIMAL_ONE {{1, 0, 0, 0}};

typedef struct {
  unsigned bits[4];
} s21_decimal;

typedef struct {
  unsigned bits[6];
} ass_21_big_dickcimal;

int s21_add(s21_decimal value_1, s21_decimal value_2,
            s21_decimal *result);  // Сложение
int s21_sub(s21_decimal value_1, s21_decimal value_2,
            s21_decimal *result);  // Вычитание
int s21_mul(s21_decimal value_1, s21_decimal value_2,
            s21_decimal *result);  // Умножение
int s21_div(s21_decimal value_1, s21_decimal value_2,
            s21_decimal *result);  // Деление

int s21_is_less(s21_decimal value_1, s21_decimal value_2);  // Меньше
int s21_is_less_or_equal(s21_decimal value_1,
                         s21_decimal value_2);  // Меньше или равно
int s21_is_greater(s21_decimal value_1, s21_decimal value_2);  // Больше
int s21_is_greater_or_equal(s21_decimal value_1,
                            s21_decimal value_2);  // Больше или равно
int s21_is_equal(s21_decimal value_1, s21_decimal value_2);      // Равно
int s21_is_not_equal(s21_decimal value_1, s21_decimal value_2);  // Не равно

int s21_from_int_to_decimal(int src, s21_decimal *dst);      // Из int
int s21_from_float_to_decimal(float src, s21_decimal *dst);  // Из float
int s21_from_decimal_to_int(s21_decimal src, int *dst);      // В int
int s21_from_decimal_to_float(s21_decimal src, float *dst);  // В float

int s21_floor(s21_decimal value,
              s21_decimal *result);  // Округляет до ближайшего целого числа в
                                     // сторону отрицательной бесконечности
int s21_round(s21_decimal value,
              s21_decimal *result);  // Округляет до ближайшего целого числа
int s21_truncate(
    s21_decimal value,
    s21_decimal *result);  // Возвращает целые цифры Decimal; любые дробные
                           // цифры отбрасываются, включая конечные нули
int s21_negate(
    s21_decimal value,
    s21_decimal *result);  // Возвращает результат умножения Decimal на -1

s21_decimal init(unsigned sign, unsigned exp, unsigned senior, unsigned middle,
                 unsigned junior);

unsigned set_bit(unsigned mantissa, unsigned position, unsigned bit);
unsigned get_bit(unsigned mantissa, unsigned position);

unsigned set_exp(unsigned mantissa, unsigned exp);
unsigned get_exp(unsigned mantissa);

unsigned set_sign(unsigned mantissa, unsigned sign);
unsigned get_sign(unsigned mantissa);

void print_decimal(s21_decimal val);
void print_decimal_to_float(s21_decimal value_1);

int is_decimal_not_zero(s21_decimal decimal);
int decimal_shift(s21_decimal *decimal, int shift);

int normalize(s21_decimal *decimal_one, s21_decimal *decimal_two);

int mul_for_normalize(s21_decimal *value_1);
int add_for_normalize(s21_decimal value_1, s21_decimal value_2,
                      s21_decimal *result);

int add_mantiss(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
void print_decimal_dec(s21_decimal val);

int get_senior_position_bit(s21_decimal val);
int div_ten(s21_decimal *value);
int big_div_ten(ass_21_big_dickcimal *value);
int is_valid(unsigned mantissa);
void trash_zero(s21_decimal *value);

int dec_to_reversed_code(s21_decimal *decimal);
int is_less_or_equal_for_div(s21_decimal value_1, s21_decimal value_2);
void set_bit_by_jonnelle(s21_decimal *value, unsigned num_bit, unsigned bit);
void print_decimal_hex(s21_decimal val);
int mul_for_ass_21_big_dickcimal(s21_decimal value_1, s21_decimal value_2,
                                 s21_decimal *result);
void add_mantiss_for_ass_21_big_dickcimal(ass_21_big_dickcimal value_1,
                                          ass_21_big_dickcimal value_2,
                                          ass_21_big_dickcimal *result);
void decimal_shift_for_ass_21_big_dickcimal(ass_21_big_dickcimal *decimal,
                                            int shift);
int cutting_ass_21_big_dickcimal(ass_21_big_dickcimal big_result,
                                 s21_decimal *result, int res);
int is_not_zero_ass_21_big_dickcimal(ass_21_big_dickcimal big_result);
void div_for_ass_21_big_dickcimal(s21_decimal *value_1, s21_decimal value_2,
                                  s21_decimal *result, int negative_exp);
int is_less_or_equal_for_div_for_ass_21_big_dickcimal(
    ass_21_big_dickcimal value_1, ass_21_big_dickcimal value_2);
void mul_on_ten_ass_21_big_dickcimal(ass_21_big_dickcimal *value_1);
void ass_21_big_dickcimal_to_reversed_code(ass_21_big_dickcimal *decimal);
void print_dickcimal(ass_21_big_dickcimal val);
int div_ten_for_add(s21_decimal *value);

#endif