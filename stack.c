#include "monty.h"

/**
 * stack_push - Pushes an integer onto the stack.
 *
 * @stack: The stack to push the integer onto.
 * @n: The integer to push onto the stack.
 *
 * Return: void
 */
void stack_push(stack_t **stack, int n)
{
stack_t *new_node = malloc(sizeof(stack_t));

if (new_node == NULL)
{
fprintf(stderr, "Error: malloc failed\n");
exit(EXIT_FAILURE);
}

new_node->n = n;
new_node->prev = NULL;
new_node->next = *stack;

if (*stack != NULL)
{
(*stack)->prev = new_node;
}
*stack = new_node;
}

/**
 * stack_pop - Pops an integer from the stack.
 *
 * @stack: The stack to pop the integer from.
 *
 * Return: The integer that was popped from the stack.
 */
int stack_pop(stack_t **stack)
{
int n;
if (*stack == NULL)
{
return (-1);
}
n = (*stack)->n;
*stack = (*stack)->next;
free((*stack)->prev);
(*stack)->prev = NULL;
return (n);
}

/**
 * stack_print - Prints the contents of the stack.
 *
 * @stack: The stack to print.
 *
 * Return: void
 */
void stack_print(stack_t *stack)
{
if (stack == NULL)
{
return;
}
printf("%d\n", stack->n);
stack_print(stack->next);
}
