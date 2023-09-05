#include "s21_decimal.h"

void print_decimal_dec(s21_decimal val) {
  printf("%32u %32u %32u %32u\n", val.bits[3], val.bits[2], val.bits[1],
         val.bits[0]);
}

void print_decimal_hex(s21_decimal val) {
  printf("%#32X %#32X %#32X %#32X\n", val.bits[3], val.bits[2], val.bits[1],
         val.bits[0]);
}

/* удобная инициализация для тестов */
s21_decimal init(unsigned sign, unsigned exp, unsigned senior, unsigned middle,
                 unsigned junior) {
  s21_decimal num;
  num.bits[0] = junior;
  num.bits[1] = middle;
  num.bits[2] = senior;
  num.bits[3] = 0u;
  num.bits[3] = set_exp(num.bits[3], exp);
  num.bits[3] = set_sign(num.bits[3], sign);

  return num;
}

/* возвращет бит разряда position мантиссы */
unsigned get_bit(unsigned mantissa, unsigned position) {
  unsigned mask = 1u << position;
  unsigned bit = (mantissa & mask) >> position;
  return bit;
}

/* устанавливает bit (0 или 1) в разряд position мантиссы и возвращет её */
unsigned set_bit(unsigned mantissa, unsigned position, unsigned bit) {
  unsigned mask = bit ? 1u << position : ~(1u << position);
  mantissa = bit ? mantissa | mask : mantissa & mask;
  return mantissa;
}

/* возвращает степень мантиссы */
unsigned get_exp(unsigned mantissa) {
  mantissa = set_bit(mantissa, 31, 0);
  return mantissa >> 16;
}

/* задает степень мантиссы */
unsigned set_exp(unsigned mantissa, unsigned exp) {
  unsigned sign = get_sign(mantissa);
  exp = set_bit(exp, 31, sign);
  return exp << 16;
}

/* возвращает знак мантиссы */
unsigned get_sign(unsigned mantissa) { return get_bit(mantissa, 31); }

/* задает знак мантиссы */
unsigned set_sign(unsigned mantissa, unsigned sign) {
  return set_bit(mantissa, 31, sign);
}

/* Сложение */
int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int return_code = 0;
  *result = init(0, 0, 0, 0, 0);
  unsigned exp_1 = get_exp(value_1.bits[3]);
  unsigned exp_2 = get_exp(value_2.bits[3]);

  unsigned sign_1 = get_sign(value_1.bits[3]);
  unsigned sign_2 = get_sign(value_2.bits[3]);
  s21_decimal zero = {{0}};
  *result = zero;

  if (exp_1 != exp_2) {
    return_code = normalize(&value_1, &value_2);
    result->bits[3] = value_1.bits[3];
  }

  if (sign_1 != sign_2) {
    if (sign_1) {
      dec_to_reversed_code(&value_1);
    } else if (sign_2) {
      dec_to_reversed_code(&value_2);
    }
  }

  if (!return_code) return_code = add_mantiss(value_1, value_2, result);

  return return_code;
}

