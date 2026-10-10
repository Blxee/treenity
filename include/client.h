#ifndef CLIENT_H
# define CLIENT_H

#include <stdio.h>

typedef enum t_command {
  CMD_CREATE = 0,
  CMD_LIST = 1,
  CMD_PRODUCE = 2,
  CMD_SUBSCRIBE = 3,
  CMD_INFO = 4,
} t_command;

typedef struct s_args {
  char *ipc_identifier;
  t_command command;
} t_args;

typedef enum e_client_error {
  ARG_ERR_MISSING = 1,
  ARG_ERR_EXTRA,
  ARG_ERR_UNKNOWN,
} t_client_error;

# define CLIENT_USAGE "\
Usage: client <ipc_identifier> <subcommand>\n\
    Subcommands:\n\
        create\n\
        list\n\
        produce\n\
        subscribe\n\
        info\n"

int client_error_print(t_client_error err);
int args_parse_common(int argc, char** argv, t_args *args);

void cmd_create(int argc, char** argv);
void cmd_list(int argc, char** argv);
void cmd_produce(int argc, char** argv);
void cmd_subscribe(int argc, char** argv);
void cmd_info(int argc, char** argv);

#endif

