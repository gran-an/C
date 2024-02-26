#include "headers/s21_calc.h"

char *dijkstra_algorithm(char *input) {
  Node *stack_char = NULL;
  static char str_out[256];
  int index = 0, len = strlen(input);
  if (validation(input)) {
    return "Error";
  }
  if (input[0] == '-' || input[0] == '+') {
    str_out[index] = '0';
    str_out[index + 1] = ',';
    index += 2;
  }
  for (int i = 0; i < len; i++) {  // array cycle
    if ((isNumber(input[i])) || input[i] == '.') {
      str_out[index] = input[i];
      index++;
      if ((input[i + 1] < 48 || input[i + 1] > 57) &&
          input[i + 1] != '.') {  // number check
        str_out[index] = ',';
        index++;
      }
      if (input[i + 1] == '(') {  // multiply before the bracket
        while (!isEmpty(stack_char) && (peek_prior(stack_char) >= 3)) {
          str_out[index] = pop_char(&stack_char);
          index++;
        }
        push(&stack_char, '*', 3);
      }
    } else if (input[i] == '(') {  // verification opening bracket
      if (input[i + 1] == '-' || input[i + 1] == '+') {
        str_out[index] = '0';
        str_out[index + 1] = ',';
        index += 2;
      }
      push(&stack_char, input[i], priority(input[i]));
    } else if (input[i] == ')') {  // verification closing bracket
      while (!isEmpty(stack_char) && stack_char->oper != '(') {
        str_out[index] = pop_char(&stack_char);
        index++;
      }
      pop_char(&stack_char);
    } else if (input[i] >= 97 && input[i] <= 116 && input[i] != 109) {
      push(&stack_char, trigonometry(input[i], input[i + 1]), 4);
      while (input[i + 1] != '(') {  // find end triginometry function
        i++;
      }
    } else if (input[i] == 'X' || input[i] == 'x') {  // variable 'X'
      str_out[index] = 'x';
      index++;
    } else if (priority(input[i]) > 1) {  // verification mathematical symbol
      int prior_in = priority(input[i]);
      while (!isEmpty(stack_char) && peek_prior(stack_char) >= prior_in) {
        str_out[index] = pop_char(&stack_char);
        index++;
      }
      push(&stack_char, input[i], prior_in);
      if (input[i + 2] == 'd') {
        i += 2;
      }
    }
  }
  while (!isEmpty(stack_char)) {
    str_out[index] = pop_char(&stack_char);
    index++;
  }
  str_out[index] = '\0';
  return str_out;
}

Data calculation(char *input, Data x_value) {
  char *str_out = dijkstra_algorithm(input);
  Node *stack_calc = NULL;
  Data calc = 0;
  static char buff_numb[256];
  int index = 0;
  int len = strlen(str_out);
  if (!strcmp(str_out, "Error")) {
    return NAN;
  }
  for (int i = 0; i < len; i++) {
    if ((str_out[i] >= 48 && str_out[i] <= 57)) {
      while (str_out[i] != ',') {
        buff_numb[index] = str_out[i];
        i++;
        index++;
      }
      push_data(&stack_calc, atof(buff_numb));
      memset(&buff_numb, '\0', 256);
      index = 0;
    } else if (str_out[i] >= 65 && str_out[i] <= 73) {
      push_data(&stack_calc,
                calc_trigonometry(str_out[i], pop_data(&stack_calc)));
    } else if (priority(str_out[i]) > 1) {
      Data value_2 = pop_data(&stack_calc);
      Data value_1 = pop_data(&stack_calc);
      push_data(&stack_calc, calc_math(value_2, value_1, str_out[i]));
    } else if (str_out[i] == 'x') {
      push_data(&stack_calc, x_value);
    }
  }
  calc = pop_data(&stack_calc);
  return calc;
}

