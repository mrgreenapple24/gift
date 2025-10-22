#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#ifndef GIFT_H
#define GIFT_H

int cmd_init();
int cmd_add(int argc, char *argv[]);
int cmd_commit(int argc, char *argv[]);
int cmd_log(int argc, char *argv[]);

void print_help() {
    printf("Usage: ./gift <command> [options]\n");
    printf("Commands:\n");
    printf("  init       Initialize a new repository\n");
    printf("  add        Add file contents to the index\n");
    printf("  commit     Record changes to the repository\n");
    printf("  log        Show commit logs\n");
}


#endif
