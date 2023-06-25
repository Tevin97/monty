#include "monty.h"

/**
 * nop - Does nothing
 * @stack: Pointer to the head of the stack
 * @line_number: Line number
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)*stack;
	(void)line_number;
}
