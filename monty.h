#ifndef MONTY_H
#define MONTY_H

/*Libraries used*/
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

/**
 * struct stack_t - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_t
{
int n;
struct stack_t *prev;
struct stack_t *next;
} stack_t;

void stack_push(stack_t **stack, int n);
int stack_pop(stack_t **stack);
void stack_print(stack_t *stack);

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
char *opcode;
void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

#endif /* MONTY_H */
