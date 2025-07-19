#include <stdio.h>
#include <stdlib.h>

#include "include/shell.h"

Shell* shell_setup(void)
{
    Shell *shell = malloc(sizeof(Shell));

    if (shell == NULL)
    {
        fprintf(stderr, "Memory allocation failed for Shell\n");
        exit(EXIT_FAILURE);
    }

    return shell;
}

void shell_cleanup(Shell *shell)
{
    if (shell != NULL)
    {
        if (shell->command != NULL)
        {
            free(shell->command);
        } else {
            fprintf(stderr, "Command pointer is NULL during cleanup\n");
        }
        free(shell);
    } else {
        fprintf(stderr, "Shell pointer is NULL during cleanup\n");
    }
}

void shell_loop(Shell *shell)
{
    if (shell == NULL)
    {
        fprintf(stderr, "Shell pointer is NULL in loop function\n");
        return;
    }

    while (1)
    {
        printf("> ");
        shell->command = malloc(256 * sizeof(char));
        if (shell->command == NULL)
        {
            fprintf(stderr, "Memory allocation failed for command\n");
            exit(EXIT_FAILURE);
        }

        if (fgets(shell->command, 256, stdin) == NULL)
        {
            fprintf(stderr, "Error reading command\n");
            free(shell->command);
            exit(EXIT_FAILURE);
        }
        
        // Process the command here
        printf("You entered: %s", shell->command);

        // For demonstration, we will break the loop after one iteration
        break;
    }
}
