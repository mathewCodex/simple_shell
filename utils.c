#include "utils.h"
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

#define UNUSED(x) (void)(x)

/**
 * read_command - Read a command from the user input.
 *
 * Return: The command entered by the user as a string
 */
char *read_command(void)
{
	char *command = NULL;
	size_t buffer_size = 0;
	ssize_t length = getline(&command, &buffer_size, stdin);

	if (length == -1)
	{
		if (feof(stdin))
		{
			printf("\nExiting shell...\n");
			return (NULL);
		}
		else
		{
			perror("Error reading command");
			exit(EXIT_FAILURE);
		}
	}

	if (command[length - 1] == '\n')
	{
		command[length - 1] = '\0';
	}
	return (command);
}

/**
 * execute_command - Execute a command
 * @command: A command to be executed
 *
 * Return: No return value
*/
void execute_command(char *command)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == 0)
	{
		char *args[2];

		args[0] = command;
		args[1] = NULL;
		execvp(command, args);
		perror("Execution error");
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
	{
		perror("Forking error");
	}
	else
	{
		do {
			wait(&status);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
}

/**
 * handle_signal - Handle the SIGINT signal (Ctrl C)
 * @signal: The signal number
*/
void handle_signal(int signal)
{
	UNUSED(signal);
	printf("\n#cisfun$ ");
	fflush(stdout);
}
