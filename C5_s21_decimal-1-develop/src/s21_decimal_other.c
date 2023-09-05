#include "s21_decimal.h"

/* проверяет заполненность нулями неиспользуемых битов и степень макс 28 */
int is_valid(unsigned mantissa) {
  int valid = 1;
  unsigned exp = get_exp(mantissa);

  if (exp > 28)
    valid = 0;
  else {
    for (unsigned bit = 0; bit < BITS_COUNT - 1; bit++) {
      if ((bit < 16 or bit > 23) and get_bit(mantissa, bit)) {
        valid = 0;
        break;
      }
    }
  }

  return valid;
}

/* Не равно */
int s21_is_not_equal(s21_decimal value_1, s21_decimal value_2) {
  int not_equal = 0;

  unsigned sign_1 = get_sign(value_1.bits[3]);
  unsigned sign_2 = get_sign(value_2.bits[3]);

  unsigned exp_1 = get_exp(value_1.bits[3]);
  unsigned exp_2 = get_exp(value_2.bits[3]);

  if (exp_1 < exp_2)
    normalize(&value_1, &value_2);
  else if (exp_2 < exp_1)
    normalize(&value_2, &value_1);

  if (sign_1 != sign_2)
    not_equal = 1;
  else {
    for (int mantissa = 2; mantissa >= 0; mantissa--) {
      if (value_1.bits[mantissa] != value_2.bits[mantissa]) {
        not_equal = 1;
        break;
      }
    }
  }

  return not_equal;
}

/* Равно */
int s21_is_equal(s21_decimal value_1, s21_decimal value_2) {
  int equal = 0;

  unsigned sign_1 = get_sign(value_1.bits[3]);
  unsigned sign_2 = get_sign(value_2.bits[3]);

  unsigned exp_1 = get_exp(value_1.bits[3]);
  unsigned exp_2 = get_exp(value_2.bits[3]);

  if (exp_1 < exp_2)
    normalize(&value_1, &value_2);
  else if (exp_2 < exp_1)
    normalize(&value_2, &value_1);

  if (sign_1 == sign_2) {
    equal = 1;
    for (int mantissa = 2; mantissa >= 0; mantissa--) {
      if (value_1.bits[mantissa] != value_2.bits[mantissa]) {
        equal = 0;
        break;
      }
    }
  }

  return equal;
}

/* Больше */
int s21_is_greater(s21_decimal value_1, s21_decimal value_2) {
  int greater = 0;

  unsigned sign_1 = get_sign(value_1.bits[3]);
  unsigned sign_2 = get_sign(value_2.bits[3]);

  unsigned exp_1 = get_exp(value_1.bits[3]);
  unsigned exp_2 = get_exp(value_2.bits[3]);

  if (sign_1 < sign_2)
    greater = 1;
  else if (sign_1 > sign_2)
    greater = 0;
  else {
    if (exp_1 < exp_2)
      normalize(&value_1, &value_2);
    else if (exp_2 < exp_1)
      normalize(&value_2, &value_1);

    for (int mantissa = 2; mantissa >= 0; mantissa--) {
      if (value_1.bits[mantissa] > value_2.bits[mantissa]) {
        if (sign_1 and sign_2)
          greater = 0;
        else
          greater = 1;
        break;
      } else if (value_1.bits[mantissa] < value_2.bits[mantissa]) {
        if (sign_1 and sign_2)
          greater = 1;
        else
          greater = 0;
        break;
      }
    }
  }

  return greater;
}

/* Меньше */
int s21_is_less(s21_decimal value_1, s21_decimal value_2) {
  int less = 0;

  unsigned sign_1 = get_sign(value_1.bits[3]);
  unsigned sign_2 = get_sign(value_2.bits[3]);

  unsigned exp_1 = get_exp(value_1.bits[3]);
  unsigned exp_2 = get_exp(value_2.bits[3]);

  if (sign_1 > sign_2)
    less = 1;
  else if (sign_1 < sign_2)
    less = 0;
  else {
    if (exp_1 < exp_2)
      normalize(&value_1, &value_2);
    else if (exp_2 < exp_1)
      normalize(&value_2, &value_1);

    for (int mantissa = 2; mantissa >= 0; mantissa--) {
      if (value_1.bits[mantissa] < value_2.bits[mantissa]) {
        if (sign_1 and sign_2)
          less = 0;
        else
          less = 1;
        break;
      } else if (value_1.bits[mantissa] > value_2.bits[mantissa]) {
        if (sign_1 and sign_2)
          less = 1;
        else
          less = 0;
        break;
      }
    }
  }

  return less;
}

