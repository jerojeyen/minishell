#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include "minishell.h"

int		count_word(char *line)
{
  int		i;
  int		count;

  i = 0;
  count = 0;
  while (line[i])
    {
      if (line[i] == ' ')
	count++;
      i++;
    }
  return (count + 1);
}

char		**make_table(char *line, char *delim)
{
  char		**tab;
  char		*cmd;
  int		i;

  i = 0;
  if ((tab = malloc((count_word(line) + 1) * sizeof(char*))) == NULL)
    return (NULL);
  cmd = strtok(line, delim);
  if ((tab[i] = strdup(cmd)) == NULL)
    return (NULL);
  i++;
  while (cmd != NULL)
    {
      cmd = strtok(NULL, delim);
      if (cmd != NULL)
	{
	  if ((tab[i] = strdup(cmd)) == NULL)
	    return (NULL);
	  i++;
	}
    }
  tab[i] = NULL;
  return (tab);
}
