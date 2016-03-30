#include <string.h>
#include <stdio.h>
#include "reverse-range-in-place.h"


char reverse_words(char* string){
	int start = 0;
	for(int i = 0; i < strlen(string) + 1; i++){
		if(string[i] == ' ' || string[i] == '\0'){
			reverse_range_in_place(string, start, i - 1);
			start = i + 1;
		}
	}
	reverse_range_in_place(string, 0, strlen(string));
}