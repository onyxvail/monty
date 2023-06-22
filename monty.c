#include "monty.h"

/**
 * push - Pushes an integer to the stack
 * @stack: The stack to push the integer to
 * @line_number: The line number of the instruction in the bytecode file
 *
 */
void push(stack_t **stack, unsigned int line_number)
{
int value;
char *argument = strtok(NULL, "\n");

if (argument == NULL)
{
fprintf(stderr, "L%d: usage: push integer\n", line_number);
exit(EXIT_FAILURE);
}

value = atoi(argument);
stack_push(stack, value);
}
/**
 * pall - Prints all the values on the stack
 * @stack: The stack to print the values from
 * @line_number: The line number of the instruction in the bytecode file
 *
 */
void pall(stack_t **stack)
{
stack_t *top = *stack;

if (top == NULL)
{
return;
}
while (top != NULL)
{
printf("%d\n", top->n);
top = top->next;
}
}
