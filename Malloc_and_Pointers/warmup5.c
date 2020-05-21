#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "warmup5.h"


/*
concatenates a string safely
inputs:
  char *str1
  char *str2
return:
  returns the save concatenation
*/
char *safe_str_concat(char *str1, char *str2)
{
  char* safe_str_concat = (char *) malloc(sizeof(str1)+sizeof(str2));
  int len = strlen(str1) +strlen(str2);
  for (int i = 0; i< strlen(str1); i ++)
  {
    safe_str_concat[i] = str1[i];
  }
  for(int j = strlen(str1); j < len; j++)
  {
    safe_str_concat[j] = str2[j- strlen(str1)];
  }
  return safe_str_concat;
}




/*
Takes an int_vector initializes it
inputs:

return:
  initilized array
*/

int_vector* make_init_array()
{
  int_vector* v = (int_vector *)malloc(sizeof(int));
  v->allocated_size = 0;
  v->array = NULL;
  return v;
}



/*
Takes an int_vector and places a value at an index
inputs:
  int_vector *vector
  unsigned int index
  int read_value
return:
  updates the int_vector

*/
void write_value(int_vector *vector, unsigned int index, int value)
{
  if (index > sizeof(vector->array))
  {
    int* new_array = (int*) malloc(sizeof(int)*(index+1));
    vector->array = strcpy(new_array, vector->array);
  }
  vector->array[index] = value;
}


/*
Takes an int_vector and reads a value at an index
inputs:
  int_vector *vector
  unsigned int index
  int read_value
return:
  returns the value at the index
*/
int read_value(int_vector *vector, unsigned int index)
{
  int ind = 0;
  for (int i = 0; i <= index; i++)
  {
    if (ind == index)
    {
      return vector->array[index];
    }
    ind++;

  }
  return 0;
}

/*
Takes a pixel and initializes it
inputs:
  int height
  int width
  pixel color
return:
  returns the value at the index
*/
pixel** make_and_init_image(int height, int width, pixel color)
{
  pixel **w = (pixel**) malloc(sizeof(pixel*)*height);
  for (int i = 0 ; i < height; i++)
  {
      w[i] = (pixel*) malloc(sizeof(pixel)* width);
      for (int j = 0; j < width; j++)
      {
        w[i][j] = color;
      }
  }
  return w;
}
