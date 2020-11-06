#include <stdlib.h>
#include <stdio.h>
#include "BinaryTranslation.h"

void text2binary(){
    FILE* file_txt = NULL;
    file_txt = fopen("../../Files/input.txt", "r");
    FILE* file_bin = NULL;
    file_bin = fopen("../../Files/binary.txt", "wb");

    char c;

    if (file_txt != NULL){
        do{
            c = fgetc(file_txt);
            if (c != EOF){
                fprintf(file_bin, char2binary(c));  // Façon d'opitimiser : utiliser un dico et, si caractère déjà converti, ne pas appeler char2binary et mettre le code binaire directement
            }
        }while(c != EOF);
        rewind(file_txt);
    }

    fclose(file_txt);
    fclose(file_bin);
}

char* char2binary(char c){
    char* bin = (char*)malloc(9*sizeof(char));
    int ascii = (int)c;
    int temp[8] = {0};

    for(int i = 0; ascii > 0; i++){
        temp[i] = ascii%2;
        ascii /= 2;
    }

    for(int j = 0; j < 8; j++){
        bin[j] = (char)temp[7-j]+48;
    }

    bin[8] = '\0';

    return bin;
}