
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#include "program.h"

int checkAnagrams(char *string1, char *string2) {
  
  char *s1 = string1;
  char *s2 = string2;

  int *alphaTable1 = calloc(26, sizeof(int));
  
  if (strlen(string1) != strlen(string2)) {
    return 0;
  }
  
  while (*s1 != '\0' && *s2 != '\0') {
   alphaTable1[((int) tolower(*s1)) - 96] += 1;
   alphaTable1[((int) tolower(*s2)) - 96] -= 1;
   s1++;
   s2++;
  }
  
  for (int i = 0; i < 26; i++) {
    if (alphaTable1[i] != 0) {
      return 0;
    }
  }

  free(alphaTable1);
  return 1;

}