/* Больше или равно */
int s21_is_greater_or_equal(s21_decimal value_1, s21_decimal value_2) {
  int greater = 1;

  unsigned sign_1 = get_sign(value_1.bits[3]);
  unsigned sign_2 = get_sign(value_2.bits[3]);

  unsigned exp_1 = get_exp(value_1.bits[3]);
  unsigned exp_2 = get_exp(value_2.bits[3]);

  if (sign_1 < sign_2)
    greater = 1;
  else if (sign_1 > sign_2)
    greater = 0;
  else {
    if (exp_1 < exp_2)
      normalize(&value_1, &value_2);
    else if (exp_2 < exp_1)
      normalize(&value_2, &value_1);

    for (int mantissa = 2; mantissa >= 0; mantissa--) {
      if (value_1.bits[mantissa] > value_2.bits[mantissa]) {
        if (sign_1 and sign_2)
          greater = 0;
        else
          greater = 1;
        break;
      } else if (value_1.bits[mantissa] < value_2.bits[mantissa]) {
        if (sign_1 and sign_2)
          greater = 1;
        else
          greater = 0;
        break;
      }
    }
  }

  return greater;
}

/* Меньше или равно */
int s21_is_less_or_equal(s21_decimal value_1, s21_decimal value_2) {
  int less = 1;

  unsigned sign_1 = get_sign(value_1.bits[3]);
  unsigned sign_2 = get_sign(value_2.bits[3]);

  unsigned exp_1 = get_exp(value_1.bits[3]);
  unsigned exp_2 = get_exp(value_2.bits[3]);

  if (sign_1 > sign_2)
    less = 1;
  else if (sign_1 < sign_2)
    less = 0;
  else {
    if (exp_1 < exp_2)
      normalize(&value_1, &value_2);
    else if (exp_2 < exp_1)
      normalize(&value_2, &value_1);

    for (int mantissa = 2; mantissa >= 0; mantissa--) {
      if (value_1.bits[mantissa] < value_2.bits[mantissa]) {
        if (sign_1 and sign_2)
          less = 0;
        else
          less = 1;
        break;
      } else if (value_1.bits[mantissa] > value_2.bits[mantissa]) {
        if (sign_1 and sign_2)
          less = 1;
        else
          less = 0;
        break;
      }
    }
  }

  return less;
}

/* Из int */
int s21_from_int_to_decimal(int src, s21_decimal *dst) {
  *dst = init(0, 0, 0, 0, 0);
  unsigned source = 0;
  int sign = get_sign(src);

  if (sign == 1) {
    source = src;
    source = ~(src) + 1;
  } else if (sign == 0)
    source = src;

  for (int num_bit = 0; num_bit < BITS_COUNT - 1; num_bit++) {
    int bit = get_bit(source, num_bit);
    dst->bits[0] = set_bit(dst->bits[0], num_bit, bit);
  }
  dst->bits[3] = set_sign(dst->bits[3], sign);

  return 0;
}

/* В int */
int s21_from_decimal_to_int(s21_decimal src, int *dst) {
  int return_code = 0;

  if (is_valid(src.bits[3])) {
    *dst = 0;
    int exp = get_exp(src.bits[3]);
    int sign = get_sign(src.bits[3]);

    while (exp != 0) {
      div_ten(&src);
      exp--;
    }

    if (get_senior_position_bit(src) > 30)
      return_code = 1;
    else {
      *dst = src.bits[0];
      if (sign) *dst = -*dst;
    }
  } else
    return_code = 1;

  return return_code;
}

