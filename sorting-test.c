
/* sorting-test.c
   Testing sorting library.
*/

/* #include <math.h> */
#include <stdio.h>
/* #include <stdlib.h> */

/* #include "bool.h" */
/* #include "priority_queue.h" */
/* #include "queue.h" */
#include "random.h"

#include "sorting.h"

/* Initialise array */
void
initialise_array (item_type s[], int n)
{
  int i;

  for (i = 0; i < n; i++)
    s[i] = n - i;
}

/* Print sorted array */
void
print_sorted_array (item_type s[], int n, char *sort_algorithm)
{
  int i;

  printf ("\n\n%s:\n", sort_algorithm);
  for (i = 0; i < n; i++)
    printf ("%d ", s[i]);
}

int
main (void)
{
  int s[NELEM + 2];
  int i;                        /* counters */

  initialise_array (s, NELEM);
  random_permutation (s, NELEM);

  /* ASR (2020-08-26) We can not print the random array because it
     breaks the test suite. */
  /* printf ("\n\nRandom array: \n"); */
  /* for (i = 0; i < NELEM; i++) */
  /*   printf ("%d ", s[i]); */

  insertion_sort (s, NELEM);
  print_sorted_array (s, NELEM, "Insertion sort");

  initialise_array (s, NELEM);
  random_permutation (s, NELEM);

  selection_sort (s, NELEM);
  print_sorted_array (s, NELEM, "Selection sort");

  initialise_array (s, NELEM);
  random_permutation (s, NELEM);

  quicksort (s, 0, NELEM - 1);
  print_sorted_array (s, NELEM, "Quicksort");

  initialise_array (s, NELEM);
  random_permutation (s, NELEM);

  heapsort (s, NELEM);
  print_sorted_array (s, NELEM, "Heapsort sort");

  initialise_array (s, NELEM);
  random_permutation (s, NELEM);

  mergesort (s, 0, NELEM - 1);
  print_sorted_array (s, NELEM, "Mergesort");

  // /* test binary search */
  printf ("\n\nBinary Search:\n");
  for (i = 0; i < NELEM; i++)
    {
      s[i] = 2 * (NELEM - i);
    }
  random_permutation (s, NELEM);

  heapsort (s, NELEM);
  for (i = 2; i < 2 * NELEM + 1; i += 2)
    {
      printf ("%d found in %d\n", i, binary_search (s, i, 0, NELEM - 1));
    }

  return 0;
}