/* сложение только мантисс */
int add_mantiss(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int return_code = 0;
  int overflow = 0;

  for (unsigned mantissa = 0; mantissa < 3; mantissa++)
    for (unsigned num_bit = 0; num_bit < BITS_COUNT; num_bit++) {
      int bit_1 = get_bit(value_1.bits[mantissa], num_bit);
      int bit_2 = get_bit(value_2.bits[mantissa], num_bit);
      int sum = bit_1 + bit_2 + overflow;
      if (sum == 2) {
        overflow = 1;
        sum = 0;
      } else if (sum == 3) {
        overflow = 1;
        sum = 1;
      } else
        overflow = 0;
      result->bits[mantissa] = set_bit(result->bits[mantissa], num_bit, sum);
      if (num_bit == 31 && mantissa == 2 && overflow) return_code = 1;
    }
  if ((get_sign(value_1.bits[3]) + get_sign(value_2.bits[3])) % 2 == 0) {
    if (overflow && !get_exp(value_1.bits[3]))
      return_code = 1;
    else if (overflow && get_exp(result->bits[3])) {
      return_code = 0;
      int remainder = div_ten_for_add(result);
      s21_decimal result_for_remainder = *result;
      if (remainder >= 6 ||
          (remainder == 5 && div_ten(&result_for_remainder) % 2 != 0)) {
        s21_decimal one = {{1, 0, 0, result->bits[3]}};
        add_mantiss(*result, one, result);
      }
      result->bits[3] = set_exp(result->bits[3], get_exp(result->bits[3]) - 1);
    } else {
      result->bits[3] = set_exp(result->bits[3], get_exp(value_1.bits[3]));
    }
    if (get_sign(value_1.bits[3]) && get_sign(value_2.bits[3])) {
      result->bits[3] = set_sign(result->bits[3], 1);
    }
  } else if (!overflow &&
             (get_sign(value_1.bits[3]) + get_sign(value_2.bits[3])) % 2 != 0) {
    dec_to_reversed_code(result);
    result->bits[3] = set_sign(result->bits[3], 1);
  } else if (overflow &&
             (get_sign(value_1.bits[3]) + get_sign(value_2.bits[3])) % 2 != 0) {
    return_code = 0;
  }

  return return_code;
}

/* Умножение */
int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int return_code = 0;
  int negative = 0;
  *result = init(0, 0, 0, 0, 0);

  if ((get_sign(value_1.bits[3]) + get_sign(value_2.bits[3])) % 2 != 0) {
    negative = 1;
  }
  value_1.bits[3] = set_sign(value_1.bits[3], 0);
  value_2.bits[3] = set_sign(value_2.bits[3], 0);
  s21_decimal zero = {{0}};
  *result = zero;
  return_code = mul_for_ass_21_big_dickcimal(value_1, value_2, result);
  if (get_exp(result->bits[3]) > 28) {
    int remainder = 0;
    int exp_fin = get_exp(result->bits[3]);
    while (exp_fin > 28) {
      remainder = div_ten(result);
      exp_fin--;
    }
    if (is_decimal_not_zero(*result)) {
      s21_decimal temp_res_for_remainder = *result;
      if (remainder >= 6 ||
          (remainder == 5 && div_ten(&temp_res_for_remainder) % 2 != 0)) {
        s21_decimal just_one = {{1, 0, 0, 0}};
        add_mantiss(*result, just_one, result);
      }
    }
    result->bits[3] = set_exp(result->bits[3], exp_fin);
  }
  result->bits[3] = set_sign(result->bits[3], negative);
  return return_code;
}

int is_decimal_not_zero(s21_decimal decimal) {
  int value = 0;
  if (decimal.bits[0] != 0 || decimal.bits[1] != 0 || decimal.bits[2] != 0)
    value = 1;
  return value;
}

int decimal_shift(s21_decimal *decimal, int shift) {
  int overflow = 0;

  for (int i = 0; i < shift; i++) {
    if (decimal->bits[2] >> 31) {
      overflow = 1;
      break;
    }
    decimal->bits[2] <<= 1;
    if (decimal->bits[1] >> 31) {
      decimal->bits[2] = set_bit(decimal->bits[2], 0, 1);
    }
    decimal->bits[1] <<= 1;
    if (decimal->bits[0] >> 31) {
      decimal->bits[1] = set_bit(decimal->bits[1], 0, 1);
    }
    decimal->bits[0] <<= 1;
  }

  return overflow;
}

void print_decimal(s21_decimal val) {
  for (int mantissa = 3; mantissa >= 0; mantissa--) {
    for (int num_bit = BITS_COUNT - 1; num_bit >= 0; num_bit--) {
      printf("%u", get_bit(val.bits[mantissa], num_bit));
    }
    printf(" ");
  }
  printf("\n");
}

