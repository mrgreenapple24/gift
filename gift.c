#include "gift.h"

int main(int argc, char *argv[]) {
  if (argc < 2) {
    print_help();
    return 1;
  }

  const char *command = argv[1];

  if (strcmp(command, "init") == 0) {
    return cmd_init(argc - 1, &argv[1]);
  } else if (strcmp(command, "add") == 0) {
    return cmd_add(argc - 1, &argv[1]);
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
