#ifndef UTILS_H
#define UTILS_H
#define MAX_COMMAND_LENGTH 1024
void handle_signal(int signal);
char *read_command(void);
char **parse_command(char *command);
void execute_command(char **args);
#endif
