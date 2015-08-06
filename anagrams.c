
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

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

int main(void) {

  char *string1 = malloc(70 * sizeof(char));
  char *string2 = malloc(70 * sizeof(char));
  printf("ANAGRAMS - ANAGRAMMI\n");
  printf("> Insert your two strings:\n");
  printf("> ");
  scanf("%s", string1);
  printf("> ");
  scanf("%s", string2);
  int result = checkAnagrams(string1, string2);
  printf("> Anagram Check: ");
  printf(result ? "POSITIVE\n" : "NEGATIVE\n");
  free(string1);
  free(string2);
  return 0;

}
