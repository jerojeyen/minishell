#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "minishell.h"

char		*do_new_line(t_string *ls)
{
  int		value;
  char		*line;

  line = NULL;
  if (ls != NULL)
    {
      value = count_malloc(ls);
      if ((line = malloc((value + 1) * sizeof(char))) == NULL)
		return (NULL);
      memset(line, '\0', value + 1);
      while (ls)
	{
	  line = strcat(line, ls->st);
	  if (ls->next != NULL)
	    line = strcat(line, " ");
	  ls = ls->next;
	}
      return (line);
    }
  return (NULL);
}

