#ifndef SERVER_H
# define SERVER_H

typedef enum e_server_error {
  ARG_ERR_EXTRA = 1,
  IO_PIPE_CREATE_ERROR,
  IO_PIPE_OPEN_ERROR,
  IO_PIPE_CLOSE_ERROR,
} t_server_error;

typedef struct s_pipe {
  char *path;
  int fd;
} t_pipe;

# define SERVER_USAGE "\
Usage: server\n\
        prints IPC identifier\n"

int server_error_print(t_server_error err);

t_server_error pipe_create(t_pipe *pipe);
int pipe_destroy(t_pipe *pipe);

#endif

