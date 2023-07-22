#ifndef UTILS_H
#define UTILS_H

extern char **environ;
char *read_command();
char **parse_command(char *command);
void execute_command(char **args);
void handle_signal(int signal);

#endif