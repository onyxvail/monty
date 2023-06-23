#include "monty.h"

/**
 * _rotr - mod top of stack
 * @stack: pointer to list
 * @line_number: number of line
 */
void _rotr(stack_t **stack, unsigned int line_number)
{
stack_t *pld = *stack;

int supp = 0;

if (!line_number || !stack || !*stack || !(*stack)->next)
return;

while (pld->next)
pld = pld->next;

supp = pld->n;

while (pld->prev)
{
pld = pld->prev;
pld->next->n = pld->n;
}

pld->n = supp;
}

/**
 * _pstr - mod top of stack
 * @stack: pointer to lists
 * @line_number: number of line
 */
void _pstr(stack_t **stack, unsigned int line_number)
{
stack_t *tmp = *stack;
int c = 0;

(void)line_number;

while (tmp)
{
c = tmp->n;
if (c == 0 || _isalpha(c) == 0)
break;
putchar(c);
tmp = tmp->next;
}
putchar('\n');
}

/**
 * _rotl - mod top of stack
 * @stack: pointer to lists
 * @line_number: number of line opcode
 */
void _rotl(stack_t **stack, unsigned int line_number)
{
stack_t *pld = *stack;

int supp = 0;

if (!line_number || !stack || !*stack || !(*stack)->next)
return;

supp = pld->n;

while (pld->next)
{
pld = pld->next;
pld->prev->n = pld->n;
}

pld->n = supp;
}
