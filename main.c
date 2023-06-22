#include "monty.h"

int main(int argc, char *argv[])
{
if (argc != 2)
{
fprintf(stderr, "Usage: monty file\n");
return (EXIT_FAILURE);
}

FILE *file = fopen(argv[1], "r");
if (file == NULL)
{
fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
return (EXIT_FAILURE);
}

stack_t *stack = NULL;
char *line = NULL;
size_t line_buf_size = 0;
ssize_t line_size;
unsigned int line_number = 0;

while ((line_size = getline(&line, &line_buf_size, file)) != -1)
{
line_number++;
char *opcode = strtok(line, " \t\n");
if (opcode == NULL || opcode[0] == '#')
continue;
if (strcmp(opcode, "push") == 0)
{
char *argument = strtok(NULL, " \t\n");
if (argument == NULL)
{
fprintf(stderr, "L%d: usage: push integer\n", line_number);
free(line);
fclose(file);
stack_print(stack);
return (EXIT_FAILURE);
}
int value = atoi(argument);
stack_push(&stack, value);
}
else if (strcmp(opcode, "pall") == 0)
{
pall(&stack);
}

}
free(line);
fclose(file);
return (EXIT_SUCCESS);
}
