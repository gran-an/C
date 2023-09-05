#include "s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  int res = INCORRECT;
  if (rows > 0 && columns > 0) {
    double **matrix =
        calloc(rows * columns * sizeof(double) + rows * sizeof(double *), 1);
    if (matrix != NULL) {
      double *ptr = (double *)matrix + rows;
      for (int i = 0; i < rows; i++) {
        matrix[i] = ptr + columns * i;
      }
      result->columns = columns;
      result->rows = rows;
      result->matrix = matrix;
      res = OK;
    }
  }
  return res;
}

void s21_remove_matrix(matrix_t *A) {
  if (A->matrix) free(A->matrix);
  A->matrix = NULL;
  A->columns = 0;
  A->rows = 0;
}

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int res = SUCCESS;
  if (s21_empty(A) && s21_empty(B) && A->rows == B->rows &&
      A->columns == B->columns) {
    for (int i = 0; i < A->rows && res; i++) {
      for (int j = 0; j < A->columns && res; j++) {
        if (fabs(A->matrix[i][j] - B->matrix[i][j]) >= 1e-7) {
          res = FAILURE;
        }
      }
    }
  } else {
    res = FAILURE;
  }
  return res;
}

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int res = OK;
  if (!s21_empty(A) || !s21_empty(B)) {
    res = INCORRECT;
  } else if (A->rows == B->rows && A->columns == B->columns && res == OK) {
    res = s21_create_matrix(A->rows, A->columns, result);
    for (int i = 0; i < A->rows && !res; i++) {
      for (int j = 0; j < A->columns && !res; j++) {
        result->matrix[i][j] = A->matrix[i][j] + B->matrix[i][j];
      }
    }
  } else {
    res = ERROR;
  }
  return res;
}

int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int res = OK;
  if (!s21_empty(A) || !s21_empty(B)) {
    res = INCORRECT;
  } else if (A->rows == B->rows && A->columns == B->columns && res == OK) {
    res = s21_create_matrix(A->rows, A->columns, result);
    for (int i = 0; i < A->rows && !res; i++) {
      for (int j = 0; j < A->columns && !res; j++) {
        result->matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
      }
    }
  } else {
    res = ERROR;
  }
  return res;
}

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int res = OK;
  if (!s21_empty(A) || !s21_empty(B)) {
    res = INCORRECT;
  } else if (A->columns == B->rows) {
    res = s21_create_matrix(A->rows, B->columns, result);
    for (int i = 0; i < A->rows && !res; i++) {
      for (int j = 0; j < B->columns && !res; j++) {
        result->matrix[i][j] = 0;
        for (int k = 0; k < A->columns; k++) {
          result->matrix[i][j] += A->matrix[i][k] * B->matrix[k][j];
        }
      }
    }
  } else {
    res = ERROR;
  }
  return res;
}

int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  int res = OK;
  if (!s21_empty(A)) {
    res = INCORRECT;
  }
  if (!res) {
    res = s21_create_matrix(A->rows, A->columns, result);
    for (int i = 0; i < A->rows && !res; i++) {
      for (int j = 0; j < A->columns && !res; j++) {
        result->matrix[i][j] = A->matrix[i][j] * number;
      }
    }
  }
  return res;
}

int s21_transpose(matrix_t *A, matrix_t *result) {
  int res = OK;
  if (!s21_empty(A)) {
    res = INCORRECT;
  } else {
    res = s21_create_matrix(A->columns, A->rows, result);
    for (int i = 0; i < A->rows && !res; i++) {
      for (int j = 0; j < A->columns && !res; j++) {
        result->matrix[j][i] = A->matrix[i][j];
      }
    }
  }
  return res;
}

int s21_determinant(matrix_t *A, double *result) {
  int res = OK;
  if (!s21_empty(A)) {
    res = INCORRECT;
  } else if (A->columns != A->rows) {
    res = ERROR;
  } else {
    *result = s21_det_dop(A, A->rows);
  }
  return res;
}

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int res = OK;
  if (!s21_empty(A)) {
    res = INCORRECT;
  }
  if (A->rows == A->columns && A->rows != 1) {
    res = s21_create_matrix(A->rows, A->columns, result);
    for (int i = 0; i < A->rows && !res; i++) {
      for (int j = 0; j < A->columns && !res; j++) {
        matrix_t tmp = {0};
        int res = s21_create_matrix(A->rows, A->rows, &tmp);
        if (!res) {
          double det = 0;
          cofactor(A, &tmp, i, j, A->rows);
          s21_determinant(&tmp, &det);
          result->matrix[i][j] = pow(-1, (i + j)) * det;
          s21_remove_matrix(&tmp);
        }
      }
    }
  } else {
    res = ERROR;
  }
  return res;
}

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  int res = OK;
  double det = 0.0;
  s21_determinant(A, &det);
  if (!s21_empty(A)) {
    res = INCORRECT;
  } else if (A->rows == A->columns && fabs(det) > 1e-7) {
    matrix_t tmp = {0};
    matrix_t tmp_2 = {0};
    s21_calc_complements(A, &tmp);
    s21_transpose(&tmp, &tmp_2);
    s21_mult_number(&tmp_2, 1 / det, result);
    s21_remove_matrix(&tmp);
    s21_remove_matrix(&tmp_2);
  } else {
    res = ERROR;
  }
  return res;
}

int s21_empty(matrix_t *A) {
  int res = INCORRECT;
  if (A->matrix == NULL || A->rows <= 0 || A->columns <= 0) {
    res = OK;
  }
  return res;
}

double s21_det_dop(matrix_t *A, int n) {
  double determinant = 0;
  if (n == 1) {
    determinant = A->matrix[0][0];
  } else if (n == 2) {
    determinant =
        A->matrix[0][0] * A->matrix[1][1] - A->matrix[0][1] * A->matrix[1][0];
  } else if (n == 3) {
    determinant = A->matrix[0][0] * (A->matrix[1][1] * A->matrix[2][2] -
                                     A->matrix[1][2] * A->matrix[2][1]) -
                  A->matrix[0][1] * (A->matrix[1][0] * A->matrix[2][2] -
                                     A->matrix[1][2] * A->matrix[2][0]) +
                  A->matrix[0][2] * (A->matrix[1][0] * A->matrix[2][1] -
                                     A->matrix[1][1] * A->matrix[2][0]);
  } else {
    matrix_t tmp = {0};
    int res = s21_create_matrix(n, n, &tmp);
    if (res == OK) {
      int sign = 1;
      for (int i = 0; i < n; i++) {
        cofactor(A, &tmp, 0, i, n);
        determinant += sign * A->matrix[0][i] * s21_det_dop(&tmp, n - 1);
        sign = -sign;
      }
      s21_remove_matrix(&tmp);
    }
  }
  return determinant;
}

void cofactor(matrix_t *A, matrix_t *dest, int row, int col, int n) {
  dest->rows = n - 1;
  dest->columns = n - 1;
  int offset_row = 0;
  int offset_columns = 0;
  for (int i = 0; i < n; i++) {
    if (i == row) offset_row = 1;
    offset_columns = 0;
    for (int j = 0; j < n; j++) {
      if (j == col) offset_columns = 1;
      if (i != row && j != col)
        dest->matrix[i - offset_row][j - offset_columns] = A->matrix[i][j];
    }
  }
}
