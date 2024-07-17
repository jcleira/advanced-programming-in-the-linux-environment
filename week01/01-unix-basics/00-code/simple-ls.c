#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <errno.h>
#include <string.h>

DIR *opendir(const char *name);
int closedir(DIR *dirp);

int main(int argc, char **argv) {
  if (argc != 2) {
    fprintf(stderr, "usage: %s dir_name\n", argv[0]);
    exit(EXIT_FAILURE);
  }


  DIR *d;
  struct dirent *dir;

  if ((d = opendir(argv[1])) == NULL) {
    fprintf(stderr, "error opening dir %s, err: %s\n", argv[1],
        strerror(errno));

    exit(EXIT_FAILURE);
  }

  while((dir = readdir(d)) != NULL) {
    printf("%s\n", dir->d_name);
  }

  closedir(d);

  return EXIT_SUCCESS;
}
