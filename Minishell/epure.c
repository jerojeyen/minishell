#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "minishell.h"

int		count_letter(char *line, int pos)
{
  int		count;

  count = 0;
  while (line[pos] != '\0')
    {
      if (line[pos] == ' ' || line[pos] == '\t' || line[pos] == '\n')
	return (count);
      pos++;
      count++;
    }
  return (count);
}

void		add_end_ls(t_string **ls, t_string **new)
{
  t_string	*deb;

  deb = *ls;
  if (*ls == NULL)
    *ls = *new;
  else
    {
      while ((*ls)->next)
	*ls = (*ls)->next;
      (*ls)->next = *new;
      *ls = deb;
    }
}

int		get_word(char *line, int pos, t_string **ls)
{
  t_string	*new;
  int		j;

  j = 0;
  if ((new = malloc(sizeof(new))) == NULL)
    return (error_int("get_word : Error Malloc", 2));
  if ((new->st = malloc((count_letter(line, pos) + 1) * sizeof(char))) == NULL)
    return (error_int("get_word : Error Malloc", 2));
  while (line[pos] != ' ' && line[pos] != '\0'
	 && line[pos] != '\t' && line[pos] != '\n')
    {
      new->st[j] = line[pos];
      pos++;
      j++;
    }
  new->st[j] = '\0';
  new->next = NULL;
  add_end_ls(ls, &new);
  return (pos);
}

int		count_malloc(t_string *ls)
{
  int		i;

  i = 0;
  while (ls)
    {
      i += strlen(ls->st);
      if (ls->next != NULL)
	i++;
      ls = ls->next;
    }
  return (i);
}

char		*epure(char *line, t_info *info)
{
  int		i;
  t_string	*ls;
  char		*n_line;

  i = 0;
  ls = NULL;
  n_line = NULL;
  if (line != NULL)
    {
      while (line[i] != '\0')
	{
	  if (line[i] != ' ' && line[i] != '\t' && line[i] != '\n')
	    {
	      i = get_word(line, i, &ls);
	    }
	  i++;
	}
      check_particular(&ls, info);
      n_line = do_new_line(ls);
      free_ls(&ls);
      free(line);
      return (n_line);
    }
  return (NULL);
}
