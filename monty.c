#include <stdio.h>
#include <stdlib.h>

#include "monty.h"

/**
 * pall - print all members
 * @stack: double list
 * @linenumber: line
 */
void pall(stack_t **stack, __attribute__((unused)) unsigned int linenumber)
{
stack_t *a = *stack;
if (!*stack)
{
return;
}

while (a != NULL)
{
printf("%d\n", a->n);
a = a->next;
}
}

/**
 * pint - prints the value at the top of the stack
 * @stack: double pointer to the head of the stack
 * @line_number: current line number in the monty file
 */
void pint(stack_t **stack, unsigned int line_number)
{
if (*stack == NULL)
{
dprintf(STDERR_FILENO, "L%u: can't pint, stack empty\n", line_number);
free_it_all();
exit(EXIT_FAILURE);
}
printf("%d\n", (*stack)->n);
}
