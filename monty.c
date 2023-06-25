#include "monty.h"

/**
 * main - Entry point for the Monty Interpreter
 * @argc: Argument count
 * @argv: Array of arguments
 *
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure
 */
int main(int argc, char **argv)
{
	FILE *file;
	char *line = NULL;
	size_t len = 0, line_number = 0;
	stack_t *stack = NULL;

	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (!file)
	{
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n", argv[1]);
		 exit(EXIT_FAILURE);
	}


	while (getline(&line, &len, file) != -1)
	{
		line_number++;
		global.arg = strtok(line, DELIMS);
		if (!global.arg || global.arg[0] == '#')
			continue;
		global.opcode = get_opcode();
		if (!global.opcode)
		{
			dprintf(STDERR_FILENO, "L%u: unknown instruction %s\n", 
					line_number, global.arg);
			free_all(&stack);
			fclose(file);
			exit(EXIT_FAILURE);
		}
		global.opcode(&stack, line_number);
	}

	free(line);
	free_all(&stack);
	fclose(file);
	return (EXIT_SUCCESS);
}


/**
 * execute_opcode - Executes an opcode function based on a string input
 * @opcode: String containing the opcode to execute
 *
 * Return: A function pointer to the opcode function, or NULL if not found
 */
void (*execute_opcode(char *opcode))(stack_t **, unsigned int)
{
	instruction_t instructions[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{NULL, NULL}
	};

	int i =o;

	while (instructions[i].opcode)
	{
		if (strcmp(instructions[i].opcode, opcode) == 0)
			return (instructions[i].f);
		i++;
	}

	return (NULL);
}
