#include "monty.h"

/**
 * push - Adds an integer to the top of the stack
 * @stack: Double pointer to the head of the stack
 * @line_number: Line number
 */
void push(stack_t **stack, unsigned int line_number)
{
	char *arg;

	if (!global.arg || !is_digit(global.arg))
	{
		dprintf(STDERR_FILENO, "L%u: usage: push integer\n", line_number);
		free_all(stack);
		exit(EXIT_FAILURE);
	}

	arg = global.arg;
	add_node(stack, atoi(arg));
}
