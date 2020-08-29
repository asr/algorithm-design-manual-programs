
/* utils.h
   Auxiliary functions, definitions and macros.
*/

#include <error.h>
#include <stdio.h>

/* Exit with an error message */
#define die(...) error (1, 0, __VA_ARGS__)

/* Safe fopen */
FILE * xfopen (char *filename, char *mode);

/* Safe malloc */
void * xmalloc (size_t size);
