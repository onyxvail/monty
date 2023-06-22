#include "monty.h"

/**
 * push - pushes the new node to the linked list
 * @head: address of the linked list's head
 * @arg: corresponding arg.
 * @mode: 1 if queue and 0 if stack
 * Return: nothing
 */
void push(stack_t **head, char *arg, int *mode)
{
stack_t *new = NULL;
int num = atoi(arg);

new = malloc(sizeof(stack_t));
if (new == NULL)
{
dprintf(STDERR_FILENO, "Error: malloc failed\n");
error = 1;
free(new);
return;
}
new->n = num;
if (*mode == 0)
push_stack(head, &new);
else
monty_queue(head, &new);

}
