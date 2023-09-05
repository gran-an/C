#ifndef S21_MATRIX_H
#define S21_MATRIX_H
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define ERROR 2
#define INCORRECT 1
#define OK 0
#define SUCCESS 1
#define FAILURE 0

typedef struct matrix_struct {
  double **matrix;
  int rows;
  int columns;
} matrix_t;

int s21_create_matrix(int rows, int columns, matrix_t *result);  //(создание)
void s21_remove_matrix(matrix_t *A);  //(очистка и уничтожение)
int s21_eq_matrix(matrix_t *A, matrix_t *B);  //(сравнение)
int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);  //(сложение)
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);  //(вычитание)
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);  //(умножение)
int s21_mult_number(matrix_t *A, double number,
                    matrix_t *result);  //(умножение на число)
int s21_transpose(matrix_t *A, matrix_t *result);  //(транспонирование)
int s21_determinant(matrix_t *A, double *result);  //(вычисление определителя)
int s21_calc_complements(
    matrix_t *A,
    matrix_t *result);  //(вычисление матрицы алгебраических дополнений)
int s21_inverse_matrix(matrix_t *A,
                       matrix_t *result);  //(поиск обратной матрицы)
int s21_empty(matrix_t *A);  //(определение пустой матрицы)
double s21_det_dop(matrix_t *A, int n);  // (нахождение детерминанта)
void cofactor(matrix_t *A, matrix_t *dest, int row, int col,
              int n);  //(уменьшение порядка матрицы и возвращение уменьшщеной
                       //на 1 матрицы)

#endif