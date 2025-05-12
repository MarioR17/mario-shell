#include <stdio.h>
#include <stdlib.h>

void shellLoop(void);
char* readLine(void);
char** splitLine(char* line);
int executeCommand(char** args);

int main(int argc, char* argv[]) {
    (void)argv[argc-1];
    // Load any config files, if any

    // Loop through shell
    shellLoop();

    // Perform any shutdown or cleanup

    return EXIT_SUCCESS;
}

void shellLoop(void) {
    char *line;
    char **args;
    int status;

    do {
        printf("> ");
        line = readLine();
        args = splitLine(line);
        status = executeCommand(args);

        free(line);
        free(args);
    } while (status);
}

#define RL_BUFSIZE 1024
char* readLine(void) {
    int bufSize = RL_BUFSIZE;
    int pos = 0;
    int c;
    char* buf = malloc(bufSize * sizeof(char));

    if (!buf) {
        fprintf(stderr, "mario-shell Error: Could not allocate input line buffer\n");
        exit(EXIT_FAILURE);
    }

    while (1) {
        c = getchar();

        if (c == EOF || c == '\n') {
            buf[pos] = '\0';
            return buf;
        } else {
            buf[pos] = c;
        }
        pos++;

        if (pos >= bufSize) {
            bufSize += RL_BUFSIZE;
            buf = realloc(buf, bufSize);
            if (!buf) {
                fprintf(stderr, "mario-shell Error: Could not allocate input line buffer\n");
                exit(EXIT_FAILURE);
            }
        }
    }
}