/* возвращает номер позиции старшего бита (0-95) */
int get_senior_position_bit(s21_decimal val) {
  int senior_bit = -1;
  int is_found = 0;

  for (int mantissa = 2; mantissa >= 0; mantissa--) {
    for (int num_bit = BITS_COUNT - 1; num_bit >= 0; num_bit--) {
      if (get_bit(val.bits[mantissa], num_bit)) {
        senior_bit = num_bit + mantissa * BITS_COUNT;
        is_found = 1;
        break;
      }
    }
    if (is_found) break;
  }

  return senior_bit;
}

/* Из float */
int s21_from_float_to_decimal(float src, s21_decimal *dst) {
  *dst = init(0, 0, 0, 0, 0);
  char buf[15] = {0};
  int sign = 0;
  sprintf(buf, "%e", src);

  int cursor = 0;
  if (buf[cursor] == '-') {  // скан знака
    sign = 1;
    cursor++;
  }

  char mantissa[8] = {0};                        // для мантиссы
  for (int i = 0; buf[cursor] != 'e'; cursor++)  // скан мантиссы до e
    if (buf[cursor] != '.') mantissa[i++] = buf[cursor];

  cursor++;
  char exp[4] = {0};  // для экспоненты
  for (int i = 0; buf[cursor] != 0; cursor++, i++)  // скан экспоненты от е
    exp[i] = buf[cursor];

  int mant = atoi(mantissa);
  int expo = -atoi(exp) + 6;  // перевод мантиссы и экпоненты в int
  dst->bits[0] = mant;

  while (expo < 0)
    if (!mul_for_normalize(dst)) expo++;
  while (expo > 28)
    if (!div_ten(dst)) expo--;

  if (is_decimal_not_zero(*dst)) {
    dst->bits[3] = set_exp(dst->bits[3], expo);
    dst->bits[3] = set_sign(dst->bits[3], sign);
    trash_zero(dst);
  }

  return 0;
}

/* В float */
int s21_from_decimal_to_float(s21_decimal src, float *dst) {
  int return_code = 0;

  if (is_valid(src.bits[3])) {
    *dst = 0;
    int exp = get_exp(src.bits[3]);
    int sign = get_sign(src.bits[3]);

    for (int mantissa = 0; mantissa < 3; mantissa++)
      for (int num_bit = 0; num_bit < BITS_COUNT; num_bit++)
        if (get_bit(src.bits[mantissa], num_bit))
          *dst += pow(2, num_bit + mantissa * BITS_COUNT);

    while (exp) {
      *dst /= 10;
      exp--;
    }
    if (sign) *dst = -*dst;
  } else
    return_code = 1;

  return return_code;
}

/* Возвращает целые цифры; любые дробные цифры отбрасываются, включая конечные
 * нули */
int s21_truncate(s21_decimal value, s21_decimal *result) {
  int return_code = 0;

  if (is_valid(value.bits[3])) {
    *result = init(0, 0, 0, 0, 0);
    int exp = get_exp(value.bits[3]);
    int sign = get_sign(value.bits[3]);

    if (exp == 0)
      *result = value;
    else {
      value.bits[3] = 0;
      while (exp != 0) {
        div_ten(&value);
        exp--;
      }

      *result = value;
      result->bits[3] = set_sign(result->bits[3], sign);
    }
  } else
    return_code = 1;

  return return_code;
}

/* децимал/10 */
int div_ten(s21_decimal *value) {
  uint64_t ost_1 = 0, ost_2 = 0, ost_3 = 0;

  ost_1 = (value->bits[2] % 10) * ((uint64_t)UINT32_MAX + 1);
  ost_2 = ((ost_1 + value->bits[1]) % 10) * ((uint64_t)UINT32_MAX + 1);
  ost_3 = ((ost_2 + value->bits[0]) % 10);

  value->bits[2] /= 10;
  value->bits[1] = (ost_1 + value->bits[1]) / 10;
  value->bits[0] = (ost_2 + value->bits[0]) / 10;

  return ost_3;
}

