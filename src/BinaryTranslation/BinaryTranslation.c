#include <stdlib.h>
#include <stdio.h>
#include "BinaryTranslation.h"

int text2binary() {
    // Opening text files
    FILE* file_txt = NULL;
    file_txt = fopen("Files/input.txt", "r");
    FILE* file_bin = NULL;
    file_bin = fopen("Files/binary.txt", "wb");

    // Allocation of a 9 - bit character string (8 + \0)
    char* bin = (char*)malloc(sizeof(9));

    char c = 0;

    if (file_txt != NULL) {

        // Retrieving each character of the text
        do {
            c = fgetc(file_txt);
            if (c != EOF) {
                // Character conversion to binary and writing to binary file
                char2binary(c, &bin);
                fprintf(file_bin, bin);
            }
        } while (c != EOF);

        // Closing text files
        fclose(file_txt);
        fclose(file_bin);
        return 1;
    }
    else {
        printf("\nError: Input file could not be opened!\n");
        fclose(file_bin);
        return 0;
    }

    free(bin);
}

void char2binary(char c, char** string) {
    // Retrieving the ASCII code of the input character
    int ascii = (int)c;

    // Simplified writing of the double input pointer and creation of a temporary integer array
    char* bin = *string;
    int temp[8] = { 0 };

    // Filling of the integer table by successive division method (creation of the binary code)
    for (int i = 0; ascii > 0; i++) {
        temp[i] = ascii % 2;
        ascii /= 2;
    }

    // Inversion of the obtained binary code
    for (int j = 0; j < 8; j++) {
        bin[j] = (char)temp[7 - j] + 48;
    }

    bin[8] = '\0';
}