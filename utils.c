
/* utils.c
   Auxiliary functions, definitions and macros.
*/

#include <stdio.h>
#include <stdlib.h>

#include "utils.h"

FILE *
xfopen (char *filename, char *mode)
{
  FILE *fp;

  fp = fopen (filename, mode);

  if (fp == NULL)
    die ("Could not open file `%s`", filename);
  return fp;
}

void *
xmalloc (size_t size)
{
  void *value = malloc (size);

  if (value == NULL)
    die ("Virtual memory exhausted");

  return value;
}
