#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "minishell.h"

void		free_env(t_env **env)
{
  t_env		*prev;

  while (*env)
    {
      free((*env)->name);
      free((*env)->value);
      prev = (*env);
      (*env) = (*env)->next;
      free(prev);
    }
}

int		maj_env(t_info *info, char *name, char *value)
{
  t_env		*deb;
  int		indic;

  indic = 0;
  deb = info->env;
  while (deb)
    {
      if (strcmp(deb->name, name) == 0)
	{
	  free(deb->value);
	  deb->value = strdup(value);
	  indic = 1;
	}
      deb = deb->next;
    }
  if (indic == 0)
    add_value_env(name, value, info);
}

int		add_value_env(char *name, char *value, t_info *info)
{
  t_env		*new;

  if ((new = malloc(sizeof(t_env *))) == NULL)
    return (error_int("add_value : Error Malloc", 2));
  if (name != NULL)
    if ((new->name = strdup(name)) == NULL)
      return (error_int("add_value : Error Strdup", 2));
  if (value != NULL)
    if ((new->value = strdup(value)) == NULL)
      return (error_int("add_value: Error Strdup", 2));
  new->next = info->env;
  info->env = new;
}

void		aff_env(t_info *info)
{
  t_env		*deb;

  deb = info->env;
  while (deb)
    {
      printf("%s = %s\n", deb->name, deb->value);
      deb = deb->next;
    }
}
