#include "monty.h"

/**
 * main - the main monty function
 *@ac: argument count
 *@av: argument vec
 *Return: integer
 */
int main(int ac, char **av)
{
FILE *fps;
char *line = NULL;
size_t size = 0;
ssize_t read;
stack_t *head = NULL;
int line_number = 0;

if (ac < 2)
{
dprintf(STDERR_FILENO, "USAGE: monty file\n");
exit(EXIT_FAILURE);
}

fps = fopen(av[1], "r");
if (fps == NULL)
{
dprintf(STDERR_FILENO, "Error: Can't open file %s\n", av[1]);
exit(EXIT_FAILURE);
}
read = getline(&line, &size, fps);
while (read != -1)
{
line_number++;
parses_line(line);
}
frees_list(&head, fps, line);
exit(EXIT_SUCCESS);
}
