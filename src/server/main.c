#include "server.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>


int server_error_print(t_server_error err)
{
  if (err == ARG_ERR_EXTRA)
    dprintf(2, "[Error]: extra argument.\n");
  else if (err == IO_PIPE_CREATE_ERROR)
    dprintf(2, "[Error]: could not create pipe.\n");
  else if (err == IO_PIPE_OPEN_ERROR)
    dprintf(2, "[Error]: could not open pipe.\n");
  else if (err == IO_PIPE_CLOSE_ERROR)
    dprintf(2, "[Error]: could not close pipe.\n");
  return err;
}

t_server_error pipe_create(t_pipe *pipe)
{
  pipe->path = "operator.server.1337";
  if(mkfifo(pipe->path, 0666) == -1)
    return IO_PIPE_CREATE_ERROR;
  pipe->fd = open(pipe->path, O_RDWR | O_TRUNC);
  if (pipe->fd == -1)
    return IO_PIPE_OPEN_ERROR;
  return 0;
}

int pipe_destroy(t_pipe *pipe)
{
  if (close(pipe->fd) == -1)
    return IO_PIPE_CLOSE_ERROR;
  if (unlink(pipe->path) == -1)
    return IO_PIPE_CLOSE_ERROR;
  return 0;
}

int main(int argc, char** argv)
{
  int err;
  t_pipe pipe;
  
  (void)argv;
  if (argc > 1)
  {
    server_error_print(ARG_ERR_EXTRA);
    printf(SERVER_USAGE);
    return ARG_ERR_EXTRA;
  }
  err = pipe_create(&pipe);
  if (err)
    return server_error_print(err);
  printf("%s\n", pipe.path);
  err = pipe_destroy(&pipe);
  if (err)
    return server_error_print(err);
  return 0;
}
