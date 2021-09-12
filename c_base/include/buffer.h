#ifndef BUFFER_H
#define BUFFER_H

#include <stdlib.h>

typedef struct buffer_struct {
  size_t length;
  size_t ptr;
  size_t *content;
} Buffer;

Buffer *init_buffer();
void grow_buffer(Buffer *buffer);
void free_buffer(Buffer *buffer);
void print_buffer(Buffer *buffer);
void push_buffer(Buffer *buffer, size_t el);
size_t pop_buffer(Buffer *buffer);

#endif
