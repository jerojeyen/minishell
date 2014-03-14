#include <unistd.h>
#include <string.h>
#include "minishell.h"

t_cmd		cmd[7] = {
  {"exit", do_exit},
  {"env", do_env},
  {"pwd", do_pwd},
  {"cd", do_cd},
  {"setenv", do_setenv},
  {"unsetenv", do_unsetenv},
  {NULL, NULL}
};

int		do_cmd(t_info *info)
{
  int		i;

  i = 0;
  while (cmd[i].name)
    {
      if (strcmp(cmd[i].name, info->tab_cmd[0]) == 0)
	return (cmd[i].ptr_func(info));
      i++;
    }
  return (RETURN_ERROR);
}
