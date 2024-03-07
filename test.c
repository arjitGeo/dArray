#include "dArr.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// int
// main (void)
// {
//   printf ("Hello, World!\n");

//   darr_t *arr = darr_new (sizeof (int));

//   int a[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//   int b[4] = { 31, 2314, 7634455, 1242465 };
//   int c[8]
//       = { 143631, 3426314, 9634455, 242465, 4156, 1242465, 1242465, 1242465
//       };
//   int aa[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//   int ba[4] = { 31, 2314, 7634455, 1242465 };
//   int ca[8]
//       = { 143631, 3426314, 9634455, 242465, 4156, 1242465, 1242465, 1242465
//       };

//   darr_push (arr, a, 10);
//   darr_push (arr, b, 4);
//   darr_push (arr, c, 8);
//   darr_push (arr, aa, 10);
//   darr_push (arr, ba, 4);
//   darr_push (arr, ca, 8);
//   darr_push (arr, a, 10);
//   darr_push (arr, b, 4);
//   darr_push (arr, c, 8);
//   darr_push (arr, aa, 10);
//   darr_push (arr, ba, 4);
//   darr_push (arr, ca, 8);

//   // snprintf

//   // int *d = darr_values (arr, malloc (darr_lengthInBytes (arr)),
//   //                       darr_lengthInBytes (arr));

//   // putchar ('\n');

//   // for (size_t i = 0, count = darr_length (arr); i < count; i++)
//   //   printf ("%d\n", d[i]);

//   int e = 0;

//   // darr_valueAt (arr, &e, 10);

//   // printf ("%d\n", e);
//   printf ("%d\n", *(int *)darr_valueAt (arr, &e, 10));

//   putchar ('\n');
//   putchar ('\n');

//   printf ("Length: -------------- %zu\n", darr_length (arr));
//   printf ("Capacity: ------------ %zu\n", darr_capacity (arr));
//   printf ("size of one element: - %zu\n", darr_sizeOfOneElement (arr));

//   darr_delete (arr);
//   return (0);
// }

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
