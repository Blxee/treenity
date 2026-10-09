#include "server.h"
#include <stdio.h>
#include <stdlib.h>


int server_error_print(t_server_error err)
{
  if (err == ARG_ERR_EXTRA)
    dprintf(2, "[Error]: extra argument.\n");
  return err;
}

int create_fifo_pipe(char **identifier)
{
  *identifier = malloc(123);
  return 0;
}

int main(int argc, char** argv)
{
  int err;
  char *identifier;
  
  (void)argv;
  if (argc > 1)
  {
    server_error_print(ARG_ERR_EXTRA);
    printf(SERVER_USAGE);
    return ARG_ERR_EXTRA;
  }
  err = create_fifo_pipe(&identifier);
  if (err)
    return server_error_print(err);
  free(identifier);
  return 0;
}
