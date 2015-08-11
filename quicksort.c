
#include <stdio.h>
#include <stdlib.h>

int partition(char *string, int l, int r) {

  char piv = string[l];
  int i = l - 1;
  int j = r + 1;

  for (;;) {

    do {
      j--;
    } while (string[j] > piv); 
    
    do {
      i++;
    } while (string[i] < piv);
    
    if (i < j) {
      char temp = string[i];
      string[i] = string[j];
      string[j] = temp;
    } else {
      break;
    }
  
  }
  return j;   
}

void quicksort(char *string, int l, int r) {
  
  if (l < r) {
    int d = partition(string, l, r);
    quicksort(string, l, d);
    quicksort(string, d + 1, r);
  }

}

int main(void) {

  printf("Insert string to sort and l r parameters:\n");
  printf("> ");
  char *string = malloc(70 * sizeof(char));
  int l, r;
  scanf("%s %d %d", string, &l, &r);
  quicksort(string,l, r);
  printf("> Sorted: %s\n", string);
  return 0;
  
} 
