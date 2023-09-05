#include "s21_math.h"

int s21_abs(int x) {
  int abs = x;
  if (x < 0) {
    abs = -x;
  }
  return abs;
}

long double s21_acos(double x) {
  long double acos = 0;
  if (x == 1) {
    acos = 0;
  } else if (0 <= x && x <= 1) {
    acos = s21_atan(s21_sqrt(1 - s21_pow(x, 2)) / x);
  } else if (-1 <= x && x < 0) {
    acos = S21_PI + s21_atan(s21_sqrt(1 - s21_pow(x, 2)) / x);
  } else {
    acos = S21_NAN;
  }
  return acos;
}

long double s21_asin(double x) {
  long double asin = 0;
  if (s21_fabs(x) <= 1) {
    asin = s21_atan(x / s21_sqrt(1 - s21_pow(x, 2)));
  } else {
    asin = S21_NAN;
  }
  return asin;
}

long double s21_atan(double x) {
  long double atan = 0;
  long double add = 1;
  int flag = 0;
  if (x == -S21_INFINITY) {
    atan = -S21_PI / 2;
    flag = 1;
  }
  if (x != x) {
    atan = S21_NAN;
    flag = 1;
  }
  if (s21_fabs(x) < 1 && flag == 0) {
    for (int i = 0; s21_fabs(add) > S21_EPS; i++) {
      add = (s21_pow(-1, i) * s21_pow(x, (1 + 2 * i))) / (1 + 2 * i);
      atan += add;
    }
  } else if (s21_fabs(x) > 1 && flag == 0) {
    for (int i = 0; s21_fabs(add) > S21_EPS; i++) {
      add = (s21_pow(-1, i) * s21_pow(x, (-1 - 2 * i))) / (1 + 2 * i);
      atan += add;
    }
    if (x < 0) {
      atan = -S21_PI / 2 - atan;
    } else {
      atan = S21_PI / 2 - atan;
    }

  } else if (x == 1) {
    atan = 0.785398;
  } else if (x == -1) {
    atan = -0.785398;
  }
  return atan;
}

long double s21_ceil(double x) {
  long double ceil = 0;
  int flag = 0;
  if (x != x) {
    ceil = S21_NAN;
    flag = 1;
  }
  if (x == -S21_INFINITY) {
    ceil = -S21_INFINITY;
    flag = 1;
  }
  if (x == S21_INFINITY) {
    ceil = S21_INFINITY;
    flag = 1;
  }
  if ((x - (int)x) != 0 && flag == 0) {
    if (x < 0) {
      ceil = (int)x;
    } else {
      ceil = (int)x + 1;
    }
  } else {
    ceil = x;
  }
  return ceil;
}

long double s21_cos(double x) {
  long double cos = 1;
  long double add = 1.;
  long double count = x;
  int flag = 0;
  if (s21_fabs(x) == S21_INFINITY) {
    cos = S21_NAN;
    flag = 1;
  }
  if (x == 0) {
    cos = 1;
    flag = 1;
  }
  while (s21_fabs(count) > 2 * S21_PI && flag == 0) {
    if (count < 0) {
      count = count + 2 * S21_PI;
    } else {
      count = count - 2 * S21_PI;
    }

    continue;
  }
  long double n = 0;
  for (; s21_fabs(add) > S21_EPS && flag == 0;) {
    add = (-add) * count * count / ((n + 2.) * (n + 1.));
    n += 2.;
    cos += add;
  }
  return cos;
}

long double s21_exp(double x) {
  long double exp = 1;
  long double i = 1;
  long double add = 1;
  int flag = 0;
  int minus = 0;
  if (x == 0) {
    exp = 1;
    flag = 1;
  }
  if (x == S21_INFINITY || x > 709.7827) {
    exp = S21_INFINITY;
    flag = 1;
  }
  if (x == -S21_INFINITY || x < -15) {
    exp = 0;
    flag = 1;
  }
  if (x < 0 && flag == 0) {
    x = -x;
    minus = 1;
  }
  while (s21_fabs(add) > S21_EPS && flag == 0) {
    add *= x / i;
    i++;
    exp += add;
  }
  if (minus == 1) {
    exp = 1.0 / exp;
  }
  return exp;
}

long double s21_fabs(double x) {
  long double fabs = x;
  int flag = 0;
  if (x != x) {
    fabs = S21_NAN;
    flag = 1;
  }
  if (x < 0 && flag == 0) {
    fabs *= -1;
  } else if (flag == 0) {
    fabs = x;
  }
  return fabs;
}

