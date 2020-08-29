
/*      graph.c

        A generic adjacency list graph data type.

        by: Steven Skiena
        begun: March 6, 2002

*/

/*
Copyright 2003 by Steven S. Skiena; all rights reserved.

Permission is granted for use in non-commerical applications
provided this copyright notice remains intact and unchanged.

This program appears in my book:

"Programming Challenges: The Programming Contest Training Manual"
by Steven Skiena and Miguel Revilla, Springer-Verlag, New York 2003.

See our website www.programming-challenges.com for additional information.

This book can be ordered from Amazon.com at

http://www.amazon.com/exec/obidos/ASIN/0387001638/thealgorithmrepo/

*/

#include <stdio.h>
#include <stdlib.h>

#include "graph.h"
#include "queue.h"
#include "utils.h"

/* [[[ init_graph_c */
void
initialize_graph (graph * g, bool directed)
{
  int i;                        /* counter */

  g->nvertices = 0;
  g->nedges = 0;
  g->directed = directed;

  for (i = 1; i <= MAXV; i++)
    {
      g->degree[i] = 0;
    }

  for (i = 1; i <= MAXV; i++)
    {
      g->edges[i] = _NULL;
    }
}

/* ]]] */

/* [[[ insert_edge_cut */
void
insert_edge (graph * g, int x, int y, bool directed)
{
  edgenode *p;                  /* temporary pointer */

  p = malloc (sizeof (edgenode));       /* allocate storage for edgenode */

  p->weight = _NULL;
  p->y = y;
  p->next = g->edges[x];

  g->edges[x] = p;              /* insert at head of list */

  g->degree[x]++;

  if (directed == FALSE)
    {
      insert_edge (g, y, x, TRUE);
    }
  else
    {
      g->nedges++;
    }
}

/* ]]] */

/* [[[ fread_graph_cut */
void
fread_graph (char *filename, graph *g, bool directed)
{
  int i;     /* Counter */
  int m;     /* Number of edges */
  int x, y;  /* Vertices in edge (x,y) */
  FILE *fp;  /* Temporary file pointer */

  initialize_graph (g, directed);

  if (filename == NULL)
    fp = stdin;
  else
    fp = xfopen (filename, "r");

  if (fscanf (fp, "%d %d", &(g->nvertices), &m) == 0)
    die ("Error reading the number of vertices or the number of edges");

  if ( m > MAXV )
    die ("The graph has too many vertices: %d (maximun allowed is %d)",
         m, MAXV);

  for (i = 1; i <= m; i++)
    {
      if (fscanf (fp, "%d %d", &x, &y) == 0)
        die ("Error reading an edge");

      insert_edge (g, x, y, directed);
    }
}

/* ]]] */

void
delete_edge (graph * g, int x, int y, bool directed)
{
  edgenode *p, *p_back;         /* temporary pointers */

  p = g->edges[x];
  p_back = _NULL;

  while (p != _NULL)
    {
      if (p->y == y)
        {
          g->degree[x]--;
          if (p_back != _NULL)
            {
              p_back->next = p->next;
            }
          else
            {
              g->edges[x] = p->next;
            }
          free (p);
          if (directed == FALSE)
            {
              delete_edge (g, y, x, TRUE);
            }
          else
            {
              g->nedges--;
            }
          return;
        }
      else
        {
          p = p->next;
        }
    }
  printf ("Warning: deletion(%d,%d) not found in g.\n", x, y);
}

/* [[[ print_graph_cut */
void
print_graph (graph * g)
{
  int i;                        /* counter */
  edgenode *p;                  /* temporary pointer */

  for (i = 1; i <= g->nvertices; i++)
    {
      printf ("%d: ", i);
      p = g->edges[i];
      while (p != _NULL)
        {
          printf (" %d", p->y);
          p = p->next;
        }
      printf ("\n");
    }
}

/* ]]] */
