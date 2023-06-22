#include "monty.h"

/**
 * push_stack - pushing node to  stack.
 * @head: addressing the head of the linked list
 * @new: address pointer to node
 * Return: nothing
 */
void push_stack(stack_t **head, stack_t **new)
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
 * monty_queue - pushes the new node to queue
 * @head: addressing the head of the linked list
 * @new: address pointer to node
 * Return: nothing
 */
void monty_queue(stack_t **head, stack_t **new)
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
