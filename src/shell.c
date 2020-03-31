#include "shell.h"

#include <stdio.h>

Command inputCmd(void) {
    Command cmd;
    char input[CMDLEN];
    fgets(input, CMDLEN, stdin);
    cmd = parseInp(input);
    return cmd;
}

void initCmd(Command *cmd) {
    cmd->argc = 0;
    for (size_t i = 0; i < CMDLEN / 2 + 1; i++) cmd->argv[i] = NULL;
}

Command parseInp(const char *input) {
    Command cmd;
    initCmd(&cmd);
    char *inpCopy = strdup(input), *cpyPtr = inpCopy;
    char delim[] = " \n";
    for (char *ptr = strsep(&inpCopy, delim); ptr != NULL;
         ptr = strsep(&inpCopy, delim))
        if (*ptr != '\0') cmd.argv[cmd.argc++] = strdup(ptr);
    free(cpyPtr);
    return cmd;
}

void printCmd(const Command *cmd) {
    for (size_t i = 0; i < cmd->argc; i++)
        if (i == 0)
            printf("%s", cmd->argv[i]);
        else
            printf(" %s", cmd->argv[i]);
}

void freeCmd(Command *cmd) {
    for (size_t i = 0; i < cmd->argc; i++) free(cmd->argv[i]);
}
