#include "common.h"

int main(int argc, char const *argv[]) {
  unsigned int i;
  const char *filename = "/tmp/krf_link1";
  const char *linkname = "/tmp/krf_link2";

  creat(filename, 0700);

  for (i = 0;; i++) {
    if (i % 1000 == 0) {
      printf("iteration %u...\n", i);
    }

    if (link(filename, linkname) < 0) {
      perror("fault!");
      unlink(filename);
      exit(errno);
    }

    unlink(linkname);
  }

  return 0;
}
