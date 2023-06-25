#include "monty.h"
/**
 * pint - Prints the value at the top of the stack without removing it
 * @stack: Pointer to the head of the stack
 * @line_number: Line number
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (!*stack)
	{
		dprintf(STDERR_FILENO, "L%u: can't pint, stack empty\n", line_number);
		free_all(stack);
	}

	printf("%d\n", (*stack)->n);
}
