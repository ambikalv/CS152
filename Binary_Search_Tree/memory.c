#include<stdio.h>
#include<stdlib.h>
#include "memory.h"
#include "bst.h"
//FINAL SUB 

/* memory_new
 * create a new memory struct, initialze its address and size
 */
memory* memory_new(unsigned int addr, unsigned int size){
  memory* m = (memory*)malloc(sizeof(memory));
  m->addr = addr;
  m->size = size;
  return m;
}

/* free the dynamically allocated memory struct
 */
void memory_free(void* p){
  memory* m = (memory*)p;
  free(m);
}

/* compare two memory variables x and y by address
 * if x is less than y, return -1
 * if x is greater than y, return 1
 * if they are equal, return 0
 */
int memory_addr_cmp(const void* x, const void* y){
  //TODO


  if ((x == NULL) || (y == NULL))
  {
    printf("NULL\n" );
    return 0;
  }

  const memory* x_mem = x;
  const memory* y_mem = y;

  int x_address = x_mem->addr;
  int y_address = y_mem->addr;


  if (x_address < y_address)
  {
    return -1; // cant return -1 for some reason
  }
  else if (x_address > y_address)
  {
    return 1;
  }
  else
  {
    return 0;
  }

}

/* compare two memory variables x and y by size
 * if x is less than y, return -1
 * if x is greater than y, return 1
 * if they are equal, return 0
 */

int memory_size_cmp(const void* x, const void* y){
  //TODO
  const memory* x_mem = x;
  const memory* y_mem = y;

  int x_size = x_mem->size;
  int y_size = y_mem->size;

  if (x_size < y_size)
  {
    return -1;
  }
  else if (x_size > y_size)
  {
    return 1;
  }
  else
  {
    return 0;
  }

}

/* print the memory address and size
*/

void memory_print(void* data){
  if (data == NULL) return;
  memory* m = (memory*)data;
  printf("address: %u, size: %u\n", m->addr, m->size);
}
