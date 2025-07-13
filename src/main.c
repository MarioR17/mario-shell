#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

#include "include/shell.h"

int main(int argc, char* argv[]) 
{
    (void) argv[argc-1];

    printf("Welcome to the simple shell!\n");

    return EXIT_SUCCESS;
}
