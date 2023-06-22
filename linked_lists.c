#include "monty.h"

/**
 * free_monty - freeing the linked lists
 * @head: top of  stack
 * @fps: file
 * @line: line
 * Return: VOID
 */

void free_monty(stack_t **head, FILE *fps, char *line)
{
if (*head != NULL)
{
while ((*head)->next != NULL)
{
(*head) = (*head)->next;
free((*head)->prev);
}
free(*head);
}
fclose(fps);
free(line);
}
