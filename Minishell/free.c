#include <stdio.h>
#include <stdlib.h>
#include "minishell.h"

void		free_info_tab(char ***tab)
{
  int		i;

  i = 0;
  while ((*tab)[i])
    {
      free((*tab)[i]);
      i++;
    }
  free(*tab);
}

void		free_ls(t_string **ls)
{
  t_string	*prev;

  while (*ls)
    {
      free((*ls)->st);
      prev = (*ls);
      (*ls) = (*ls)->next;
      free(prev);
    }
}
