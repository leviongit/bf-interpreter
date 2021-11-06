#include "include/common.h"
#include "include/tape_u8.h"
#include <stdlib.h>

tape_u8_t *tape_u8_new(u32 size) {
  tape_u8_t *tape = malloc(sizeof(tape_u8_t));
  tape->size = size;
  tape->data = calloc(size, sizeof(u8));
  return tape;
}

void tape_u8_free(tape_u8_t *tape) {
  free(tape->data);
  free(tape);
}

void tape_u8_extend(tape_u8_t *tape, u32 size) {
  tape->size += size;
  tape->data = realloc(tape->data, tape->size * sizeof(u8));
}

// `tape` technically shouldn't ever shrink, but it's possible.
void tape_u8_shrink(tape_u8_t *tape, u32 size) {
  tape->size -= size;
  tape->data = realloc(tape->data, tape->size * sizeof(u8));
}

u8 tape_u8_get(tape_u8_t *tape) {
  return tape->data[tape->pos];
}

u8 tape_u8_get_at(tape_u8_t *tape, u32 pos) {
  if (pos >= tape->size) {
    return 0;
  }

  return tape->data[pos];
}

void tape_u8_set(tape_u8_t *tape, u8 value) {
  tape->data[tape->pos] = value;
}

void tape_u8_set_at(tape_u8_t *tape, u32 pos, u8 value) {
  if (pos >= tape->size) {
    tape_u8_extend(tape, pos - tape->size + 1);
  }

  tape->data[pos] = value;
}

void tape_u8_set_at_range(tape_u8_t *tape, u32 pos, u32 size, u8 value) {
  if(pos + size > tape->size) {
    tape_u8_extend(tape, pos + size - tape->size);
  }

  for (u32 i = 0; i < size; i++) {
    tape->data[pos + i] = value;
  }
}

void tape_u8_advance(tape_u8_t *tape, u32 amount) {
  if (tape->pos + amount >= tape->size) {
    tape_u8_extend(tape, amount);
  }

  tape->pos += amount;
}

void tape_u8_rewind(tape_u8_t *tape, u32 amount) {
  if (tape->pos < amount) {
    tape->pos = 0;
  } else {
    tape->pos -= amount;
  }
}

void tape_u8_copy_from_tape(tape_u8_t *tape, u32 pos, tape_u8_t *src, u32 src_pos, u32 size) {
  if (src_pos + size > src->size) {
    return;
  }

  if (pos + size > tape->size) {
    tape_u8_extend(tape, pos + size - tape->size);
  }

  for (u32 i = 0; i < size; i++) {
    tape->data[pos + i] = tape_u8_get_at(src, src_pos + i);
  }
}

void tape_u8_copy_to_tape(tape_u8_t *tape, u32 pos, tape_u8_t *dst, u32 dst_pos, u32 size) {
  if (pos + size > tape->size) {
    return;
  }

  if (dst_pos + size > dst->size) {
    tape_u8_extend(dst, dst_pos + size - dst->size);
  }

  for (u32 i = 0; i < size; i++) {
    tape_u8_set_at(dst, dst_pos + i, tape_u8_get_at(tape, pos + i));
  }
}

void tape_u8_copy_from_memory(tape_u8_t *tape, u32 pos, u8 *src, u32 src_pos, u32 size) {
  if (pos + size > tape->size) {
    tape_u8_extend(tape, pos + size - tape->size);
  }

  for (u32 i = 0; i < size; i++) {
    tape->data[pos + i] = src[src_pos + i];
  }
}

void tape_u8_copy_to_memory(tape_u8_t *tape, u32 pos, u8 *dst, u32 dst_pos, u32 size) {
  if (pos + size > tape->size) {
    return;
  }

  for (u32 i = 0; i < size; i++) {
    dst[dst_pos + i] = tape->data[pos + i];
  }
}

u32 tape_u8_get_pos(tape_u8_t *tape) {
  return tape->pos;
}

void tape_u8_set_pos(tape_u8_t *tape, u32 pos) {
  if (pos >= tape->size) {
    tape_u8_extend(tape, pos - tape->size + 1);
  }

  tape->pos = pos;
}

void tape_u8_increment(tape_u8_t *tape) {
  tape->data[tape->pos]++;
}

void tape_u8_decrement(tape_u8_t *tape) {
  tape->data[tape->pos]--;
}