int normalize(s21_decimal *decimal_one, s21_decimal *decimal_two) {
  unsigned decimal_one_exp = get_exp(decimal_one->bits[3]);
  unsigned decimal_two_exp = get_exp(decimal_two->bits[3]);
  unsigned sign_1 = get_sign(decimal_one->bits[3]);
  unsigned sign_2 = get_sign(decimal_two->bits[3]);
  int return_code = 0;

  while (decimal_one_exp < decimal_two_exp && decimal_one_exp <= 28 &&
         !(decimal_one->bits[2] >> 29 & 0b111)) {
    mul_for_normalize(decimal_one);
    decimal_one_exp++;
  }

  while (decimal_two_exp < decimal_one_exp && decimal_two_exp <= 28 &&
         !(decimal_two->bits[2] >> 29 & 0b111)) {
    mul_for_normalize(decimal_two);
    decimal_two_exp++;
  }

  if (decimal_one_exp != decimal_two_exp) {
    int remainder_from_decimal_one = 0;
    while (decimal_one_exp > decimal_two_exp) {
      remainder_from_decimal_one = div_ten(decimal_one);
      decimal_one_exp--;
    }
    s21_decimal temp_res = *decimal_one;
    if (remainder_from_decimal_one >= 6 ||
        (div_ten(&temp_res) % 2 != 0 && remainder_from_decimal_one == 5)) {
      decimal_one->bits[0] += 1;
    }
    int remainder_from_decimal_two = 0;
    while (decimal_two_exp > decimal_one_exp) {
      remainder_from_decimal_two = div_ten(decimal_two);
      decimal_two_exp--;
    }
    s21_decimal temp_res_two = *decimal_one;
    if (remainder_from_decimal_two >= 6 ||
        (div_ten(&temp_res_two) % 2 != 0 && remainder_from_decimal_two == 5)) {
      decimal_two->bits[0] += 1;
    }
  }

  decimal_one->bits[3] = set_exp(decimal_one->bits[3], decimal_one_exp);
  decimal_two->bits[3] = set_exp(decimal_two->bits[3], decimal_two_exp);
  decimal_one->bits[3] = set_sign(decimal_one->bits[3], sign_1);
  decimal_two->bits[3] = set_sign(decimal_two->bits[3], sign_2);

  return return_code;
}

int mul_for_normalize(s21_decimal *value_1) {
  int return_code = 0;
  int ten = 10;
  s21_decimal temp = init(0, 0, 0, 0, 0);

  while (ten and !return_code) {
    if (ten & 1) add_for_normalize(temp, *value_1, &temp);
    return_code = decimal_shift(value_1, 1);
    ten >>= 1;
  }
  *value_1 = temp;

  return return_code;
}

int add_for_normalize(s21_decimal value_1, s21_decimal value_2,
                      s21_decimal *result) {
  int return_code = 0;
  int overflow = 0;

  for (unsigned mantissa = 0; mantissa < 3; mantissa++)
    for (unsigned num_bit = 0; num_bit < BITS_COUNT; num_bit++) {
      int bit_1 = get_bit(value_1.bits[mantissa], num_bit);
      int bit_2 = get_bit(value_2.bits[mantissa], num_bit);
      int sum = bit_1 + bit_2 + overflow;
      if (sum == 2) {
        overflow = 1;
        sum = 0;
      } else if (sum == 3) {
        overflow = 1;
        sum = 1;
      } else
        overflow = 0;
      result->bits[mantissa] = set_bit(result->bits[mantissa], num_bit, sum);
    }

  return return_code;
}

int dec_to_reversed_code(s21_decimal *decimal) {
  int overflow = 0;

  decimal->bits[0] = ~decimal->bits[0];
  if (decimal->bits[0] == 0b11111111111111111111111111111111) overflow = 1;
  decimal->bits[0] += 1;
  decimal->bits[1] = ~(decimal->bits[1]);
  int overflow_second_bits = 0;
  if (decimal->bits[0] == 0b11111111111111111111111111111111 && overflow)
    overflow_second_bits = 1;

  decimal->bits[1] += overflow;
  decimal->bits[2] = ~decimal->bits[2];
  decimal->bits[2] += overflow_second_bits;

  return 0;
}

