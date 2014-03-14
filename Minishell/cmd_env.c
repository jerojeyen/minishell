#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "minishell.h"

int		do_setenv(t_info *info)
{
  if (info->tab_cmd[1] && info->tab_cmd[2])
    {
      maj_env(info, info->tab_cmd[1], info->tab_cmd[2]);
    }
  else
    fprintf(stderr, "SETENV : Error bad arguments\n");
  return (RETURN_SUCCESS);
}

int		do_erase(t_info *info, t_env **deb, t_env **prev)
{
  if (*prev == NULL)
    info->env = (*deb)->next;
  else
    (*prev)->next = (*deb)->next;
  free((*deb)->name);
  free((*deb)->value);
  free(*deb);
  return (RETURN_SUCCESS);
}

int		do_unsetenv(t_info *info)
{
  t_env		*deb;
  t_env		*prev;

  prev = NULL;
  deb = info->env;
  if (info->tab_cmd[1])
    {
      while (deb)
	{
	  if (strcmp(deb->name, info->tab_cmd[1]) == 0)
	    return (do_erase(info, &deb, &prev));
	  prev = deb;
	  deb = deb->next;
	}
      fprintf(stderr, "UNSETENV : %s doesn't Exist\n", info->tab_cmd[1]);
      return (RETURN_SUCCESS);
    }
  fprintf(stderr, "UNSETENV : Need an argument\n");
  return (RETURN_SUCCESS);
}
