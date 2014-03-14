#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "minishell.h"

int		count_back(char *s)
{
  int		i;
  int		count;

  count = 0;
  i = 0;
  while (s[i])
    {
      if (s[i] == '/')
	count++;
      i++;
    }
  return (count);
}

int		count_char(char *s, int fin)
{
  int		count;
  int		i;

  i = 0;
  count = 0;
  while (fin != 1)
    {
      if (s[i] == '/')
	fin--;
      else
	count++;
      i++;
    }
}

char		*get_base_home(char *s)
{
  int		fin;
  char		*new;
  int		i;

  i = 0;
  fin = count_back(s);
  new = my_memset((count_char(s, fin) + 1) * sizeof(char), '\0');
  if (new == NULL)
    return (NULL);
  while (fin != 0)
    {
      if (s[i] == '/')
	fin--;
      new[i] = s[i];
      i++;
    }
  return (new);
}

char		*replace_other_tild(char *str, t_info *info)
{
  char		*n;
  char		*home;
  char		*new_st;

  *str++;
  if ((n = my_getenv(info, "HOME")) != NULL)
    {
      home = get_base_home(n);
      new_st = my_memset((strlen(home) + strlen(str) + 1) * sizeof(char), '\0');
      if (new_st == NULL)
	return (NULL);
      new_st = my_strcat(new_st, home);
      new_st = my_strcat(new_st, str);
      return (new_st);
    }
  return (NULL);
}
