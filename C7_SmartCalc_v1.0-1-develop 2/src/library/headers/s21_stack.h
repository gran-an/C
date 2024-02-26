#ifndef S21_STACK_H
#define S21_STACK_H
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef double Data;

typedef struct Node {
  Data number;        // number for calculation
  struct Node *next;  // pointer
  char oper;          // operation
  int prior;          // priority
} Node;

/* GENERAL FUNCTIONS FOR THE STACK */

char pop_char(Node **stack);                    // Pop Operation from stack
void push(Node **stack, char oper, int prior);  // Push struct Node to the stack
int isEmpty(struct Node *stack);                // Checking for empty
int peek_prior(struct Node *stack);
Data pop_data(Node **stack);
void push_data(Node **stack, Data numb);

#endif