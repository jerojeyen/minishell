#include <sys/types.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "minishell.h"

void		execute(char *line, char **tab)
{
  pid_t		pid;
  int		statut;

  pid = fork();
  if (pid)
    wait(&statut);
  else
    {
      if (execve(line, tab, NULL) == -1)
	kill(pid);
    }
}

int		check_line(char *path, t_info *info)
{
  char		*line;

  if ((line = malloc((strlen(info->tab_cmd[0]) + strlen(path) + 2) *
		     sizeof(char))) == NULL)
    return (RETURN_ERROR);
  memset(line, '\0', (strlen(info->tab_cmd[0]) + strlen(path) + 2));
  line = strcat(line, path);
  line = strcat(line, "/");
  line = strcat(line, info->tab_cmd[0]);
  if (access(line, F_OK | X_OK) == 0)
    {
      execute(line, info->tab_cmd);
      memset(line, '\0', strlen(line));
      free(line);
      return (RETURN_SUCCESS);
    }
  memset(line, '\0', strlen(line));
  free(line);
  return (RETURN_ERROR);
}

int		find_full_path(t_info *info)
{
  char		*path;
  int		i;
  char		*line;
  char		*tp;

  i = 0;
  path = my_getenv(info, "PATH");
  if (path == NULL)
    return (error_int("Variable PATH doesn't exist", 1));
  tp = strtok(path, ":");
  check_line(tp, info);
  while ((tp = strtok(NULL, ":")))
    {
      if (check_line(tp, info) == RETURN_SUCCESS)
	{
	  free(path);
	  return (RETURN_SUCCESS);
	}
      memset(tp, '\0', strlen(tp));
    }
  free(tp);
  free(path);
  return (RETURN_ERROR);
}

int		do_binaries(t_info *info)
{
  if (access(info->tab_cmd[0], F_OK | X_OK) == 0)
    {
      execute(info->tab_cmd[0], info->tab_cmd);
      return (RETURN_SUCCESS);
    }
  else
    return (find_full_path(info));
  return (RETURN_ERROR);
}
