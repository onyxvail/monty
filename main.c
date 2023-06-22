#include "monty.h"
/**
 * open_monty - opens a monty
 * and validates  the input
 * @argc: the args for count
 * @filename: the path to monty.
 */
void open_monty(int argc, char *filename)
{
if (argc != 2)
{
dprintf(STDERR_FILENO, "USAGE: monty file\n");
exit(EXIT_FAILURE);
}
monty.file = fopen(filename, "r");
if (!monty.file)
{
dprintf(STDERR_FILENO, "Error: Can't open file %s\n", filename);
exit(EXIT_FAILURE);
}
}
/**
 * read_monty - Read and execute each line of the input from monty'sfile
 */
void read_monty(void)
{
size_t len = 0;
ssize_t read;
char *opcode, *data;
while (1)
{
read = getline(&monty.line, &len, monty.file);
if (read == -1)
break;
opcode = strtok(monty.line, " ");
if (*opcode == '#' || *opcode == '\n')
{
monty.line_number++;
continue;
}
else if (strcmp(opcode, "push") == 0)
{
data = strtok(NULL, " \n");
if (monty.is_queue)
{
push_queue(data);
}
else
push(data);
}
else
opcode_monty(&monty.stack, opcode);
monty.line_number++;
}
}
/**
 * opcode_monty - finds and call the function
 * that correspond with opcode.
 * @stack: **pointer to stack
 * @opcode: opcode from this line of our monty file
 */
void opcode_monty(stack_t **stack, char *opcode)
{
int i;
char *op;
instruction_t fncs[] = {
{"pall", pall},
{"pint", pint},
{"pop", pop},
{"swap", swap},
{"add", add},
{"nop", nop},
{"sub", sub},
{"div", div_op},
{"mul", mul},
{"mod", mod},
{"pchar", pchar},
{"pstr", pstr},
{"rotl", rotl},
{"rotr", rotr},
{"stack", stack_op},
{"queue", queue_op},
{NULL, NULL}
};
op = strtok(opcode, "\n");
for (i = 0; fncs[i].opcode; i++)
{
if (strcmp(op, fncs[i].opcode) == 0)
{
fncs[i].f(stack, monty.line_number);
return;
}
}
if (strcmp(opcode, "push"))
{
dprintf(STDERR_FILENO, "L%u: ", monty.line_number);
dprintf(STDERR_FILENO, "unknown instruction %s\n", opcode);
}
else
dprintf(STDERR_FILENO, "L%u: usage: push integer\n", monty.line_number);
exit(EXIT_FAILURE);
}
