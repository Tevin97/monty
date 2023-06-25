#include "monty.h"

/**
 * add - Adds the top two elements of the stack
 * @stack: Double pointer to the head of the stack
 * @line_number: Line number
 */
void add(stack_t **stack, unsigned int line_number)
{
	int sum;

	if (!*stack || !(*stack)->next)
	{
		 dprintf(STDERR_FILENO, "L%u: can't add, stack too short\n", line_number);
		 free_all(stack);
		 exit(EXIT_FAILURE);
	}

	sum = (*stack)->n + (*stack)->next->n;
	(*stack)->next->n = sum;
	delete_node(stack);
}
