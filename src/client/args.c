#include <string.h>
#include "client.h"

int client_error_print(t_client_error err)
{
  if (err == ARG_ERR_MISSING)
    dprintf(2, "[Error]: missing argument.\n");
  else if (err == ARG_ERR_EXTRA)
    dprintf(2, "[Error]: extra argument.\n");
  else if (err == ARG_ERR_UNKNOWN)
    dprintf(2, "[Error]: unkown argument.\n");
  return err;
}

int args_parse_common(int argc, char** argv, t_args *args)
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

