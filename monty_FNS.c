#define _POSIX_C_SOURCE 200809L
#define  _GNU_SOURCE
#include <stdio.h>
#include "monty.h"

/**
 * read_monty_file - read the bytecode files
 *  and runs the commands
 * @filenames:file's pathname
 * @stack: pointer to the top of the stack
 */
void read_monty_file(char *filenames, stack_t **stack)
{
char *line;
size_t i = 0;
int line_count = 1;
instruct_func s;
int check;
int read;


var_global.file = fopen(filenames, "r");

if (var_global.file == NULL)
{
fprintf(stderr, "Error: Can't open file %s\n", filenames);
exit(EXIT_FAILURE);
}

while ((read = getline(&var_global.buffer, &i, var_global.file)) != -1)
{
line = parseline(var_global.buffer, stack, line_count);
if (line == NULL || line[0] == '#')
{
line_count++;
continue;
}
s = check_opcode(line);
if (s == NULL)
{
fprintf(stderr, "L%d: unknown instruction %s\n", line_count, line);
exit(EXIT_FAILURE);
}
s(stack, line_count);
line_count++;
}
free(var_global.buffer);
check = fclose(var_global.file);
if (check == -1)
exit(-1);
}

/**
 * check_opcode -  check the opcode
 * and returns correct function
 * @str: opcode
 * Return: returns a function on success, or NULL on failure
 */
instruct_func check_opcode(char *str)
{
int i;

instruction_t instruct[] = {
{"push", _push},
{"pall", _pall},
{"pint", _pint},
{"pop", _pop},
{"swap", _swap},
{"add", _add},
{"nop", _nop},
{"sub", _sub},
{"mul", _mul},
{"div", _div},
{"mod", _mod},
{"pchar", _pchar},
{"pstr", _pstr},
{"rotl", _rotl},
{"rotr", _rotr},
{NULL, NULL},
};

i = 0;
while (instruct[i].f != NULL && strcmp(instruct[i].opcode, str) != 0)
{
i++;
}

return (instruct[i].f);
}

/**
 * isitnumber - check if  the string is a number
 * @str: string being passed
 * Return: returns 1 if string is a number, 0 otherwise
 */
int isitnumber(char *str)
{
unsigned int i;

if (str == NULL)
return (0);
i = 0;
while (str[i])
{
if (str[0] == '-')
{
i++;
continue;
}
if (!isdigit(str[i]))
return (0);
i++;
}
return (1);
}

/**
 * parseline - parses lines for opcodesand args
 * @line: the line to be parsed
 * @stack: pointer to the head of the stack
 * @line_number: the current line number
 * Return: returns the opcode on success or null on failure
 */
char *parseline(char *line, stack_t **stack, unsigned int line_number)
{
char *op_code, *push, *arg;
(void)stack;

push = "push";
op_code = strtok(line, "\n ");
if (op_code == NULL)
return (NULL);

if (strcmp(op_code, push) == 0)
{
arg = strtok(NULL, "\n ");
if (isitnumber(arg) == 1 && arg != NULL)
{
var_global.push_arg = atoi(arg);
}
else
{
fprintf(stderr, "L%d: usage: push integer\n", line_number);
exit(EXIT_FAILURE);
}
}
return (op_code);
}
