#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "minishell.h"

int		minishell(t_info *info)
{
  int		ret;
  char	*res;

  ret = 0;
  while (ret == 0)
    {
      printf("%s", PROMPT);
      if ((info->cmd = epure(read_line(), info)) != NULL)
	{
	  if ((info->tab_cmd = make_table(info->cmd, " ")) != NULL)
	    {
	      if (parser(info) == RETURN_EXIT)
			return (RETURN_EXIT);
	      free_info_tab(&info->tab_cmd);
	    }
	  free(info->cmd);
	  info->cmd = NULL;
	  info->tab_cmd = NULL;
	}
      else
	printf("\n");
    }
  return (RETURN_SUCCESS);
}

int		init_info(t_info *info)
{
  info->env = NULL;
  info->cmd = NULL;
  info->tab_cmd = NULL;
  return (RETURN_SUCCESS);
}

int		main(int ac, char **av)
{
  t_info	info;

  if (init_info(&info) == RETURN_EXIT)
    return (RETURN_EXIT);
  init_env(&info);
  minishell(&info);
  free_env(&info.env);
  free(info.cmd);
  free_info_tab(&info.tab_cmd);
}
