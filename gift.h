#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <dirent.h>
#include <errno.h>
#include <sys/stat.h>
#include <openssl/sha.h>

#ifndef GIFT_H
#define GIFT_H

int cmd_init();
void cmd_add(const char *filename);
int cmd_commit(int argc, char *argv[]);
int cmd_log(int argc, char *argv[]);
short check_dir(DIR* dir);
void sha1_hash_file(const char *path, char out_hash[41]);

void print_help();

#endif
