#include <stdio.h>
#include <string.h>

typedef enum e_args_error {
  ARG_ERR_MISSING = 1,
  ARG_ERR_EXTRA = 2,
  ARG_ERR_UNKNOWN = 3,
} t_args_error;

void args_error_print(t_args_error err)
{
  if (err == ARG_ERR_MISSING)
    printf("[Error]: missing argument.\n");
  else if (err == ARG_ERR_EXTRA)
    printf("[Error]: extra argument.\n");
  else if (err == ARG_ERR_UNKNOWN)
    printf("[Error]: unkown argument.\n");
}

typedef enum t_command {
  CMD_CREATE = 0,
  CMD_LIST = 1,
  CMD_PRODUCE = 2,
  CMD_SUBSCRIBE = 3,
  CMD_INFO = 4,
} t_command;

typedef struct args_s {
  char *ipc_identifier;
  t_command command;
} args_t;

int args_parse_common(int argc, char** argv, args_t *args)
{
  if (argc < 3)
    return ARG_ERR_MISSING;
  args->ipc_identifier = argv[1];
  if (strcmp(argv[2], "create") == 0)
    args->command = CMD_CREATE;
  else if (strcmp(argv[2], "list") == 0)
    args->command = CMD_LIST;
  else if (strcmp(argv[2], "produce") == 0)
    args->command = CMD_PRODUCE;
  else if (strcmp(argv[2], "subscribe") == 0)
    args->command = CMD_SUBSCRIBE;
  else if (strcmp(argv[2], "info") == 0)
    args->command = CMD_INFO;
  else
    return ARG_ERR_UNKNOWN;
  return 0;
}

void cmd_create(int argc, char** argv)
{
  (void)argc;
  (void)argv;
  printf("cmd_create was called..\n");
}

void cmd_list(int argc, char** argv)
{
  (void)argc;
  (void)argv;
  printf("cmd_list was called..\n");
}

void cmd_produce(int argc, char** argv)
{
  (void)argc;
  (void)argv;
  printf("cmd_produce was called..\n");
}

void cmd_subscribe(int argc, char** argv)
{
  (void)argc;
  (void)argv;
  printf("cmd_subscribe was called..\n");
}

void cmd_info(int argc, char** argv)
{
  (void)argc;
  (void)argv;
  printf("cmd_info was called..\n");
}

#define USAGE "\
Usage: client <ipd_identifier> <subcommand>\n\
    Subcommands:\n\
        create\n\
        list\n\
        produce\n\
        subscribe\n\
        info\n"

int main(int argc, char** argv)
{
  args_t args;
  int err;

  err = args_parse_common(argc, argv, &args);
  if (err)
  {
    args_error_print(err);
    printf(USAGE);
    return err;
  }
  printf("hello world from client\n");
  return 0;
}
