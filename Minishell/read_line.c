#include "stdio.h"

char		*read_line()
{
  char		*line;
  size_t	n;

  line = NULL;
  n = 0;
  getline(&line, &n, stdin);
  return (line);
}
