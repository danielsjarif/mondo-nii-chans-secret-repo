#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char* madlib_by_numbers(char* template, int word_count, char* words[]){
    int nums = 0;
    int size = 0;
    for(int i = 0; i < strlen(template); i++){
    if(isdigit(template[i]) && ((template[i] - '0') < word_count || (template[i] - '0') < 0)){
      nums++;
      size = size + strlen(words[template[i] - '0']);
    }
  }
    char temp[256];
    char* tmplCpy = malloc((strlen(template) - nums + size + 1) * sizeof(char));
    char remain[256];
    for(int i = 0; i <= strlen(template); i++){
        tmplCpy[i] = template[i];
    }   
    for(int i = 0; i < strlen(tmplCpy); i++){
        if(isdigit(tmplCpy[i]) && ((tmplCpy[i] - '0') < word_count || (tmplCpy[i] - '0') < 0)) {
            for(int j = 0; j < strlen(tmplCpy) - i; j++){
                remain[j] = tmplCpy[i + j + 1];
            }
            temp[i] = '\0';     
            strncpy(temp, tmplCpy, i);
            strcat(temp, words[tmplCpy[i] - '0']);
            strcpy(tmplCpy, temp);
            strcat(tmplCpy, remain);
            
        }
    }
    return tmplCpy;
}

