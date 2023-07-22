#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <direct.h>

#define MAX_COMMAND_ARG 1024
#define MAX_ARG 64

int main()
{
    char *command;
    char **args;

    signal(SIGINT, handle_signal);

    while (1)
    {
        printf("$ ");
        command = read_command();
        args = parse_command(command);

        if (strcmp(args[0], "exit") == 0)
        {
            break;
        }
        else if (strcmp(args[0], "env") == 0)
        {
            char **env = environ;

            while (*env != NULL)
            {
                printf("%s\n", *env);
                env++;
            }
        }
        else
        {
            execute_command(args);
        }

        free(command);
        free(args);
    }

    return (0);
}