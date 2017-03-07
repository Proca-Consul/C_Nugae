
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#include "program.h"

char *secretCode(char *string, int k) {
  
  char *s = string;
  while (*s != '\0') {
    
    if (tolower(*s) == 'z') {
      *s = (char) (97 + (k - 1));
    } else {
      *s = (char) ((int) *s + k);
    }
    s++;
  } 
  return string;
}

