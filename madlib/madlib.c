#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* madlib(char* template, char* adjective, char* noun, char* verb){
	char* sentence = malloc((strlen(template) + strlen(adjective) + strlen(noun) + strlen(verb) + 1) * sizeof(char));
    sprintf(sentence,template,adjective,noun,verb);
	return sentence;
}