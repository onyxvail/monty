#include <stdio.h>
#include "monty.h"

monty_t monty;

/**
 * main- entry point
 * @argc: args count
 * @argv: args vector
 *
 * Return: EXIT_SUCCESS
 */
int main(int argc, char **argv)
{

init_montyStruct();
open_monty(argc, argv[1]);
read_monty();
free_it_all();
return (EXIT_SUCCESS);
}

/**
 *  init_montyStruct - Initialising Struct
 *
 *
 *
 */
void init_montyStruct(void)
{

monty.file = NULL;
monty.line = NULL;
monty.stack = NULL;
monty.line_number = 1;
monty.is_queue = false;
}

/**
 * free_it_all - free the file
 *
 *
 *
 */

void free_it_all(void)
{
fclose(monty.file);
free(monty.line);
free_build(monty.stack);
}

/**
 * free_build - free the stack.
 * @h: the head of stack.
 *
 *
 */
void free_build(stack_t *h)
{
stack_t *temp;
stack_t *location = h;

while (location)
{
temp = location;
location = location->next;
free(temp);
}
}