long double s21_floor(double x) {
  long double floor = (int)x;
  int flag = 0;
  if (x != x) {
    floor = S21_NAN;
    flag = 1;
  }
  if (x == S21_INFINITY) {
    floor = S21_INFINITY;
    flag = 1;
  }
  if (x == -S21_INFINITY) {
    floor = -S21_INFINITY;
    flag = 1;
  }
  if (x - (int)x != 0 && flag == 0) {
    if (x < 0) {
      floor = (int)x - 1;
    } else {
      floor = (int)x;
    }
  }
  return floor;
}

long double s21_fmod(double x, double y) {
  long double fmod = x;
  int flag = 0;
  if ((x != x || y != y) || (x == 0 && y == 0) || (s21_fabs(y) < S21_EPS) ||
      (s21_fabs(x) == S21_INFINITY && s21_fabs(y) == S21_INFINITY)) {
    fmod = S21_NAN;
    flag = 1;
  } else if (s21_fabs(y) == S21_INFINITY) {
    fmod = x;
    flag = 1;
  } else if (x == 0) {
    fmod = 0;
    flag = 1;
  }
  if (flag == 0) {
    int n = x / y;
    fmod = (long double)x - n * (long double)y;
  }
  return fmod;
}

long double s21_log(double x) {
  int count = 0;
  long double log = 0;
  long double com = 0;
  int flag = 0;
  if (x == 0) {
    log = -S21_INFINITY;
    flag = 1;
  }
  if (x == S21_INFINITY) {
    log = S21_INFINITY;
    flag = 1;
  }
  if (x < 0) {
    log = S21_NAN;
    flag = 1;
  }
  for (; x >= S21_EXP && flag == 0; x /= S21_EXP, count++) {
    continue;
  }
  for (int i = 0; i < 10000 && flag == 0; i++) {
    com = log;
    log = com + 2 * (x - s21_exp(com)) / (x + s21_exp(com));
  }
  return (log + count);
}

long double s21_pow(double base, double exp) {
  long double pow = base;
  int flag = 0;
  if (exp == 0) {
    pow = 1.;
    flag = 1;
  }

  if (base == -S21_INFINITY && exp == -S21_INFINITY) {
    pow = 0;
    flag = 1;
  }
  if (base < 0 && flag == 0) {
    pow = s21_exp(exp * s21_log(s21_fabs(base)));
    if (s21_fmod(exp, 2) != 0) {
      pow = -pow;
    }
    if (exp == -S21_INFINITY) {
      pow = S21_INFINITY;
    }
  } else if (flag == 0) {
    pow = s21_exp(exp * s21_log(base));
  }
  if (base == 1) {
    pow = 1;
  }
  return pow;
}

long double s21_sin(double x) {
  long double sin = x;
  long double add = x;
  long double count = x;
  int flag = 0;
  if (s21_fabs(x) == S21_INFINITY) {
    sin = S21_NAN;
    flag = 1;
  }
  while (s21_fabs(sin) > 2 * S21_PI && flag == 0) {
    if (sin < 0) {
      sin = sin + 2 * S21_PI;
    } else {
      sin = sin - 2 * S21_PI;
    }
    count = sin;
    add = sin;
    continue;
  }
  long double n = 1;
  for (; s21_fabs(add) > S21_EPS && flag == 0;) {
    add = (-add) * count * count / ((n + 2.) * (n + 1.));
    n += 2.;
    sin += add;
  }
  return sin;
}

long double s21_sqrt(double x) {
  long double mid = 0.;
  long double left = 0.;
  long double right = x;
  if (x < 1) {
    right = 1;
  }
  int flag = 0;
  mid = (left + right) / 2.;
  if (x < 0) {
    mid = S21_NAN;
    flag = 1;
  } else if (x == 0) {
    mid = 0;
    flag = 1;
  } else if (x == S21_INFINITY) {
    mid = S21_INFINITY;
    flag = 1;
  }
  while ((mid - left) > S21_EPS && flag == 0) {
    if (mid * mid > x) {
      right = mid;
    } else {
      left = mid;
    }
    mid = (left + right) / 2.;
  }
  return mid;
}

long double s21_tan(double x) { return (long double)s21_sin(x) / s21_cos(x); }