int priority(char oper) {
  int prior = 0;
  if (oper == '(' || oper == ')' || oper == '.') {
    prior = 1;
  } else if (oper == '+' || oper == '-') {
    prior = 2;
  } else if (oper == '*' || oper == '/' || oper == 'm' || oper == '%') {
    prior = 3;
  } else if (oper == '^') {
    prior = 5;
  } else {
    prior = -1;
  }
  return prior;
}

char trigonometry(char input_1, char input_2) {
  char output;
  char buff[3] = {'\0'};
  buff[0] = input_1;
  buff[1] = input_2;
  if (!strcmp(buff, "co")) {  // cosine
    output = 'A';
  } else if (!strcmp(buff, "si")) {  // sine
    output = 'B';
  } else if (!strcmp(buff, "ta")) {  // tangent
    output = 'C';
  } else if (!strcmp(buff, "ac")) {  // arccosine
    output = 'D';
  } else if (!strcmp(buff, "as")) {  // arcsine
    output = 'E';
  } else if (!strcmp(buff, "at")) {  // arctangent
    output = 'F';
  } else if (!strcmp(buff, "sq")) {  // square
    output = 'G';
  } else if (!strcmp(buff, "ln")) {  // natural logorifm
    output = 'H';
  } else if (!strcmp(buff, "lo")) {  // decimal logorifm
    output = 'I';
  } else {
    output = 'R';
  }
  return output;
}

Data calc_trigonometry(char function, Data X) {
  Data res = 0;
  if (function == 'A') {
    res = cos(X);
  } else if (function == 'B') {
    res = sin(X);
  } else if (function == 'C') {
    res = tan(X);
  } else if (function == 'D') {
    res = acos(X);
  } else if (function == 'E') {
    res = asin(X);
  } else if (function == 'F') {
    res = atan(X);
  } else if (function == 'G') {
    res = sqrt(X);
  } else if (function == 'H') {
    res = log(X);
  } else if (function == 'I') {
    res = log10(X);
  }
  return res;
}

Data calc_math(Data value_2, Data value_1, char operand) {
  Data res = 0;
  if (operand == '+') {
    res = value_1 + value_2;
  } else if (operand == '-') {
    res = value_1 - value_2;
  } else if (operand == '*') {
    res = value_1 * value_2;
  } else if (operand == '/') {
    res = value_1 / value_2;
  } else if (operand == '^') {
    res = pow(value_1, value_2);
  } else if (operand == 'm' || operand == '%') {
    res = fmod(value_1, value_2);
  }
  return res;
}

int validation(char *input) {
  int res = 0, len = strlen(input), flag_bracket_open = 0,
      flag_bracket_closet = 0;
  if (priority(input[0]) > 2) {
    res = 1;
  }
  for (int i = 0; i < len; i++) {
    if (input[i] == '(') {
      flag_bracket_open++;
    } else if (input[i] == ')') {
      flag_bracket_closet++;
    }
    if ((i + 1) < len && trigonometry(input[i], input[i + 1]) == 'R' &&
        priority(input[i]) == -1 && !isNumber(input[i]) && input[i] != 'x' &&
        input[i] != 'X') {
      res = 1;
      break;
    } else if ((i + 1) >= len && input[i] != ')' && !isNumber(input[i]) &&
               input[i] != 'x' && input[i] != 'X') {
      res = 1;
      break;
    } else if ((priority(input[i]) > 1 && priority(input[i + 1]) > 1)) {
      res = 1;
      break;
    } else if ((i + 1) < len && input[i] == '(' && input[i + 1] == ')') {
      res = 1;
      break;
    } else if ((i + 1) < len && trigonometry(input[i], input[i + 1]) != 'R') {
      while (input[i + 1] != '(') {
        i++;
      }
    } else if (priority(input[i]) > 1) {
      if (input[i + 2] == 'd') {
        i += 2;
      }
    }
  }
  if (flag_bracket_closet != flag_bracket_open || len == 0) {
    res = 1;
  }
  return res;
}

int isNumber(char input_1) {
  int res = 0;
  if (input_1 >= 48 && input_1 <= 57) {
    res = 1;
  }
  return res;
}
