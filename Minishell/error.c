#include <stdio.h>

int		error_int(char *msg, int ret)
{
  fprintf(stderr, "%s\n", msg);
  return (ret);
}
