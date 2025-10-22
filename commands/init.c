#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <errno.h>

int make_dir(const char *path) {
  if (mkdir(path, 0777) == -1) {
    if (errno == EEXIST) return 0;
    perror(path);
    return -1;
  }
  return 0;
}

int write_file(const char *path, const char *content) {
  FILE *fp = fopen(path, "w");
  if (!fp) {
    perror(path);
    return -1;
  }

  fprintf(fp, "%s", content);
  fclose(fp);
  return 0;
}

int cmd_init() {
  const char *gitdir = ".gift";

  if (make_dir(gitdir) < 0) return 1;

  const char *dirs[] = {
    ".gift/objects",
    ".gift/objects/info",
    ".gift/objects/pack",
    ".gift/refs",
    ".gift/refs/heads",
    ".gift/refs/tags",
    ".gift/hooks",
    ".gift/info"
  };

  for (int i = 0; i < 8; i++) {
    if (make_dir(dirs[i]) < 0) return 1;
  }

  if (write_file(".gift/HEAD", "ref: refs/heads/master\n") < 0) return 1;

  if (write_file(".gift/config", "[core]\n" "\trepositoryformatversion = 0\n" "\tfilemode = true\n" "\tbare = false\n") < 0) return 1;

  if (write_file(".gift/description", "Unnamed repository; edit this file to name the reposiitory.\n") < 0) return 1;

  printf("Initialized empty gift repository in .gift/\n");
  return 0;
}