int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  s21_decimal zero = {{0}};
  *result = zero;
  int return_code = 0;

  if (!is_decimal_not_zero(value_2)) {
    return_code = 3;
    return return_code;
  }
  unsigned sign_1 = get_sign(value_1.bits[3]);
  unsigned sign_2 = get_sign(value_2.bits[3]);
  int res_sign = (sign_1 + sign_2) % 2;
  if (res_sign)
    sign_1 ? (value_1.bits[3] = set_sign(value_1.bits[3], 0))
           : (value_2.bits[3] = set_sign(value_2.bits[3], 0));
  unsigned exp_1 = get_exp(value_1.bits[3]);
  unsigned exp_2 = get_exp(value_2.bits[3]);
  int exp_summ = exp_1 - exp_2;
  int negative_exp = 0;
  if (exp_summ < 0) negative_exp = -exp_summ;
  value_1.bits[3] = set_exp(value_1.bits[3], 0);
  value_2.bits[3] = set_exp(value_2.bits[3], 0);

  int shift_counter = 0;
  int res = 0;
  s21_decimal result_for_add = {{0}};
  int prelast_num_is_even = 0;
  div_for_ass_21_big_dickcimal(&value_1, value_2, result, negative_exp);
  int too_big_or_too_small = 0;

  if (negative_exp || exp_summ == 0) {
    if (is_decimal_not_zero(value_1)) {
      int counter = 0;
      while (!(res = is_less_or_equal_for_div(value_1, value_2)) &&
             !(value_1.bits[2] >> 28 & 0b1111)) {
        mul_for_normalize(&value_1);
        counter++;
      }
      if (counter < 2) {
        s21_decimal temp_value_2 = zero;
        while ((res = is_less_or_equal_for_div(value_1, value_2)) &&
               !(value_2.bits[2] >> 31)) {
          temp_value_2 = value_2;
          decimal_shift(&value_2, 1);
          shift_counter++;
        }
        value_2 = temp_value_2;
        shift_counter--;
        set_bit_by_jonnelle(&result_for_add, shift_counter, 1);

        s21_decimal res_for_remainder = *result;
        int remainder = div_ten(&res_for_remainder);
        if (remainder > 6 || (remainder == 5 && !prelast_num_is_even)) {
          s21_decimal just_one = {{1, 0, 0, 0}};
          add_mantiss(*result, just_one, result);
        }
      }
    }
    int exp_exp = get_exp(result->bits[3]);
    if (exp_exp >= negative_exp)
      result->bits[3] = set_exp(result->bits[3], exp_exp - negative_exp);
    else {
      while (exp_exp < negative_exp) {
        too_big_or_too_small = mul_for_normalize(result);
        exp_exp++;
      }
      if (!too_big_or_too_small) {
        result->bits[3] = set_exp(result->bits[3], exp_exp);
      } else {
        return_code = 1;
        too_big_or_too_small = 1;
      }
    }
  } else if (exp_summ > 0) {
    int remainder = 0;
    while (exp_summ > 0) {
      remainder = div_ten(result);
      exp_summ--;
    }
    if (is_decimal_not_zero(*result)) {
      s21_decimal temp_res_for_remainder = *result;
      if (remainder >= 6 ||
          (remainder == 5 && div_ten(&temp_res_for_remainder) % 2 != 0)) {
        s21_decimal just_one = {{1, 0, 0, 0}};
        add_mantiss(*result, just_one, result);
      }
    } else if (!is_decimal_not_zero(*result)) {
      too_big_or_too_small = 1;
      return_code = 2;
    }
  }
  if ((sign_1 + sign_2) % 2 != 0)
    result->bits[3] = set_sign(result->bits[3], 1);
  else
    result->bits[3] = set_sign(result->bits[3], 0);
  if (too_big_or_too_small) *result = zero;
  return return_code;
}

int is_less_or_equal_for_div(s21_decimal value_1, s21_decimal value_2) {
  int less = 2;
  for (int mantissa = 2; mantissa >= 0; mantissa--) {
    if (value_1.bits[mantissa] < value_2.bits[mantissa]) {
      less = 0;
      break;
    } else if (value_1.bits[mantissa] > value_2.bits[mantissa]) {
      less = 1;
      break;
    }
  }
  return less;
}

