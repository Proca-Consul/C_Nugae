
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include "anagrams.h"
#include "quicksort.h"
#include "lexPerm.h"
#include "secCode.h"

int main(void) {

  printf("PAROLE, PAROLE, PAROLE - WORDS, WORDS, WORDS\n");
  printf("  by Prof. Ivano Salvo, University Sapienza di Roma\n");
  printf("  implementation by Ivan Procaccini©\n\n");
  printf("> Enter:\n");
  printf("> :lexperm [word] to obtain next lexicografic ");
  printf("permutation of given word;\n");
  printf("> :anagrams [fst word] [snd word] to check ");
  printf("whether the two words are anagrams;\n");
  printf("> :secretcode [word] [k parameter] to obtain ");
  printf("the codification of word moving each letter 'k' times ");
  printf("forward in the alphabeth;\n");
  printf("> :h to obtain help about previous commands;\n");
  printf("> :q to quit the program.\n");
  char *cmd = malloc(100 * sizeof(char));
  char *del = " ";
  
  read:
	printf("\n> ");
  scanf("%s", cmd);
  char *token = strtok(cmd, del);
  if (!strcmp(":lexperm", token)) {
    char *word = malloc(70 * sizeof(char));
    scanf("%s", word);
		char *alias = malloc(70 * sizeof(char));
    strcpy(alias, word);
    char *perm = lexPerm(word);
    if (!strcmp(alias, word)) {
      printf("> No possible next lex permutations of given word!\n");
      printf("> Enter command or type :q to quit:\n");
    } else {
      printf("> Next permutation of %s: %s\n", token, perm);
      printf("\n> Enter command or type :q to quit:\n");
    }
		free(word);
    free(alias);
    goto read;
  } else if (!strcmp(":anagrams", token)) {
    char *fst = malloc(70 * sizeof(char));
    char *snd = malloc(70 * sizeof(char));
		scanf("%s %s", fst, snd);
    if (fst == NULL || snd == NULL) {
      printf("> NULL input to :anagrams; retry or type :q to quit:\n");
    } else {
      int result = checkAnagrams(fst, snd);
      printf(result ? "> %s is " : "> %s is not ", fst);
      printf("an anagram of %s.\n", snd);
      printf("\n> Enter command or type :q to quit:\n");
    }
		free(fst);
		free(snd);
    goto read;
  } else if (!strcmp(":secretcode", token)) {
    char *word = malloc(70 * sizeof(char));
		int k;
		scanf("%s %d", word, &k);
    
		// Must check for invalid (or non integer) k 
		if (word == NULL) {
      printf("> Invalid input to :secretcode; retry or type :q to quit:\n");
    } else {
      printf("> Codification: %s\n", secretCode(word, k));
      printf("> Enter command or type :q to quit:\n");
    }
		free(word);
    goto read;
  } else if (!strcmp(":h", token)) {
    printf("\n COMMAND HELP \n");
    printf("> :anagram [fst word] [snd word] checks whether [fst word] is an anagram of [snd word]\n");
    printf("> :lexperm [word] prints the next lexicografic permutation of [word]\n");
    printf("> :secretcode [word] [k parameter] returns a codification of [word] obtained by replacing\n");
    printf("  every letter of [word] with the [k parameter]th letter after it in the alphabeth. The \n");
    printf("  alphabeth is handled as it were circular, thus continuing from 'a' right after 'z'.\n");
    printf("\n> Enter command or type :q to quit:\n");
    goto read; 
  } else if (!strcmp(":q", token)) {
    printf("> Closing program...\n");
    sleep(1);
		printf("> Done\n");
  } else {
    printf("> Ops! '%s' is not a valid command. Retry or type :q to quit :\n", token);
    goto read;
  } 
	free(cmd);
  return 0;

}
