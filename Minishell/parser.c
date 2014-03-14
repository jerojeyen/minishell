#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "minishell.h"

int		parser(t_info *info)
{
  int		ret;

  ret = do_cmd(info);
  if (ret == RETURN_EXIT)
    return (RETURN_EXIT);
  else if (ret == RETURN_ERROR)
    {
      ret = do_binaries(info);
      if (ret == RETURN_ERROR)
	printf("%s : Command Not Found\n", info->cmd);
    }
  return (RETURN_SUCCESS);
}
