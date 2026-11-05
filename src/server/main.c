#include "server.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <signal.h>
#include <stdlib.h>
#include <poll.h>

static t_pipe globa_pipe;

int server_error_print(t_server_error err)
{
  if (err == SERVER_ERR_EXTRA_ARG)
    dprintf(2, "[Error]: extra argument.\n");
  else if (err == SERVER_ERR_CREATE_PIPE)
    dprintf(2, "[Error]: could not create pipe.\n");
  else if (err == SERVER_ERR_OPEN_PIPE)
    dprintf(2, "[Error]: could not open pipe.\n");
  else if (err == SERVER_ERR_CLOSE_PIPE)
    dprintf(2, "[Error]: could not close pipe.\n");
  return err;
}

t_server_error pipe_create(t_pipe *pipe)
{
  pipe->path = "operator.server.1337";
  if(mkfifo(pipe->path, 0666) == -1)
    return SERVER_ERR_CREATE_PIPE;
  pipe->fd = open(pipe->path, O_RDWR | O_TRUNC);
  if (pipe->fd == -1)
    return SERVER_ERR_OPEN_PIPE;
  return 0;
}

t_server_error pipe_listen(t_pipe *pipe)
{
  struct pollfd fds[1];
  char buffer[1024] = {0};

  fds[0].fd = pipe->fd;
  fds[0].events = POLLIN;
  while (1)
  {
    poll(fds, 1, -1);
    read(pipe->fd, &buffer, sizeof(buffer));
    printf("recieved: '%s'\n", buffer);
  }
  return 0;
}

t_server_error pipe_destroy(t_pipe *pipe)
{
  if (close(pipe->fd) == -1)
    return SERVER_ERR_CLOSE_PIPE;
  if (unlink(pipe->path) == -1)
    return SERVER_ERR_CLOSE_PIPE;
  return 0;
}

void signal_handler(int signum)
{
  int err;
  
  (void)signum;
  printf("\ninterrupted by user..\n");
  err = pipe_destroy(&globa_pipe);
  if (err)
    server_error_print(err);
  exit(0);
}

int main(int argc, char** argv)
{
  int err;
  
  (void)argv;
  if (argc > 1)
  {
    server_error_print(SERVER_ERR_EXTRA_ARG);
    printf(SERVER_USAGE);
    return SERVER_ERR_EXTRA_ARG;
  }
  signal(SIGTERM, signal_handler);
  signal(SIGINT, signal_handler);
  err = pipe_create(&globa_pipe);
  if (err)
    return server_error_print(err);
  printf("%s\n", globa_pipe.path);
  pipe_listen(&globa_pipe);
  err = pipe_destroy(&globa_pipe);
  if (err)
    return server_error_print(err);
  return 0;
}
/*
typedef struct _s_map_node {
  int hash;
  char value;
} _t_map_node;

typedef struct s_hashmap {
  _t_map_node array;
} t_hashmap;

# define HASH_MAP_INIT_CAPACITY (1024)

t_server_error map_create(t_hashmap *map)
{
  map
  return 0;
}

int main()
{
  return 0;
}
*/
