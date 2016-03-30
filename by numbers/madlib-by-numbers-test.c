#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "madlib-by-numbers.h"

int main(){
  char* words_to_use[] = {"code", "brilliant", "Professor Doal"};
  char* insaneMessage = madlib_by_numbers("The 1 2 likes to 0 in the 1 moonlight.", 3, words_to_use);
  //char message[strlen(insaneMessage)];
  int messageLength = strlen(insaneMessage);
  printf("%s\n",insaneMessage);
  assert(strncmp("The brilliant Professor Doal likes to code in the brilliant moonlight.", insaneMessage, messageLength) == 0);
  free(insaneMessage);

  char* words_to_use1[] = {"burp", "professor", "Doal"};
  char* insaneMessage1 = madlib_by_numbers("Sneaky 1 2 likes to 0 when there is no one around.", 3, words_to_use1);
  //char message[strlen(insaneMessage)];
  int messageLength1 = strlen(insaneMessage1);
  printf("%s\n",insaneMessage1);
  assert(strncmp("Sneaky professor Doal likes to burp when there is no one around.", insaneMessage1, messageLength1) == 0);
  free(insaneMessage1);

  char* words_to_use2[] = {"burp", "professor", "Doal", "test"};
  char* insaneMessage2 = madlib_by_numbers("Sneaky 1 5 likes to 0 when there is no one around.", 4, words_to_use2);
  //If number is not in the word count it will just print out that number in the string.
  int messageLength2 = strlen(insaneMessage2);
  printf("%s\n",insaneMessage2);
  assert(strncmp("Sneaky professor 5 likes to burp when there is no one around.", insaneMessage2, messageLength2) == 0);
  free(insaneMessage2);

  char* words_to_use3[] = {"burp", "professor", "Toal", "test"};
  char* insaneMessage3 = madlib_by_numbers("Sneaky 1 -5 likes to 0 when there is no one around.", 4, words_to_use3);
  //If number is not in the word count it will just print out that number in the string.
  int messageLength3 = strlen(insaneMessage3);
  printf("%s\n",insaneMessage3);
  assert(strncmp("Sneaky professor -5 likes to burp when there is no one around.", insaneMessage3, messageLength3) == 0);
  free(insaneMessage3);
  return 0;
}



