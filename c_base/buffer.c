#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "include/buffer.h"

Buffer *init_buffer(size_t size) {
  Buffer *buffer = (Buffer*) calloc(1, sizeof(Buffer));
  buffer->ptr = 0;
  buffer->length = size;
  buffer->content = calloc(size, sizeof(size_t));

  return buffer;
}

void free_buffer(Buffer *buffer) {
  free(buffer->content);
  free(buffer);
}

void grow_buffer(Buffer *buffer) {
  buffer->content = realloc(buffer->content, buffer->length * 2);
  buffer->length *= 2;
}

void print_buffer(Buffer *buffer) {
  for (size_t i = 0; i < buffer->length; i++) {
    printf("%lu", buffer->content[i]);
    if (i < buffer->length - 1) printf("|");
  }
}

void push_buffer(Buffer *buffer, size_t el) {
  if (buffer->ptr + 1 == buffer->length)
    grow_buffer(buffer);
  buffer->content[buffer->ptr] = el;
  buffer->ptr += 1;
}

size_t pop_buffer(Buffer *buffer) {
  size_t val =
    buffer->content[buffer->ptr--];
  buffer->content[buffer->ptr+1] = -1;
  return val;
}