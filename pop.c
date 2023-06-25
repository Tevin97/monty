#include "monty.h"

/**
 * pop - Removes the top element of the stack
 * @stack: Double pointer to the head of the stack
 * @line_number: Line number
 */
void pop(stack_t **stack, unsigned int line_number)
{
	if (!*stack)
	{
		dprintf(STDERR_FILENO, "L%u: can't pop an empty stack\n", line_number);
		free_all(stack);
		exit(EXIT_FAILURE);
	}

	delete_node(stack);

}
