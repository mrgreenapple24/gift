#include "../gift.h"

void cmd_add(const char *filename) {
  char hash[41];
  sha1_hash_file(filename, hash);

  if (strlen(hash) == 0) {
    fprintf(stderr, "Failed to hash file%s\n", filename);
    return;
  }
  

  char object_path[256];
  snprintf(object_path, sizeof(object_path), ".gift/objects/%s\n", hash);

  FILE *src = fopen(filename, "rb");
  FILE *dst = fopen(object_path, "wb");

  if (!src || !dst) {
    perror("Error creating object file");
    if (src) fclose(src);
    if (dst) fclose(dst);
    return;
  }

  char buffer[4096];
  size_t bytes;

  while((bytes = fread(buffer, 1, sizeof(buffer), src)) > 0)
    fwrite(buffer, 1, bytes, dst);

  fclose(src);
  fclose(dst);

  FILE *index = fopen(".gift/index", "a");

  if (index) {
    fprintf(index, "%s %s\n", hash, filename);
    fclose(index);
  }

  printf("Added '%s' (SHA1: %s)\n", filename, hash);
}

