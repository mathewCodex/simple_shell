#include "utils.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGS 64

/**
 * read_command - Read a command from the user input.
 * 
 * Return: The command entered by the user as a string
*/
char *read_command(void)
{
    char *command;
    size_t buffer_size;
    size_t length;

    command = NULL;
    buffer_size = 0;
    getline(&command, &buffer_size, stdin);
    length = strlen(command);
    if (command[length - 1] == '\n')
    {
        command[length - 1] = '\0';
    }
    return (command);
}

/**
 * parse_command - Parse the command into arguments
 * @command: The command string to be parsed
 * 
 * Return: A double pointer to an array of arguments
*/
char **parse_command(char *command)
{
    char **args = (char **)malloc(MAX_ARGS * sizeof(char *));
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
        if (i >= MAX_ARGS)
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
 * handle_signal - Handle the SIGINT signal (Ctrl C)
 * @signal: The signal number
*/
void handle_signal(int signal)
{
    printf("\n#cisfun$ ");
    fflush(stdout);
}