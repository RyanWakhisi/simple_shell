
# The Simple Shell: 

A simple Shell Project capable of executing a number of commands.
This project was put together  by Brian Wakhisi and Allan Kipruto.

## Capabilties of this Program

1. Displays a prompt : The prompt is displayed each time a command has been executed.
2. Simple commands line - no semicolons, no pipes, no redirections.
3. One word command linesy
4. PrintS an error  message if an executable cannot be found and prompts again.
5. Handles Errors
6. It handles the end-of-file condition (Ctrl+D).
7. It handles command lines with arguments
8. Handles the PATH
9. Implements exit built-ins
10. Handles comments.

## Compilation

The Customised shell will be compiled using gcc -Wall -Werror -Wextra -pedantic -std=gnu89 * .c hsh

## Supported Commands

cd - command that changes directory
unsetenv - command that removes an environment variable.
setenv - command that initializes a new environment/modifies existing one
exit - command that exits a simple shell
env - command that list current environment variables
pwd - command that prints the path of the current working directory.

### Delimiters & Comment Commands

Semicolon(;) - serves as a command seperator that enables the execution of multiple commands on a single line by placing the semicolon between each command.
Harsh - Using a word starting with a harsh symbol in a CLI, designates the rest of the characters on that line as a comment, causing them to be ignored when the command is executed.

### Authors File

This file will contain the names of all contributors towards this simple shell project.
