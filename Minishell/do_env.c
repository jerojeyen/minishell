#include <stdio.h>
#include "minishell.h"

int		do_env(t_info *info)
{
  t_env		*deb;

  deb = info->env;
  while (deb)
    {
      printf("%s=%s\n", deb->name, deb->value);
      deb = deb->next;
    }
  return (0);
}
