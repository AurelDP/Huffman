#include <stdlib.h>
#include <stdio.h>
#include "Encoding.h"


void encod() {

    FILE* input = fopen("Files/input.txt", "r");
    FILE* output = fopen("Files/huffman.txt", "w");
    FILE* dico = fopen("Files/dico.txt", "r");

    char charInput;
    char charDico;
    int stop = 0;

    // We recover each character of the text file
    while ((charInput = fgetc(input)) != EOF) {

        stop = 0;

        // We check that we are not at the end of the dictionary and we recover the first character of the line
        while ((charDico = fgetc(dico)) != EOF && stop == 0) {
            
            // If the character is the one we are looking for
            if (charDico == charInput) {
                // Shift the cursor by 1 (pass the ":")
                fseek(dico, 1, SEEK_CUR);
                // As long as we are not at the end of the line, we write in the output file
                while ((charDico = fgetc(dico)) != '\n') {
                    fputc(charDico, output);
                }
                // Then we can break the loop
                stop = 1;
            }

            // If the character is not the one we want
            else {
                // We go to the next line and start again
                while (charDico != '\n'){
                    charDico = fgetc(dico);
                }
            }
        }
        rewind(dico);
    }

    fclose(output);
    fclose(input);
    fclose(dico);
}