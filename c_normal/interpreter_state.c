#include <stdlib.h>
#include <string.h>

#include "include/common.h"
#include "include/tape_u8.h"
#include "include/stack_u32.h"
#include "include/interpreter_state.h"

bfi_state_t *bfi_state_new(u8 *code) {
  bfi_state_t *state = malloc(sizeof(bfi_state_t));
  state->code = tape_u8_new(1);
  tape_u8_copy_from_memory(state->code, 0, code, 0, strlen((char *) code));
  state->tape = tape_u8_new(32);
  state->stack = stack_u32_new(4);
  state->depth = 0;
  return state;
}

void bfi_state_free(bfi_state_t *state) {
  tape_u8_free(state->tape);
  stack_u32_free(state->stack);
  free(state);
}

tape_u8_t *bfi_state_get_code(bfi_state_t *state) {
  return state->code;
}

u8 bfi_state_get_current_code(bfi_state_t *state) {
  return tape_u8_get(state->code);
}

u8 bfi_state_get_next_code(bfi_state_t *state) {
  return tape_u8_get_at(state->code, ++state->code->pos);
}

tape_u8_t *bfi_state_get_tape(bfi_state_t *state) {
  return state->tape;
}

stack_u32_t *bfi_state_get_stack(bfi_state_t *state) {
  return state->stack;
}
