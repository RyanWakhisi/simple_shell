#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

extern char **environ;

void displayPrompt(void);
void print_output(const char *message);
void read_user_command(char *command, size_t size);
void execute_command(const char *command, char **env);
char **get_environment(void);
void print_environment(char *command, char **environment);
char *concat_two_strings(char *dest, char *src);
void exit_shell(char *command, char **environment);

#endif
