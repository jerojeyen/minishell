#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "minishell.h"

char		*my_strcat(char *dest, char *src)
{
  int		i;
  int		j;

  j = 0;
  i = 0;
  while (dest[j])
    j++;
  while (src[i] != '\0')
    {
      dest[j] = src[i];
      j++;
      i++;
    }
  return (dest);
}

char		*get_var_env(char *name, t_info *info)
{
  char		*n;

  *name++;
  n = my_getenv(info, name);
  if (n == NULL)
    {
      fprintf(stderr, "%s doesn't exist\n", name);
      return (NULL);
    }
  else
    return (n);
}

char		*replace_tild(char *str, t_info *info)
{
  char		*n;
  char		*new_st;

  new_st = NULL;
  if (strlen(str) > 1)
    return (replace_other_tild(str, info));
  if ((n = my_getenv(info, "HOME")) != NULL)
    {
      new_st = my_memset((strlen(str) + strlen(n)) * sizeof(char), '\0');
      if (new_st == NULL)
	return (NULL);
      *str++;
      new_st = my_strcat(new_st, n);
      new_st = my_strcat(new_st, str);
      free(n);
      return (new_st);
    }
  else
    return (NULL);
}

int		check_particular(t_string **ls, t_info *info)
{
  t_string	*sv;
  char		*chg;

  sv = *ls;
  while ((*ls))
    {
      chg = NULL;
      if ((*ls)->st[0] == '$')
	chg = get_var_env((*ls)->st, info);
      else if ((*ls)->st[0] == '~')
	chg = replace_tild((*ls)->st, info);
      if (chg != NULL)
	{
	  free((*ls)->st);
	  (*ls)->st = strdup(chg);
	  free(chg);
	}
      *ls = (*ls)->next;
    }
  *ls = sv;
  return (RETURN_SUCCESS);
}
