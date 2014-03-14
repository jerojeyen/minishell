#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "minishell.h"

int		do_pwd(t_info *info)
{
  char		*buf;
  char		*res;

  res = NULL;
  buf = NULL;
  res = getcwd(buf, 150);
  if (res != NULL)
    {
      maj_env(info, "PWD", res);
      printf("%s\n", res);
      free(buf);
      free(res);
    }
  return (RETURN_SUCCESS);
}
