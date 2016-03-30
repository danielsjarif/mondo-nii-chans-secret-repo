#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "madlib.h"

int main(){
    char* madMessage = madlib("The %s %s likes to %s in the moonlight.", "cool", "git", "swim");
    int messageLength = strlen(madMessage);
    printf("%s\n",madMessage);
	assert(strncmp("The cool git likes to swim in the moonlight.", madMessage, messageLength) == 0);
	free(madMessage);

    char* madMessage1 = madlib("%s %s always %s", "Ugly", "Garry", "cries");
    int messageLength1 = strlen(madMessage1);
    printf("%s\n",madMessage1);
	assert(strncmp("Ugly Garry always cries.", madMessage1, messageLength1) == 0);
	free(madMessage1);

	char* madMessage2 = madlib("%s %s always %s too", "H4nds0m3", "S@m", "cr13$");
    int messageLength2 = strlen(madMessage2);
    printf("%s\n",madMessage1);
	assert(strncmp("H4nds0m3 S@m always cr13$ too.", madMessage2, messageLength2) == 0);
	free(madMessage2);
	
	return 0;
}