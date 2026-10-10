#ifndef SERVER_H
# define SERVER_H

typedef enum e_server_error {
  SERVER_ERR_EXTRA_ARG = 1,
  SERVER_ERR_CREATE_PIPE,
  SERVER_ERR_OPEN_PIPE,
  SERVER_ERR_CLOSE_PIPE,
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
t_server_error pipe_destroy(t_pipe *pipe);

#endif

