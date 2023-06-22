#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

/**
 * open_monty - open a monty and validate input
 * @argc: args count
 * @filename: path to monty
 */
void open_monty(int argc, char *filename)
{
if (argc != 2)
{
fprintf(stderr, "USAGE: monty file\n");
exit(EXIT_FAILURE);
}
monty.file = fopen(filename, "r");
if (!monty.file)
{
fprintf(stderr, "Error: Can't open file %s\n", filename);
exit(EXIT_FAILURE);
}
}

/**
 * read_monty - reads and executes each line of input from monty file
 */
void read_monty(void)
{
size_t len = 0;
ssize_t read;
char *opcode, *data;

while ((read = custom_getline(&monty.line, &len, monty.file)) != -1)
{
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
push_queue(data);
else
push(data);
}
else
op_choose(&monty.stack, opcode);
monty.line_number++;
}
}

/**
 * op_choose - find & call the function that corresponds with the opcode
 * @stack: **pointer to stack
 * @opcode: opcode from this line of our monty file
 */
void op_choose(stack_t **stack, char *opcode)
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
fprintf(stderr, "L%u: ", monty.line_number);
fprintf(stderr, "unknown instruction %s\n", opcode);
}
else
fprintf(stderr, "L%u: usage: push integer\n", monty.line_number);
exit(EXIT_FAILURE);
}
