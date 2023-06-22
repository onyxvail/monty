#include "monty.h"

/**
 * rotr- Rotate from bottom to top
 * @stack: head of the stack
 * @linenumber: the current ln
 *
 */
void rotr(stack_t **stack, __attribute__((unused))unsigned int linenumber)
{
stack_t *first, *second;

if (!(*stack) || !(*stack)->next)
{
return;
}

first = *stack;

while (first->next->next)
{
first = first->next;
}
second = first->next;
first->next = NULL;
(*stack)->prev = second;
second->next = *stack;
second->prev = NULL;
*stack = second;
}
/**
 * stack_op - makes the Stack format
 * @stack: head of the stack
 * @linenumber: the current ln
 *
 */
void stack_op(stack_t **stack, unsigned int linenumber)
{
(void)stack;
(void)linenumber;
monty.is_queue = false;
}
/**
 * queue_op - makes the queue format
 * @stack: head of the stack
 * @linenumber: the current ln
 */
void queue_op(stack_t **stack, unsigned int linenumber)
{
(void)stack;
(void)linenumber;
monty.is_queue = true;
}

/**
 * push_queue - add the  node to end of the list
 * @argument: integer
 */
void push_queue(char *argument)
{
int data;
stack_t *new, *location;

if (!check_input(argument))
{
dprintf(STDERR_FILENO, "L%u: usage: push integer\n",
monty.line_number);
free_it_all();
exit(EXIT_FAILURE);
}
data = atoi(argument);
new = malloc(sizeof(stack_t));
if (!new)
{
dprintf(STDERR_FILENO, "Error: malloc failed\n");
free_it_all();
exit(EXIT_FAILURE);
}
location = monty.stack;
new->n = data;
new->next = NULL;
if (!location)
{
new->prev = NULL;
monty.stack = new;
return;
}
while (location->next)
{
location = location->next;
}
location->next = new;
new->prev = location;
}
