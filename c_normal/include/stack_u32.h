#ifndef STACK_U32_H
#define STACK_U32_H

#include "common.h"

typedef struct stack_u32_t stack_u32_t;

struct stack_u32_t {
    u32 *data;
    int size;
    int top;
};

stack_u32_t *stack_u32_new(int size);
void stack_u32_free(stack_u32_t *stack);
void stack_u32_push(stack_u32_t *stack, u32 value);
u32 stack_u32_pop(stack_u32_t *stack);
u32 stack_u32_peek(stack_u32_t *stack);

#endif
