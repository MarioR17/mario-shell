#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

#include "include/shell.h"

int main(int argc, char* argv[]) 
{
    (void) argv[argc-1];

    Shell *shell = shell_setup();

    if (shell == NULL) 
    {
        fprintf(stderr, "Failed to set up shell\n");
        return EXIT_FAILURE;
    }

    shell_loop(shell);

    shell_cleanup(shell);

    return EXIT_SUCCESS;
}
