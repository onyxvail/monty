#define _POSIX_C_SOURCE 200809L
#include<stdio.h>
#include "monty.h"

/**
 * main - main function OF MONTY PROG
 *@ac: argument count
 *@av: argument vect
 *Return: integer
 */

int main(int ac, char **av)
{
FILE *fps;
char *line = NULL;
size_t size = 0;
int read;

if (ac != 2)
{
dprintf(STDERR_FILENO, "USAGE: monty file\n");
return (1);
}

fps = fopen(av[1], "r");
if (fps == NULL)
{
dprintf(STDERR_FILENO, "Error: cannot open file\n");
return (1);
}

while ((read = getline(&line, &size, fps)) != -1)
{

}

fclose(fps);
free(line);

return (0);
}
