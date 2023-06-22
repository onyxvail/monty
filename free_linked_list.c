#include "monty.h"

/**
 * frees_list - it f rees the linked list
 * @head: top of the stack
 * @fps: file
 * @line: line
 * Return: void
 */
void frees_list(stack_t **head, FILE *fps, char *line)
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
