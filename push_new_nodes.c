#include "monty.h"

/**
 * stackpush - pushes the node to the stack
 * @head: head address of the linked list
 * @new: addresses the pointer   to new node.
 * Return: NOTHING
 */

void stackpush(stack_t **head, stack_t **new)
{
if (*head == NULL)
{
(*new)->prev = NULL;
(*new)->next = NULL;
*head = (*new);
}
else
{
(*head)->prev = *new;
(*new)->next = *head;
(*new)->prev = NULL;
*head = *new;
}
}

/**
 * monty_enqueue - push new node to the queue.
 * @head: head address of the linked list.
 * @new: address THE pointer to THE New node
 * Return: NOTHING.
 */

void monty_enqueue(stack_t **head, stack_t **new)
{
stack_t *tmp;

if (*head == NULL)
{
(*new)->prev = NULL;
(*new)->next = NULL;
*head = (*new);
}
else
{
tmp = *head;
while (tmp->next)
tmp = tmp->next;

tmp->next = *new;
(*new)->next = NULL;
(*new)->prev = tmp;
}
}
