
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "quicksort.h"
#include "program.h"

char *lexPerm(char *string) {
   
  if (strlen(string) == 1) {
    return string;
  }
  
  int lim =0;
  int len = strlen(string) - 1;
  char tmp;
   
  for (int i = strlen(string) - 1; i >= 1; i--) {
    for (int j = i - 1; j >= 0; j--) {
      if (string[i] > string[j]) {
        // printf("%d i %d j\n", ilim, jlim);
        tmp = string[i];
        string[i] = string[j];
        string[j] = tmp;
        lim = j + 1;
        goto sort;
      } 
    }
  }

  sort:
  quicksort(string, lim, len); 

  return string;
}