void set_bit_by_jonnelle(s21_decimal *value, unsigned num_bit, unsigned bit) {
  int num_mant = 0, num_bit_in_mant = 0;
  if (num_bit > 31 && num_bit <= 63) {
    num_mant = 1;
    num_bit_in_mant = num_bit - 32;
  } else if (num_bit > 63) {
    num_mant = 2;
    num_bit_in_mant = num_bit - 64;
  } else {
    num_bit_in_mant = num_bit;
  }

  value->bits[num_mant] = set_bit(value->bits[num_mant], num_bit_in_mant, bit);
}

int mul_for_ass_21_big_dickcimal(s21_decimal value_1, s21_decimal value_2,
                                 s21_decimal *result) {
  int return_code = 0;
  ass_21_big_dickcimal big_result = {{0, 0, 0, 0, 0, 0}};
  ass_21_big_dickcimal big_value_1 = {
      {value_1.bits[0], value_1.bits[1], value_1.bits[2], 0, 0, 0}};
  int num_bit = 0;
  int num_mant = 0;
  int num_bit_in_mant = 0;

  while (is_decimal_not_zero(value_2)) {
    if (num_bit > 31 && num_bit <= 63) {
      num_mant = 1;
      num_bit_in_mant = num_bit - 32;
    } else if (num_bit > 63) {
      num_mant = 2;
      num_bit_in_mant = num_bit - 64;
    } else {
      num_mant = 0;
      num_bit_in_mant = num_bit;
    }
    if (get_bit(value_2.bits[num_mant], num_bit_in_mant)) {
      add_mantiss_for_ass_21_big_dickcimal(big_result, big_value_1,
                                           &big_result);
    }
    decimal_shift_for_ass_21_big_dickcimal(&big_value_1, 1);
    value_2.bits[num_mant] =
        set_bit(value_2.bits[num_mant], num_bit_in_mant, 0);
    num_bit++;
  }

  int res_exp = get_exp(value_1.bits[3]) + get_exp(value_2.bits[3]);
  return_code = cutting_ass_21_big_dickcimal(big_result, result, res_exp);

  return return_code;
}

void add_mantiss_for_ass_21_big_dickcimal(ass_21_big_dickcimal value_1,
                                          ass_21_big_dickcimal value_2,
                                          ass_21_big_dickcimal *result) {
  int overflow = 0;

  for (unsigned mantissa = 0; mantissa < 6; mantissa++) {
    for (unsigned num_bit = 0; num_bit < BITS_COUNT; num_bit++) {
      int bit_1 = get_bit(value_1.bits[mantissa], num_bit);
      int bit_2 = get_bit(value_2.bits[mantissa], num_bit);
      int sum = bit_1 + bit_2 + overflow;
      if (sum == 2) {
        overflow = 1;
        sum = 0;
      } else if (sum == 3) {
        overflow = 1;
        sum = 1;
      } else
        overflow = 0;
      result->bits[mantissa] = set_bit(result->bits[mantissa], num_bit, sum);
    }
  }
}

void decimal_shift_for_ass_21_big_dickcimal(ass_21_big_dickcimal *decimal,
                                            int shift) {
  for (int i = 0; i < shift; i++) {
    decimal->bits[5] <<= 1;
    if (decimal->bits[4] >> 31) {
      decimal->bits[5] = set_bit(decimal->bits[5], 0, 1);
    }
    decimal->bits[4] <<= 1;
    if (decimal->bits[3] >> 31) {
      decimal->bits[4] = set_bit(decimal->bits[4], 0, 1);
    }
    decimal->bits[3] <<= 1;
    if (decimal->bits[2] >> 31) {
      decimal->bits[3] = set_bit(decimal->bits[3], 0, 1);
    }
    decimal->bits[2] <<= 1;
    if (decimal->bits[1] >> 31) {
      decimal->bits[2] = set_bit(decimal->bits[2], 0, 1);
    }
    decimal->bits[1] <<= 1;
    if (decimal->bits[0] >> 31) {
      decimal->bits[1] = set_bit(decimal->bits[1], 0, 1);
    }
    decimal->bits[0] <<= 1;
  }
}

