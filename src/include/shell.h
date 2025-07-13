#ifndef SHELL_H
#define SHELL_H

typedef struct Shell Shell;

struct Shell
{
    char* config_file;
    char* log_file;
    char* command;
    Shell *prev;
    Shell *next;
};

void shell_setup(void);
void shell_loop(void);
void shell_cleanup(void);

#endif // SHELL_H
