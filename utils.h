#ifndef UTILS_H
#define UTILS_H

char *read_command();
char **parse_command(char *command);
void execute_command(char **args);
void handle_signal(int signal);

#endif