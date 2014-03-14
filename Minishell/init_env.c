#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "minishell.h"

int		init_env(t_info *info)
{
  extern char	**environ;
  int		i;
  char		*name;
  char		*value;

  i = 0;
  info->env = NULL;
  while (environ[i])
    {
      name = strtok(environ[i], "=");
      value = strtok(NULL, "=");
      if (add_value_env(name, value, info) == RETURN_EXIT)
		return (RETURN_EXIT);
      i++;
    }
  return (1);
}
