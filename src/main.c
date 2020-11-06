#include <stdlib.h>
#include <stdio.h>
#include "BinaryTranslation/BinaryTranslation.h"

int size_text(FILE* file);

int size_text(FILE* file){
    int size = 0;
    char c;
    do{
        c = fgetc(file);
        if (c != EOF){
            size++;
        }
    }while(c != EOF);
    rewind(file);
    return size;
}

void main(){
    text2binary();
    exit(0);
}