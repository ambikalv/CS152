#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hw5.h"

/*
Creates an empty string / allocates memory for it
*/
safe_string* make_empty_string()
{

  safe_string* s = (safe_string *)malloc(sizeof(char));
  s->str = "";
  s->allocated_length = 0;
  return s;
}
/*
Creates an a safe string version of str
inputs:
  char *str1
outputs:
  safe_string
*/
safe_string* make_string(char *str)
{
  safe_string* s = (safe_string *)malloc(sizeof(char)*strlen(str));
  s->str = str;
  s->allocated_length = 0;
  return s;
}

/*
Creates an a safe string version of strcpy
inputs:
  char *str1
outputs:
  copies the string
*/
void safe_str_cpy(safe_string *dest, safe_string *src)
{
  char *destination = malloc(strlen(src->str) + 1);
  dest->str = destination;
  strcpy(destination,src->str);
}

/*
Creates an a safe string version of strcat
inputs:
  char *str1
  safe_string *dest
outputs:
  concatenates the string
*/
void safe_str_cat(safe_string *dest, safe_string *src)
{

  if (sizeof(dest->str) < (sizeof(src->str) + strlen(dest->str)))
  {
    int len = strlen(dest->str) +strlen(src->str);
    safe_string* s = (safe_string *)malloc(sizeof(char)*len);
    s->str = strcat(dest->str,src->str);
    s->allocated_length = len;
  }
  else
  {
    strcat(dest->str,src->str);
  }
}

/*
Creates an a safe string version of strchr
inputs:
  char c
  safe_string *s
outputs:
  concatenates the string
*/
char *safe_strchr(safe_string *s, char c)
{
  return strchr(s->str, c);
}

/*
Creates an a safe string version of strcmp
inputs:
  char *str1
  safe_string *dest
outputs:
  concatenates the string
*/
int safe_strcmp(safe_string *s1, safe_string *s2)
{
  for (int i = 0; i < strlen(s1 -> str); i ++)
  {
    if (s1->str[i] < s2->str[i])
    {
      return -1;
    }

    if (s1->str[i] > s2->str[i])
    {
      return 1;
    }
  }
  return 0;
}
