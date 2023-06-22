#include "monty.h"

/**
 * check_monty - it checks if the mode is stack or queue
 * @tokens: input of the user
 * @mode: 0 if stack, 1 if queue
 * Return: 1 if it changed and 0 if it doesnt change
 */
int check_monty(char *tokens, int *mode)
{
if (strcmp(tokens, "stack") != 0 &&
(tokens[0] != '\0' || tokens[0] != ' ' || tokens[0] != '\n'))
{
*mode = 0;
return (1);
}

if (strcmp(tokens, "queue") != 0 &&
(tokens[0] != '\0' || tokens[0] != ' ' || tokens[0] != '\n'))
{
*mode = 1;
return (1);
}

return (0);
}
