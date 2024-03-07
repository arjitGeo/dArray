#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

struct dArr
{
  void *value;
  size_t sizeOfOneElement;
  size_t length;
  size_t capacity;
};

static int
darr_resize (struct dArr *arr, size_t size)
{
  void *temp = realloc (arr->value, size * arr->sizeOfOneElement);
  if (temp == NULL)
    return 1;

  arr->value = temp;
  arr->capacity = size;
  return 0;
}

struct dArr *
darr_new (size_t sizeOfOneElement)
{
  if (sizeOfOneElement == 0)
    return NULL;

  struct dArr *ret = malloc (sizeof (struct dArr));
  if (ret == NULL)
    return NULL;

  ret->sizeOfOneElement = sizeOfOneElement;
  ret->value = NULL;
  ret->length = 0;
  ret->capacity = 0;

  return ret;
}

void
darr_delete (struct dArr *arr)
{
  if (arr != NULL)
    free (arr->value);
  free (arr);
}

size_t
darr_length (const struct dArr *arr)
{
  if (arr == NULL)
    return 0;

  return arr->length;
}

size_t
darr_lengthInBytes (const struct dArr *arr)
{
  if (arr == NULL)
    return 0;

  return arr->length * arr->sizeOfOneElement;
}

size_t
darr_capacity (const struct dArr *arr)
{
  if (arr == NULL)
    return 0;

  return arr->capacity;
}

size_t
darr_capacityInBytes (const struct dArr *arr)
{
  if (arr == NULL)
    return 0;

  return arr->capacity * arr->sizeOfOneElement;
}

size_t
darr_sizeOfOneElement (const struct dArr *arr)
{
  if (arr == NULL)
    return 0;

  return arr->sizeOfOneElement;
}

void *
darr_values (const struct dArr *arr, void *dest, const size_t size)
{
  if (arr == NULL || dest == NULL || size == 0)
    return NULL;

  const size_t lenInBytes = arr->length * arr->sizeOfOneElement;

  return memcpy (dest, arr->value, size > lenInBytes ? lenInBytes : size);
}

void *
darr_valueAt (const struct dArr *arr, void *dest, const size_t index)
{
  if (arr == NULL || dest == NULL || index >= arr->length)
    return NULL;

  return memcpy (dest, (uint8_t *)arr->value + index * arr->sizeOfOneElement,
                 arr->sizeOfOneElement);
}

int
darr_push (struct dArr *arr, const void *value, const size_t count)
{
  if (arr == NULL || value == NULL || count == 0)
    return 1;

  if (arr->length + count >= arr->capacity)
    if (darr_resize (arr, arr->length + (count * 2)) == 1)
      return 1;

  memcpy ((uint8_t *)arr->value + arr->length * arr->sizeOfOneElement,
          (uint8_t *)value, count * arr->sizeOfOneElement);

  arr->length += count;

  return 0;
}

struct dArr *
darr_splice (struct dArr *arr, const size_t index, const size_t count)
{
  if (arr == NULL || index + count > arr->length || count == 0)
    return NULL;

  struct dArr *ret = darr_new (arr->sizeOfOneElement);
  if (ret == NULL)
    return NULL;

  if (darr_resize (ret, count) == 1)
    {
      darr_delete (ret);
      return NULL;
    }

  ret->length = count;

  memcpy (ret->value, (uint8_t *)arr->value + index * ret->sizeOfOneElement,
          count * ret->sizeOfOneElement);

  return ret;
}

// this function is impossible to make
/* int
darr_push_s (struct dArr *arr, const size_t count, ...)
{
  if (arr == NULL || count == 0)
    return 1;

  if (arr->length + count >= arr->capacity)
    if (darr_resize (arr, arr->length + (count * 2)) == 1)
      return 1;

  void *buf = malloc (count * arr->sizeOfOneElement);
  if (buf == NULL)
    return 1;

  va_list args;

  va_start (args, count);

  for (size_t i = 0; i < count; ++i)
    {
      ??? arg = va_arg (args, ???);

      arr->length++;
    }

  va_end (args);

  return 0;
} */
