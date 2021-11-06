#ifndef INTERPRETER_STATE_H
#define INTERPRETER_STATE_H

#include "common.h"
#include "tape_u8.h"
#include "stack_u32.h"

typedef struct bfi_state_t bfi_state_t;

struct bfi_state_t {
  // because why not
  tape_u8_t *code;
  tape_u8_t *tape;
  stack_u32_t *stack;
  u8 depth;
};

bfi_state_t *bfi_state_new(u8 *code);
void bfi_state_free(bfi_state_t *state);
tape_u8_t *bfi_state_get_code(bfi_state_t *state);
u8 bfi_state_get_current_code(bfi_state_t *state);
u8 bfi_state_get_next_code(bfi_state_t *state);
tape_u8_t *bfi_state_get_tape(bfi_state_t *state);
stack_u32_t *bfi_state_get_stack(bfi_state_t *state);

#endif
