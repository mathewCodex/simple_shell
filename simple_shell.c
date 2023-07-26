#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

#define MAX_COMMAND_ARG 1024

/**
 * main - Entry point of the program
 *
 * Return: 0 (Success)
 */
int main(void)
{
	char *command;
	char **args;

	signal(SIGINT, handle_signal);
	while (1)
	{
		printf("#cisfun$ ");
		command = read_command();

		if (command == NULL)
		{
			break;
		}

		args = parse_command(command);

		execute_command(args);

		free(command);
		free(args);
	}

	return (0);
}
