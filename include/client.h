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

typedef enum e_args_error {
  ARG_ERR_MISSING = 1,
  ARG_ERR_EXTRA = 2,
  ARG_ERR_UNKNOWN = 3,
} t_args_error;

#define USAGE "\
Usage: client <ipc_identifier> <subcommand>\n\
    Subcommands:\n\
        create\n\
        list\n\
        produce\n\
        subscribe\n\
        info\n"

void args_error_print(t_args_error err);
int args_parse_common(int argc, char** argv, t_args *args);

void cmd_create(int argc, char** argv);
void cmd_list(int argc, char** argv);
void cmd_produce(int argc, char** argv);
void cmd_subscribe(int argc, char** argv);
void cmd_info(int argc, char** argv);

#endif

