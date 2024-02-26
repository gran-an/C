#include "headers/s21_stack.h"

char pop_char(Node **stack) {
  Node *new = *stack;
  char res = new->oper;
  *stack = new->next;
  free(new);
  return res;
}

void push(Node **stack, char operation, int prioritet) {
  Node *new = malloc(sizeof(Node));
  new->oper = operation;
  new->prior = prioritet;
  new->next = *stack;
  *stack = new;
}

void push_data(Node **stack, Data numb) {
  Node *new = malloc(sizeof(Node));
  new->number = numb;
  new->next = *stack;
  *stack = new;
}

int peek_prior(struct Node *stack) { return stack->prior; }

Data pop_data(Node **stack) {
  Node *new = *stack;
  Data res = new->number;
  *stack = new->next;
  free(new);
  return res;
}

int isEmpty(struct Node *stack) {
  if (stack == NULL) {
    return 1;
  }
  return 0;
}
