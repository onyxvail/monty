#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

/**
 * push - pushes the node to the linked list
 * @head: head address of the linked list
 * @arg:  the arg of the corresponding's push
 * @mode: 0 if stack & 1 if queue
 * Return: NOTHING
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
push(head, &new);
else
monty_enqueue(head, &new);
}
