#include "monty.h"

/**
 * pall - printing all the data of the linked list's nodes
 * @head: address the head  of linked list
 * Return: NOTHING
 */

void pall(stack_t **head)
{
if (*head == NULL)
return;
while (*head != NULL)
{
printf("%d\n", (*head)->n);
(*head)->next = *head;
}
}
