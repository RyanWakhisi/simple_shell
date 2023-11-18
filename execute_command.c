#include "simple_shell.h"
/**
 * execute_command - function that executes a command
 * @command: command to be executed
 */
void execute_command(const char *command, char **env) {
    pid_t child_pid = fork();

    if (child_pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    } else if (child_pid == 0) {
        char *args[128];
        int arg_count = 0;
        char *token = strtok((char *)command, " ");

        while (token != NULL) {
            args[arg_count++] = token;
            token = strtok(NULL, " ");
        }
        args[arg_count] = NULL;

        if (strcmp(args[0], "cd") == 0) {
            if (args[1] != NULL) {
                if (chdir(args[1]) != 0) {
                    perror("chdir");
                }
            } else {
                if (chdir(getenv("HOME")) != 0) {
                    perror("chdir");
                }
            }
            exit(EXIT_SUCCESS);
        }

        if (strchr(args[0], '/') == NULL) {
        	char *path_token;
            char *path = getenv("PATH");
            if (path == NULL) {
                path = "/usr/bin";
            }

            path_token = strtok(path, ":");
            while (path_token != NULL) {
                char full_path[256];
                snprintf(full_path, sizeof(full_path), "%s/%s", path_token, args[0]);
                execve(full_path, args, env);
                path_token = strtok(NULL, ":");
            }
        } else {
            execve(args[0], args, env);
        }

        perror("execve");
        exit(EXIT_FAILURE);
    } else {
        int status;
        wait(&status);
    }
}
