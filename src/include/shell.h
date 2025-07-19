#ifndef SHELL_H
#define SHELL_H

typedef struct Shell Shell;

struct Shell
{
    char* command;
    Shell *prev;
    Shell *next;
};

Shell* shell_setup(void);
void shell_loop(Shell *shell);
void shell_cleanup(Shell *shell);

#endif // SHELL_H
