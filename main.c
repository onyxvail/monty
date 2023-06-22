#include "monty.h"

/**
 * open_file - open The Monty File
 * and validate the input
 * @argc: Argument Count
 * @filename: The Path to the Monty file
 */
void open_file(int argc, char *filename)
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
 * read_instructions - Read and Execute each line
 * of The instructions from Monty file.
 */
void read_instructions(void)
{
char *opcode, *data;
for (monty.line_number = 1;
getline(&monty.line, &monty.line_len, monty.file) != -1; monty.line_number++)
{
opcode = strtok(monty.line, " ");
if (*opcode == '#' || *opcode == '\n')
{
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
{
push(data);
}
}
else
{
choose_operation(&monty.stack, opcode);
}
}
}
/**
 * choose_operation - Finding and Calling the function
 * that correspond To The opcode.
 * @stack: the double pointer to the stack
 * @opcode: opcode from the current line of Monty file
 */
void choose_operation(stack_t **stack, char *opcode)
{
int i;
char *op;
instruction_t instructions[] = {
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
{"queue", queue_op}, {NULL, NULL}
};
op = strtok(opcode, "\n");
for (i = 0; instructions[i].opcode; i++)
{
if (strcmp(op, instructions[i].opcode) == 0)
{
instructions[i].f(stack, monty.line_number);
return;
}
}
if (strcmp(opcode, "push") == 0)
{
dprintf(STDERR_FILENO,
"L%u: usage: push integer\n", monty.line_number);
}
else
{
dprintf(STDERR_FILENO,
"L%u: unknown instruction %s\n", monty.line_number, opcode);
}
exit(EXIT_FAILURE);
}
