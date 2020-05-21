#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "warmup5.h"

int main()
{
  char *test = safe_str_concat("hi", "by");
  printf("%s\n", test );

  int_vector *v = (int_vector*) malloc(sizeof(int)*5);
  v->allocated_size = 4;
  int arr[4] ={1,2,3,4};
  v->array = arr;
  write_value(v, 2, 6);

  for (int i = 0; i < 4; i++)
  {
    printf("%d\n", v->array[i]);
  }

  printf("%d\n", read_value(v, 2));

}
