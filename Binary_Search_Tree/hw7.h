#ifndef HW7_H
#define HW7_H
#include "bst.h"
#include "memory.h"
//FINAL SUB








/* Create a bst from a txt file
 * return bst pointer
 */
bst* read_memory_blocks(char *filename,
  int (*cmp)(const void* x, const void* y));

#endif
