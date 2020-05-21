#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hw5.h"

int main()
{
  safe_string *hi = make_string("hello");
  printf("%s\n",hi->str) ;

  safe_string *bye = make_string("good");

  //safe_str_cpy(hi, bye);
  printf("%s\n",hi->str) ;

  safe_str_cat(hi,bye);
  printf("%s\n",hi->str) ;

  printf("success the value is %c\n",*safe_strchr(hi, 'e') );

  printf(" success the value is %d\n", safe_strcmp(hi, bye));




}
