#include <stdio.h>

#include "include/common.h"
#include "include/tape_u8.h"
#include "include/stack_u32.h"
#include "include/interpreter_state.h"
#include "include/instruction_exec.h"

void interpret(u8 *code) {
  bfi_state_t *state = bfi_state_new(code);

  tape_u8_t *_code = state->code;
  tape_u8_t *tape = state->tape;
  stack_u32_t *stack = state->stack;

  u8 chr;
  while ((chr = tape_u8_get(_code))) {
    while (state->depth) {
      if (tape_u8_get(_code) == ']') {
        state->depth--;
      } else if (chr == '[') {
        state->depth++;
      }
      tape_u8_advance(_code, 1);
      chr = tape_u8_get(_code);
    }
    switch (chr) {
      case '>':
        tape_u8_advance(tape, 1);
        break;
      case '<':
        tape_u8_rewind(tape, 1);
        break;
      case '+':
        tape_u8_increment(tape);
        break;
      case '-':
        tape_u8_decrement(tape);
        break;
      case '.':
        printf("%c", (char) tape_u8_get(tape));
        break;
      case ',':
        tape_u8_set(tape, getchar());
        break;
      case '[':
        if (tape_u8_get(tape)) stack_u32_push(stack, tape_u8_get_pos(_code));
        else state->depth++;
        break;
      case ']':
        if(tape_u8_get(tape)) {
          tape_u8_set_pos(_code, stack_u32_peek(stack));
        } else {
          stack_u32_pop(stack);
        }
        break;
    }
    tape_u8_advance(_code, 1);
  }
}
