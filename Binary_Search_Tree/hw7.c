#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bst.h"
#include "memory.h"
#include "hw7.h"
//FINAL SUB

/* Create a bst from a txt file
 * return bst pointer
 */

bst* read_memory_blocks(char *filename,
  int (*cmp)(const void* x, const void* y))
  {


    FILE *fp = fopen(filename, "r");
    if (fp == NULL)
    {
      printf("Could not open file %s for reading\n",filename);
      exit(2);
    }

    bst *out = bst_new(cmp);

    char buffer[BUFSIZ]= "garbage";
    while (fgets(buffer, sizeof(buffer), fp) != NULL)
    {

      unsigned int data;
      unsigned int size;
      char *tmp_s;
      tmp_s = strtok(buffer," ,\n\r");
      data = atoi(tmp_s);
      tmp_s  = strtok(NULL," ,\n\r");
      size = atoi(tmp_s);
      memory *mem_block = memory_new(data, size);
      bst_insert(out, mem_block);
    }
    fclose(fp);
    return out;




}
