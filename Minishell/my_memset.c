#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "minishell.h"

char		*my_memset(int len, char c)
{
  char		*res;
  int		i;

  i = 0;
  res = malloc(len * sizeof(char));
  if (res == NULL)
    return (NULL);
  while (i != len)
    {
      res[i] = c;
      i++;
    }
  return (res);
}
