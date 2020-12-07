#include <stdlib.h>
#include <stdio.h>
#include "BinaryTranslation.h"

int text2binary() {
    FILE* file_txt = NULL;
    file_txt = fopen("Files/input.txt", "r");
    FILE* file_bin = NULL;
    file_bin = fopen("Files/binary.txt", "wb");
    char* bin = (char*)malloc(sizeof(9));

    char c = 0;

    if (file_txt != NULL) {
        do {
            c = fgetc(file_txt);
            if (c != EOF) {
                char2binary(c, &bin);
                fprintf(file_bin, bin);
            }
        } while (c != EOF);
        rewind(file_txt);
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
    int ascii = (int)c;
    char* bin = *string;
    int temp[8] = { 0 };

    for (int i = 0; ascii > 0; i++) {
        temp[i] = ascii % 2;
        ascii /= 2;
    }

    for (int j = 0; j < 8; j++) {
        bin[j] = (char)temp[7 - j] + 48;
    }

    bin[8] = '\0';
}