int cutting_ass_21_big_dickcimal(ass_21_big_dickcimal big_result,
                                 s21_decimal *result, int res_exp) {
  int overflow = 0;
  int remainder = 0;
  ;

  while ((res_exp > 0 &&
          (big_result.bits[5] || big_result.bits[4] || big_result.bits[3])) &&
         is_not_zero_ass_21_big_dickcimal(big_result)) {
    remainder = big_div_ten(&big_result);
    res_exp--;
  }

  if (!res_exp &&
      (big_result.bits[5] || big_result.bits[4] || big_result.bits[3])) {
    overflow = 1;
  } else if (res_exp && !is_not_zero_ass_21_big_dickcimal(big_result)) {
    overflow = 2;
  }
  if (!overflow) {
    for (int i = 0; i < 3; i++) {
      result->bits[i] = big_result.bits[i];
    }
    s21_decimal temp_res = *result;
    if (remainder >= 6 || (div_ten(&temp_res) % 2 != 0 && remainder == 5))
      result->bits[0] += 1;
    s21_decimal temp_res_for_trash_zeros_deleting = *result;
    int stop_reducing = 0;
    while (res_exp > 0 && !stop_reducing) {
      if (div_ten(&temp_res_for_trash_zeros_deleting))
        stop_reducing = 1;
      else {
        div_ten(result);
        res_exp--;
      }
    }
    result->bits[3] = set_exp(result->bits[3], res_exp);
  }

  return overflow;
}

int is_not_zero_ass_21_big_dickcimal(ass_21_big_dickcimal big_result) {
  int this_num_is_not_zero = 0;
  if (big_result.bits[5] != 0 || big_result.bits[4] != 0 ||
      big_result.bits[3] != 0 || big_result.bits[2] != 0 ||
      big_result.bits[1] != 0 || big_result.bits[0] != 0)
    this_num_is_not_zero = 1;
  return this_num_is_not_zero;
}

void div_for_ass_21_big_dickcimal(s21_decimal *value_1, s21_decimal value_2,
                                  s21_decimal *result, int negative_exp) {
  ass_21_big_dickcimal big_value_1 = {
      {value_1->bits[0], value_1->bits[1], value_1->bits[2], 0, 0, 0}};
  ass_21_big_dickcimal big_value_2 = {
      {value_2.bits[0], value_2.bits[1], value_2.bits[2], 0, 0, 0}};
  int exp = 0;
  int stop = 0;
  s21_decimal result_for_add_b = {{0, 0, 0, 0}};
  ass_21_big_dickcimal reserv_big_value_2 = big_value_2;

  while ((((!negative_exp) ? exp < 28 : exp < 28) ||
          is_less_or_equal_for_div_for_ass_21_big_dickcimal(big_value_1,
                                                            big_value_2) ||
          !(result->bits[2] >> 29 & 0b111)) &&
         is_not_zero_ass_21_big_dickcimal(big_value_1) && !stop) {
    if (!is_less_or_equal_for_div_for_ass_21_big_dickcimal(big_value_1,
                                                           big_value_2) &&
        !stop) {
      ass_21_big_dickcimal reserv_big_value_1 = big_value_1;
      int res_exp = exp;
      while (!is_less_or_equal_for_div_for_ass_21_big_dickcimal(big_value_1,
                                                                big_value_2) &&
             ((!negative_exp) ? exp < 28 : exp <= 28)) {
        mul_on_ten_ass_21_big_dickcimal(&big_value_1);
        exp++;
        result_for_add_b.bits[3] = set_exp(result_for_add_b.bits[3], exp);
      }
      if (!is_less_or_equal_for_div_for_ass_21_big_dickcimal(big_value_1,
                                                             big_value_2) &&
          exp >= 28) {
        big_value_1 = reserv_big_value_1;
        result_for_add_b.bits[3] = set_exp(result_for_add_b.bits[3], res_exp);
        stop = 1;
      }
    }

    if (is_less_or_equal_for_div_for_ass_21_big_dickcimal(big_value_1,
                                                          big_value_2) &&
        !stop) {
      ass_21_big_dickcimal temp_value_b = {{0}};
      int shift_counter_b = 0;
      while (is_less_or_equal_for_div_for_ass_21_big_dickcimal(big_value_1,
                                                               big_value_2)) {
        temp_value_b = big_value_2;
        decimal_shift_for_ass_21_big_dickcimal(&big_value_2, 1);
        shift_counter_b++;
      }
      big_value_2 = temp_value_b;
      shift_counter_b--;
      ass_21_big_dickcimal_to_reversed_code(&big_value_2);
      add_mantiss_for_ass_21_big_dickcimal(big_value_1, big_value_2,
                                           &big_value_1);
      set_bit_by_jonnelle(&result_for_add_b, shift_counter_b, 1);
      if (!(get_exp(result_for_add_b.bits[3])))
        result_for_add_b.bits[3] =
            set_exp(result_for_add_b.bits[3], get_exp(result->bits[3]));
      s21_add(*result, result_for_add_b, result);
      s21_decimal zero = {{0, 0, 0, 0}};
      result_for_add_b = zero;
      big_value_2 = reserv_big_value_2;
      shift_counter_b = 0;
      result->bits[3] = set_exp(result->bits[3], exp);
    }
  }
  for (int i = 0; i < 3; i++) {
    value_1->bits[i] = big_value_1.bits[i];
  }
}

