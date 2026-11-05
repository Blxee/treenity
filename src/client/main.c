#include <stdio.h>
#include "client.h"

int main(int argc, char** argv)
{
  t_args args;
  int err;

  err = args_parse_common(argc, argv, &args);
  if (err)
  {
    client_error_print(err);
    printf(CLIENT_USAGE);
    return err;
  }
  if (args.command == CMD_CREATE)
    err = cmd_create(argc, argv);
  else if (args.command == CMD_LIST)
    err = cmd_list(argc, argv);
  else if (args.command == CMD_PRODUCE)
    err = cmd_produce(argc, argv);
  else if (args.command == CMD_SUBSCRIBE)
    err = cmd_subscribe(argc, argv);
  else if (args.command == CMD_INFO)
    err = cmd_info(argc, argv);
  if (err) {
    client_error_print(err);
    return (err);
  }

  return 0;
}
