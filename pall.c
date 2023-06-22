#include "monty.h"

/**
 * pall - printing the linked list.
 * @head: addressing the linked list
 * Return: nothing
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
