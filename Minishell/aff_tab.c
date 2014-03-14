#include <stdio.h>

void		aff_tab(char **tab)
{
  int		i;

  i = 0;
  while (tab[i])
    {
      printf("%s\n", tab[i]);
      i++;
    }
}
