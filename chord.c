#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char** argv) {
    if(argc > 2) {
        printf("Too many arguments\n");
    } else {
        if(argc < 2) {
            printf("Too few arguments\n");
        } else {
            int key = -1;
            char* notes[13] = {"C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "A#", "B"};
            for(int i = 0; i < 12; i++) {
                if(strcmp(argv[1], notes[i]) != 0 && i == 11){
                    printf("Please enter a valid key in uppercase\n");
                } else {
                    if(strcmp(argv[1], notes[i]) == 0) {
                        key = i;
                        break;
                    }
                }
            }
        printf("Chord %s\n", argv[1]);
        printf("%s: %s %s %s\n", argv[1], notes[key], notes[(key + 4)%12], notes[(key + 7) % 12]);
        printf("%sm: %s %s %s\n", argv[1], notes[key], notes[(key + 3)%12], notes[(key + 7) % 12]);
        printf("%s7: %s %s %s %s\n", argv[1], notes[key], notes[(key + 4)%12], notes[(key + 7) % 12], notes[(key + 10) % 12]);
        printf("%sdim7: %s %s %s %s\n", argv[1], notes[key], notes[(key + 3)%12], notes[(key + 6) % 12], notes[(key + 9) % 12]);
        }
        
    }
    return 0;
}
