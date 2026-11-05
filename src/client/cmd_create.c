#include "client.h"
#include <stdio.h>
#include <unistd.h>

int cmd_create(int argc, char** argv)
{
  if (argc < 4)
    return CLIENT_ERR_MISSING_ARG;
  int fd = fifo_open(argv[1]);
  printf("fd: %d\n", fd);
  write(fd, "hello from client", 17);

  printf("cmd_create was called..\n");
  return (0);
}
