#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define WRITE_STRING "This is a nice day"

int main(void) {
  int fd = open("ex1.txt", O_RDWR);
  char *string = WRITE_STRING;
  struct stat file_stat;
  ftruncate(fd, strlen(string));
  stat("ex1.txt", &file_stat);

  char *file_addr = mmap(NULL, file_stat.st_size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
  memcpy(file_addr, string, strlen(string));

  munmap(file_addr, file_stat.st_size);
  close(fd);

  return 0;
}
