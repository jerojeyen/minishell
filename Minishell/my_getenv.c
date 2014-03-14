#include <stdio.h>
#include <string.h>
#include "minishell.h"

char		*my_getenv(t_info *info, char *name)
{
  t_env		*deb;

  deb = info->env;
  while (deb)
    {
      if (strcmp(deb->name, name) == 0)
	{
	  if (deb->value != NULL)
	    return (strdup(deb->value));
	}
      deb = deb->next;
    }
  return (NULL);
}
