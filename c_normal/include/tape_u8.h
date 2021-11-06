#ifndef TAPE_U8_H
#define TAPE_U8_H

#include "common.h"

typedef struct tape_u8_t tape_u8_t;

struct tape_u8_t {
  u8 *data;
  u32 size;
  u32 pos;
};

tape_u8_t *tape_u8_new(u32 size);
void tape_u8_free(tape_u8_t *tape);
void tape_u8_extend(tape_u8_t *tape, u32 size);
void tape_u8_shrink(tape_u8_t *tape, u32 size);
u8 tape_u8_get(tape_u8_t *tape);
u8 tape_u8_get_at(tape_u8_t *tape, u32 pos);
void tape_u8_set(tape_u8_t *tape, u8 value);
void tape_u8_set_at(tape_u8_t *tape, u32 pos, u8 value);
void tape_u8_set_at_range(tape_u8_t *tape, u32 pos, u32 size, u8 value);
void tape_u8_advance(tape_u8_t *tape, u32 amount);
void tape_u8_rewind(tape_u8_t *tape, u32 amount);
void tape_u8_copy_from_tape(tape_u8_t *tape, u32 pos, tape_u8_t *src, u32 src_pos, u32 size);
void tape_u8_copy_to_tape(tape_u8_t *tape, u32 pos, tape_u8_t *dst, u32 dst_pos, u32 size);
void tape_u8_copy_from_memory(tape_u8_t *tape, u32 pos, u8 *src, u32 src_pos, u32 size);
void tape_u8_copy_to_memory(tape_u8_t *tape, u32 pos, u8 *dst, u32 dst_pos, u32 size);
u32 tape_u8_get_pos(tape_u8_t *tape);
void tape_u8_set_pos(tape_u8_t *tape, u32 pos);
void tape_u8_increment(tape_u8_t *tape);
void tape_u8_decrement(tape_u8_t *tape);

#endif
