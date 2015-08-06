
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

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

int main(void) {
  printf("SECRET CODES - CODICI SEGRETI\n");
  printf("> Insert the word to encode and the coding parameter:\n> ");
  int k;
  char *string = malloc(70 * sizeof(char));
  scanf("%s %d", string, &k);
  printf("> Encoding outcome: %s\n", secretCode(string, k));
  free(string);
  return 0;
}
