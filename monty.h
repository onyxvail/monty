#ifndef MONTY_H
#define MONTY_H

#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdarg.h>
#include <errno.h>
#include <stdbool.h>

/*data structures for this project*/

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
int n;
struct stack_s *prev;
struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
char *opcode;
void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* Structure declaration */
typedef struct monty_s
{
FILE *file;
char *line;
size_t line_len;
unsigned int line_number;
int is_queue;
stack_t *stack;
} monty_t;

extern monty_t monty;

/* prototypes Fns for monty*/
void open_monty(int argc, char *filename);
void read_monty(void);
void opcode_monty(stack_t **stack, char *opcode);
ssize_t custom_getline(char **lineptr, size_t *n, FILE *stream);
void op_choose(stack_t **stack, char *opcode);
void init_montyStruct(void);
void free_it_all(void);
void free_build(stack_t *h);
bool check_input(char *str);

/* prototype opcode Fns */

void push(char *argument);
void pop(stack_t **stack, unsigned int linenumber);
void swap(stack_t **stack, unsigned int linenumber);
void nop(stack_t **stack, unsigned int linenumber);
void add(stack_t **stack, unsigned int linenumber);
void pall(stack_t **stack, unsigned int linenumber);
void pint(stack_t **stack, unsigned int linenumber);
void sub(stack_t **stack, unsigned int linenumber);
void div_op(stack_t **stack, unsigned int linenumber);
void mul(stack_t **stack, unsigned int linenumber);
void mod(stack_t **stack, unsigned int linenumber);
void pchar(stack_t **stack, unsigned int linenumber);
void pstr(stack_t **stack, unsigned int linenumber);
void rotl(stack_t **stack, unsigned int linenumber);
void rotr(stack_t **stack, unsigned int linenumber);
void stack_op(stack_t **stack, unsigned int linenumber);
void queue_op(stack_t **stack, unsigned int linenumber);
void push_queue(char *argument);

#endif /*MONTY_H*/
