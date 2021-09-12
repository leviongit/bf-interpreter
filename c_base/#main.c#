#include "include/buffer.h"
#include "include/lang_eval.h"

#include <stdio.h>

int main(int argv, char **argc) {
  char *str = "++++++++[>++++[>++>+++>+++>+<<<<-]>+>+>->>+[<]<-]>>.>---.+++++++"
              "..+++.>>.<-.<.+++.------.--------.>>+.>++.";
  Buffer *buffer = init_buffer(32);
  eval(str, buffer);

  // print_buffer(buffer);
  // printf("\n");

  free_buffer(buffer);
}