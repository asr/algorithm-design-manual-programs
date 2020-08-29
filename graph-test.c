
/* graph-test.c
   Testing graph library.
*/

#include <error.h>
#include <stdlib.h>

#include "bool.h"
#include "graph.h"
#include "utils.h"

int
main (void)
{
  graph g;

  /* Reading an undirected graph. */
  fread_graph ("datafiles/g-k4", &g, FALSE);
  print_graph (&g);
  printf("\n");

  /* Reading an directed graph. */
  fread_graph ("datafiles/g1", &g, TRUE);
  print_graph (&g);
}
