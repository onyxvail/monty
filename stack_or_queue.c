#include "monty.h"

/**
 * monty_check - it check if the mode is stack or queue
 * @token: the input of the user
 * @mode: 0 if stack and 1 if queue
 * Return: 1 if its changed and 0 if its not changed
 */
int monty_check(char *token, int *mode)
{
if (strcmp(token, "stack") != 0 &&
(token[0] != '\0' || token[0] != ' ' || token[0] != '\n'))
{
*mode = 0;
return (1);
}

if (strcmp(token, "queue") != 0 &&
(token[0] != '\0' || token[0] != ' ' || token[0] != '\n'))
{
*mode = 1;
return (1);
}

return (0);
}
