#include "gift.h"

int main(int argc, char *argv[]) {
  if (argc < 2) {
    print_help();
    return 1;
  }

  const char *command = argv[1];
  // lmao
  if (strcmp(command, "init") == 0) {
    printf("%s", (cmd_init() ? "lmao failed" : "wtf it worked?!"));
  } else if (strcmp(command, "add") == 0) {
    if (argc < 3) {
      printf("Usage : gift add <file>\n");
      return 1;
    }

    cmd_add(argv[2]);
  } else if (strcmp(command, "commit") == 0) {
    return cmd_commit(argc-1, &argv[1]);
  } else if (strcmp(command, "log") == 0) {
    return cmd_log(argc-1, &argv[1]);
  } else {
    printf("Unknown command: %s\n", command);
    return 1;
  }

  return 0;
}