/* биг децимал/10 */
int big_div_ten(ass_21_big_dickcimal *value) {
  uint64_t ost_1 = 0, ost_2 = 0, ost_3 = 0, ost_4 = 0, ost_5 = 0, ost_6 = 0;

  ost_1 = (value->bits[5] % 10) * ((uint64_t)UINT32_MAX + 1);
  ost_2 = ((ost_1 + value->bits[4]) % 10) * ((uint64_t)UINT32_MAX + 1);
  ost_3 = ((ost_2 + value->bits[3]) % 10) * ((uint64_t)UINT32_MAX + 1);
  ost_4 = ((ost_3 + value->bits[2]) % 10) * ((uint64_t)UINT32_MAX + 1);
  ost_5 = ((ost_4 + value->bits[1]) % 10) * ((uint64_t)UINT32_MAX + 1);
  ost_6 = ((ost_5 + value->bits[0]) % 10);

  value->bits[5] /= 10;
  value->bits[4] = (ost_1 + value->bits[4]) / 10;
  value->bits[3] = (ost_2 + value->bits[3]) / 10;
  value->bits[2] = (ost_3 + value->bits[2]) / 10;
  value->bits[1] = (ost_4 + value->bits[1]) / 10;
  value->bits[0] = (ost_5 + value->bits[0]) / 10;

  return ost_6;
}

/* Удаляет лишние нули в конце */
void trash_zero(s21_decimal *value) {
  int exp = get_exp(value->bits[3]);
  int sign = get_sign(value->bits[3]);

  while (exp and value->bits[0] % 10 == 0 and value->bits[0]) {
    value->bits[0] /= 10;
    exp--;
  }

  value->bits[3] = set_exp(value->bits[3], exp);
  value->bits[3] = set_sign(value->bits[3], sign);
}

/* Возвращает результат умножения Decimal на -1 */
int s21_negate(s21_decimal value, s21_decimal *result) {
  int return_code = 0;
  if (is_valid(value.bits[3])) {
    int sign = get_sign(value.bits[3]) ? 0 : 1;
    *result = value;
    result->bits[3] = set_sign(result->bits[3], sign);
  } else
    return_code = 1;

  return return_code;
}

/* Округляет до ближайшего целого числа */
int s21_round(s21_decimal value, s21_decimal *result) {
  int return_code = 0;
  if (is_valid(value.bits[3])) {
    *result = init(0, 0, 0, 0, 0);
    int exp = get_exp(value.bits[3]);
    int sign = get_sign(value.bits[3]);

    if (exp == 0)
      *result = value;
    else {
      value.bits[3] = 0;
      int ost = 0;
      while (exp != 0) {
        ost = div_ten(&value);
        exp--;
      }
      if (ost > 4) add_mantiss(value, init(0, 0, 0, 0, 1), &value);

      *result = value;
      result->bits[3] = set_sign(result->bits[3], sign);
    }
  } else
    return_code = 1;

  return return_code;
}

/* Округляет до ближайшего целого числа в сторону отрицательной бесконечности */
int s21_floor(s21_decimal value, s21_decimal *result) {
  int return_code = 0;
  if (is_valid(value.bits[3])) {
    *result = init(0, 0, 0, 0, 0);
    int exp = get_exp(value.bits[3]);
    int sign = get_sign(value.bits[3]);

    if (exp == 0)
      *result = value;
    else {
      value.bits[3] = 0;
      int ost = 0;
      while (exp != 0) {
        int tmp = 0;
        tmp = div_ten(&value);
        ost = tmp > ost ? tmp : ost;
        exp--;
      }
      if (ost > 0 and sign) add_mantiss(value, init(0, 0, 0, 0, 1), &value);

      *result = value;
      result->bits[3] = set_sign(result->bits[3], sign);
    }
  } else
    return_code = 1;

  return return_code;
}

/* Вычитание */
int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int return_code = 0;

  *result = init(0, 0, 0, 0, 0);
  unsigned sign_1 = get_sign(value_1.bits[3]);
  unsigned sign_2 = get_sign(value_2.bits[3]);

  if ((sign_1 + sign_2) % 2 == 0) {
    if (sign_1) {
      value_2.bits[3] = set_sign(value_2.bits[3], 0);
    } else {
      value_2.bits[3] = set_sign(value_2.bits[3], 1);
    }
  } else if ((sign_1 + sign_2) % 2 != 0) {
    if (sign_1) {
      value_2.bits[3] = set_sign(value_2.bits[3], 1);
    } else {
      value_2.bits[3] = set_sign(value_2.bits[3], 0);
    }
  }

  return_code = s21_add(value_1, value_2, result);

  return return_code;
}
