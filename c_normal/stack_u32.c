#include <stdlib.h>

#include "include/common.h"
#include "include/stack_u32.h"

stack_u32_t *stack_u32_new(int size) {
    stack_u32_t *stack = malloc(sizeof(stack_u32_t));
    stack->size = size;
    stack->top = -1;
    stack->data = calloc(size, sizeof(uint32_t));
    return stack;
}

void stack_u32_free(stack_u32_t *stack) {
    free(stack->data);
    free(stack);
}

void stack_u32_push(stack_u32_t *stack, u32 value) {
    if (stack->top == stack->size - 1) {
        stack->size *= 2;
        stack->data = realloc(stack->data, stack->size * sizeof(uint32_t));
    }
    stack->top++;
    stack->data[stack->top] = value;
}

u32 stack_u32_pop(stack_u32_t *stack) {
    if (stack->top == -1) {
        return 0;
    }

    if (stack->top == stack->size / 4 && stack->size / 2 != 0) {
        stack->size /= 2;
        stack->data = realloc(stack->data, stack->size * sizeof(uint32_t));
    }

    u32 value = stack->data[stack->top];
    stack->top--;
    return value;
}

u32 stack_u32_peek(stack_u32_t *stack) {
    if (stack->top == -1) {
        return 0;
    }
    return stack->data[stack->top];
}
