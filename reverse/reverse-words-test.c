#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#include "reverse-words.h"
#include "reverse-range-in-place.h"

int main(){
	char* sentence = "Please help us sensei";
	char message[strlen(sentence)];
	strncpy(message,sentence,strlen(sentence));
    int sentenceLength = strlen(sentence);
    message[sentenceLength] = '\0';
    reverse_words(message);
    printf("%s\n",message);
	assert(strncmp("sensei us help Please", message, sentenceLength) == 0);
	free(sentence);
    
    char* sentence1 = "~xXX Dr@9& $l4y3r XXx~";
	char message1[strlen(sentence1)];
	strncpy(message1,sentence1,strlen(sentence1));
    int sentenceLength1 = strlen(sentence1);
    message1[sentenceLength1] = '\0';
    reverse_words(message1);
    printf("%s\n",message1);
	assert(strncmp("XXx~ $l4y3r Dr@9& ~xXX ", message1, sentenceLength1) == 0);
	free(sentence1);

    char* sentence2 = "Insert le epik meme here xDDDDDDDDD";
	char message2[strlen(sentence2)];
	strncpy(message2,sentence2,strlen(sentence2));
    int sentenceLength2 = strlen(sentence2);
    message2[sentenceLength2] = '\0';
    reverse_words(message2);
    printf("%s\n",message2);
	assert(strncmp("xDDDDDDDDD here meme epik le Insert", message2, sentenceLength2) == 0);
	free(sentence2);	

	char* sentence3 = " a b c d e fghijk lmno pqrs ";
	char message3[strlen(sentence2)];
	strncpy(message3,sentence3,strlen(sentence3));
    int sentenceLength3 = strlen(sentence3);
    message3[sentenceLength3] = '\0';
    reverse_words(message3);
    printf("%s\n",message3);
    assert(strncmp(" pqrs lmno fghijk e d c b a ", message3, sentenceLength3) == 0);
	free(sentence3);

    return 0;
}
