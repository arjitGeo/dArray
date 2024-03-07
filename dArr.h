#ifndef DARR_H
#define DARR_H

#include <stddef.h>

typedef struct dArr darr_t;

darr_t *darr_new (size_t sizeOfOneElement);
void darr_delete (darr_t *arr);

size_t darr_length (const darr_t *arr);
size_t darr_lengthInBytes (const darr_t *arr);
size_t darr_capacity (const darr_t *arr);
size_t darr_capacityInBytes (const darr_t *arr);
size_t darr_sizeOfOneElement (const darr_t *arr);

int darr_push (darr_t *arr, const void *value, const size_t count);
void *darr_values (const darr_t *arr, void *dest, const size_t size);
void *darr_valueAt (const darr_t *arr, void *dest, const size_t index);
darr_t *darr_splice (const darr_t *arr, const size_t index,
                     const size_t count);

/*
 * TODO:
 *  darr_pop
 *  darr_insert
 *  darr_remove
 *  darr_clear
 *  darr_sort
 *  darr_find
 *  darr_filter
 *  darr_map
 *  darr_reduce
 *  darr_forEach
 */

#endif // DARR_H