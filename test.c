#include "dArr.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int
main (void)
{
  putchar ('\n');
  darr_t *arr = darr_new (sizeof (char));
  char buff[32];

  darr_push (arr, buff, snprintf (buff, 32, "a float: %.2f, ", 16.34));
  darr_push (arr, buff, snprintf (buff, 32, "an int: %d", 16));

  const char null = '\0';
  darr_push (arr, &null, 1);

  darr_t *arr2 = darr_splice (arr, 0, 14);
  darr_push (arr2, &null, 1);

  char *buf = malloc (darr_lengthInBytes (arr));
  char *buf2 = malloc (darr_lengthInBytes (arr2));

  puts (darr_values (arr, buf, darr_lengthInBytes (arr)));
  putchar ('\n');

  puts (darr_values (arr2, buf2, darr_lengthInBytes (arr2)));

  putchar ('\n');
  putchar ('\n');

  printf ("Length:    ----------  %zu\n", darr_length (arr));
  printf ("Capacity:  ----------  %zu\n\n", darr_capacity (arr));
  printf ("Length 2:    ----------  %zu\n", darr_length (arr2));
  printf ("Capacity 2:  ----------  %zu\n", darr_capacity (arr2));

  darr_delete (arr);
  darr_delete (arr2);
  return (0);
}
