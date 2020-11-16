#include <stdlib.h>
#include <stdio.h>
#include "BinaryTranslation/BinaryTranslation.h"
#include "Occurences/Occurences.h"

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

int main(){
    text2binary();
    occurence();
}