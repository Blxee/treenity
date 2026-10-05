#include <stdio.h>
#include "client.h"

int main(int argc, char** argv)
{
  t_args args;
  int err;

  err = args_parse_common(argc, argv, &args);
  if (err)
  {
    args_error_print(err);
    printf(USAGE);
    return err;
  }
  if (args.command == CMD_CREATE)
    cmd_create(argc, argv);
  else if (args.command == CMD_LIST)
    cmd_list(argc, argv);
  else if (args.command == CMD_PRODUCE)
    cmd_produce(argc, argv);
  else if (args.command == CMD_SUBSCRIBE)
    cmd_subscribe(argc, argv);
  else if (args.command == CMD_INFO)
    cmd_info(argc, argv);
  return 0;
}
