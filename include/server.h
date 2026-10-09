#ifndef SERVER_H
# define SERVER_H

typedef enum e_server_error {
  ARG_ERR_EXTRA = 1,
} t_server_error;

# define SERVER_USAGE "\
Usage: server\n\
        prints IPC identifier\n"

int server_error_print(t_server_error err);

#endif

