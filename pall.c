#include "monty.h"

/**
 * pall - Prints all the integers in the stack, starting from the top
 * @stack: Pointer to the head of the stack
 * @line_number: Line number
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	(void)line_number;

	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}

}
