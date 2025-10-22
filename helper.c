#include "gift.h"


void print_help() {
    printf("Usage: ./gift <command> [options]\n");
    printf("Commands:\n");
    printf("  init       Initialize a new repository\n");
    printf("  add        Add file contents to the index\n");
    printf("  commit     Record changes to the repository\n");
    printf("  log        Show commit logs\n");
}

short check_dir(DIR* dir) {
  if (dir) {
    closedir(dir);
  } else if (ENOENT == errno) {
    printf("%s\n", "Directory does not exist");
  } else {
    printf("%s\n", "opendir() failed lmao");
  }
}

void sha1_hash_file(const char *path, char out_hash[41]) {
  FILE *file = fopen(path, "rb");

  if (!file) {
    perror("Error opening file for hashing");
    strcpy(out_hash, "");
    return;
  }

  SHA_CTX ctx;
  SHA1_Init(&ctx);

  unsigned char data[4096];
  size_t bytes;

  while((bytes = fread(data, 1, sizeof(data), file)) != 0)
    SHA1_Update(&ctx, data, bytes);

  unsigned char hash[SHA_DIGEST_LENGTH];
  SHA1_Final(hash, &ctx);
  fclose(file);

  for (int i = 0; i < SHA_DIGEST_LENGTH; i++) {
    sprintf(out_hash + (i*2), "%02x", hash[i]);
  }

  out_hash[40] = '\0';
}
