#include <string.h>
#include <stdio.h>

int main(int argc, char** argv) {
    if(argc > 3) {
        printf("Too many arguments\n");
    } else if(argc < 3) {
            printf("Too few arguments\n");
    } else {
        int key1 = -1;
        int key2 = -1;
        char* notes[13] = {"C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "A#", "B"};
        char* intervals[13] = {"minor second", "major second", "minor third", "major third", "perfect fourth", "tritone", 
        "perfect fifth", "minor sixth", "major sixth", "minor seventh", "major seventh", "perfect octave"};
        for(int i = 0; i < 12; i++) {
            if(strcmp(argv[1], notes[i]) != 0 && i == 11){
                printf("Please enter a valid KEY for your 1st Argument\n");
            } else {
                if(strcmp(argv[1], notes[i]) == 0) {
                    key1 = i;
                    break;
                }
            }
        }
        for(int j = 0; j < 12; j++) {
            if(strcmp(argv[2], notes[j]) != 0 && j == 11){
                printf("Please enter a valid KEY for your 2nd Argument\n");
            } else {
                if(strcmp(argv[2], notes[j]) == 0) {
                    key2 = j;
                    break;
                }
            }
        }
        if(key1 < key2) {
        	int temp = key1;
        	key1 = key2;
        	key2 = temp;
        } else if(key1 == key2) {
        	key1 = 21;
        	key2 = 9;
        }
    printf("%s to %s is a %s\n", argv[1], argv[2], intervals[(key1 - key2) - 1]);
    }
    return 0;
}