int is_less_or_equal_for_div_for_ass_21_big_dickcimal(
    ass_21_big_dickcimal value_1, ass_21_big_dickcimal value_2) {
  int less = 2;

  for (int mantissa = 5; mantissa >= 0; mantissa--) {
    if (value_1.bits[mantissa] < value_2.bits[mantissa]) {
      less = 0;
      break;
    } else if (value_1.bits[mantissa] > value_2.bits[mantissa]) {
      less = 1;
      break;
    }
  }

  return less;
}
void mul_on_ten_ass_21_big_dickcimal(ass_21_big_dickcimal *value_1) {
  int ten = 10;
  ass_21_big_dickcimal temp = {{0}};

  while (ten) {
    if (ten & 1) add_mantiss_for_ass_21_big_dickcimal(temp, *value_1, &temp);
    decimal_shift_for_ass_21_big_dickcimal(value_1, 1);
    ten >>= 1;
  }

  *value_1 = temp;
  ;
}

void ass_21_big_dickcimal_to_reversed_code(ass_21_big_dickcimal *decimal) {
  int overflow = 0;
  decimal->bits[0] = ~decimal->bits[0];
  if (decimal->bits[0] == 0b11111111111111111111111111111111) overflow = 1;
  decimal->bits[0] += 1;

  for (int i = 1; i < 6; i++) {
    decimal->bits[i] = ~decimal->bits[i];
    if (decimal->bits[i] == 0b11111111111111111111111111111111 && overflow) {
      decimal->bits[i] += overflow;
      overflow = 1;
    } else if (decimal->bits[i] != 0b11111111111111111111111111111111) {
      decimal->bits[i] += overflow;
      overflow = 0;
    }
  }
}

void print_dickcimal(ass_21_big_dickcimal val) {
  for (int mantissa = 5; mantissa >= 0; mantissa--) {
    for (int num_bit = BITS_COUNT - 1; num_bit >= 0; num_bit--) {
      printf("%u", get_bit(val.bits[mantissa], num_bit));
    }
    printf(" ");
  }
  printf("\n");
}

int div_ten_for_add(s21_decimal *value) {
  uint64_t ost_1 = 0, ost_2 = 0, ost_3 = 0;

  ost_1 = (((uint64_t)UINT32_MAX + 1 + value->bits[2]) % 10) *
          ((uint64_t)UINT32_MAX + 1);
  ost_2 = ((ost_1 + value->bits[1]) % 10) * ((uint64_t)UINT32_MAX + 1);
  ost_3 = ((ost_2 + value->bits[0]) % 10);

  value->bits[2] /= 10;
  value->bits[1] = (ost_1 + value->bits[1]) / 10;
  value->bits[0] = (ost_2 + value->bits[0]) / 10;

  return ost_3;
}