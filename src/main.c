#include "strings.h"
#include <stdio.h>

int main(int argc, char **argv) {
  if (argc == 1) {
    printf("usage: %s word_to_reverse\n", argv[0]);
    return -1;
  }

  for (int i = 1; i < argc; i++) {
    char *result = argv[i];
    revstr(result);
    printf("%s\n", result);
  }

  return 0;
}
