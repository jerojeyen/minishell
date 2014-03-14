#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "minishell.h"

char		*get_pwd()
{
  char		*buf;
  char		*res;

  res = NULL;
  buf = NULL;
  res = getcwd(buf, 150);
  if (res != NULL)
    free(buf);
  return (res);
}

int		do_cd_moins(t_info *info, char *save)
{
  char		*path;

  if ((path = my_getenv(info, "OLDPWD")) == NULL)
    return (error_int("my_getenv : Variable OLDPWD doesn't exist",
		      RETURN_SUCCESS));
  if (chdir(path) != -1)
    {
      maj_env(info, "OLDPWD", save);
      maj_env(info, "PWD", get_pwd());
    }
  return (RETURN_SUCCESS);
}

int		do_cd_normal(t_info *info, char *save)
{
  char		*path;

  if ((path = my_getenv(info, "HOME")) == NULL)
    return (error_int("my_getenv : Variable HOME doesn't exist",
		      RETURN_SUCCESS));
  if (chdir(path) != -1)
    {
      maj_env(info, "OLDPWD", save);
      maj_env(info, "PWD", get_pwd());
    }
  return (RETURN_SUCCESS);
}

int		do_cd(t_info *info)
{
  char		*path;
  char		*save;

  save = get_pwd();
  if (info->tab_cmd[1])
    {
      if (strcmp(info->tab_cmd[1], "-") == 0)
	return (do_cd_moins(info, save));
      else
	{
	  if (chdir(info->tab_cmd[1]) == -1)
	    fprintf(stderr, "%s : Aucun dossier de ce type\n", info->tab_cmd[1]);
	  maj_env(info, "OLDPWD", save);
	  maj_env(info, "PWD", get_pwd());
	}
    }
  else
    return (do_cd_normal(info, save));
}
