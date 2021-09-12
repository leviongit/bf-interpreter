#ifndef LANG_EVAL_H
#define LANG_EVAL_H

#include "buffer.h"

void handle_char(char c, Buffer *buffer, Buffer *stack, size_t *code_idx);

void eval(char *str, Buffer *buffer);

#endif