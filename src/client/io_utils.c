#include "client.h"
#include <fcntl.h>
#include <unistd.h>

int fifo_open(char *path)
{
  return (open(path, O_RDWR));
}

