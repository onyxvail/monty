#include "monty.h"

/**
 * parses_line - parses line into tokens.
 * the tokens are separated by " " and "\n".
 * only the  first 2 tokens will be returned if success
 * @line: buffer from getline
 *
 * Return: null-terminated array of tokens
 * or NULL
 */
char **parses_line(char *line)
{
char *token, **tokens;
unsigned int i;

tokens = malloc(sizeof(char *) * 3);
if (tokens == NULL)
{
printf("Error: malloc failed");
exit(EXIT_FAILURE);
}
token = strtok(line, " '\n'");
if (token == NULL)
{
free(tokens);
return (NULL);
}
i = 0;
while (token != NULL && i < 2)
{
tokens[i] = token;
token = strtok(NULL, " '\n'");
i++;
}
tokens[i] = NULL;
return (tokens);
}
