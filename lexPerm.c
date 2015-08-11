
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "quicksort.h"

char *lexPerm(char *string) {
   
  if (strlen(string) == 1) {
    return string;
  }
  
  int jlim = -1;
  int ilim = 1;
  char tmp;

  start: 
  for (int i = strlen(string) - 1; i >= ilim ; i--) {
    for (int j = i - 1; j > jlim; j--) {
      if (string[i] > string[j]) {
        // printf("%d i %d j\n", ilim, jlim);
        tmp = string[i];
        string[i] = string[j];
        string[j] = tmp;
        jlim = j;
        ilim = jlim + 1;
        firstLoop = 0;
        goto start;
      } 
    }
  }
  return string;
}




int main(void) {

  printf("LEXICOGRAPHIC PERMS - PERMUTAZIONI LESSICOGRAFICHE\n");
  printf("> Insert your string:\n> ");
  char *string = malloc (70 * sizeof(char));
  scanf("%s", string);
  char *alias = malloc(70 * sizeof(char));
  strcpy(alias, string); 
  char *result = lexPerm(string);
  if (strcmp(alias, result) == 0) {
    printf("> No possible next permutations of given string\n");
  } else {
    printf("> Next lexicographic permutation: %s\n", result);
  }
  free(string);
  free(alias);
  return 0;

} 
  
 


