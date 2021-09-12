#include "include/lang_eval.h"
#include "include/buffer.h"

#include <stdio.h>
#include <stdint.h>
#include <string.h>

void handle_char(char c, Buffer *buffer, Buffer *stack, size_t *code_idx) {
  switch (c) {
  case '+': {
    buffer->content[buffer->ptr] += 1;
    break;
  }
  case '-': {
    buffer->content[buffer->ptr] -= 1;
    break;
  }
  case '>': {
    if (buffer->ptr + 1 == buffer->length)
      grow_buffer(buffer);
    buffer->ptr += 1;
    break;
  }
  case '<': {
    if (buffer->ptr == 0) return;
    buffer->ptr -= 1;
    break;
  }
  case '.': {
    printf("%c", (int) buffer->content[buffer->ptr]);
    break;
  }
  case '!': {
    printf("%lu\n", buffer->content[buffer->ptr]);
  }
  case ',': {
    buffer->content[buffer->ptr] = getchar();
    break;
  }
  case '[': {
    push_buffer(stack, *code_idx);
    break;
  }
  case ']': {
    if (buffer->content[buffer->ptr]) *code_idx = stack->content[stack->ptr-1];
    else pop_buffer(stack);
    break;
  }
  }
  return;
}

void eval(char *str, Buffer *buffer) {
  Buffer *stack = init_buffer(1);
  for(size_t i = 0; i < strlen(str); i++) {
    // printf("%c\n", str[i]);
    handle_char(str[i], buffer, stack, &i);
  }
}
