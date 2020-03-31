#ifndef SHELL_H
#define SHELL_H

#include <stdlib.h>
#include <string.h>

#define CMDLEN 256

typedef struct Command {
    int argc;
    char *argv[CMDLEN / 2 + 1];
} Command;

Command inputCmd(void);
void initCmd(Command *cmd);
void parseInp(const char *input, Command *cmd);
void printCmd(const Command *cmd);
void freeCmd(Command *cmd);

#endif
