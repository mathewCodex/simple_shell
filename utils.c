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
 * parse_command - Parse the command into arguments
 * @command: The command to be parsed
 *
 * Return: A double pointer to an array of arguments
 */
char **parse_command(char *command)
{
	char **args = (char **)malloc(MAX_COMMAND_LENGTH * sizeof(char *));
	char *token;
	int i;

	if (!args)
	{
		perror("Memory allocation error");
		exit(EXIT_FAILURE);
	}

	token = strtok(command, " ");
	i = 0;

	while (token != NULL)
	{
		args[i] = token;
		i++;

		if (i >= MAX_COMMAND_LENGTH)
		{
			fprintf(stderr, "Too many arguments\n");
			exit(EXIT_FAILURE);
		}

		token = strtok(NULL, " ");
	}

	args[i] = NULL;

	return (args);
}

/**
 * execute_command - Execute a command
 * @args: An array of commands to be executed
 * Return: No return value
 */
void execute_command(char **args)
{
	pid_t pid;
	int status;

	pid = fork();

	if (pid == 0)
	{
		if (execve(args[0], args, NULL) == -1)
		{
			perror("Execution error");
			_exit(EXIT_FAILURE);
		}
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
 * handle_signal - Handle the SIGNINT (ctrl c)
 * @signal: The signal number
 */
void handle_signal(int signal)
{
	UNUSED(signal);
	printf(" ");
	fflush(stdout);
}
