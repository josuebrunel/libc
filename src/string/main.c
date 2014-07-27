#include "sl_strlen.h"
#include <stdio.h>

int main(int argc, char *argv[])
{
  char* str = "Jon Doe";
  printf ("len of %s is %i\n",str, sl_stren(str));
  return 0;
}
