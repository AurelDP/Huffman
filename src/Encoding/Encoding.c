#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Encoding.h"


void encod() {

    FILE* input = fopen("Files/input.txt", "r");
    FILE* output = fopen("Files/huffman.txt", "w");
    FILE* dico = fopen("Files/dico.txt", "r");

    char charInput;
    char charDico;
    char charTemp;
    char* charLine = (char*)malloc(sizeof(char));
    int stop = 0;
    int i = 0;

    while ((charInput = fgetc(input)) != EOF)
    {
        stop = 0;

        while ((charDico = fgetc(dico)) != EOF && stop == 0)
        {
            if ((charDico == charInput))
            {
                charLine = (char*)realloc(charLine, 1);
                charLine[0] = '\0';
                i = 0;
                fseek(dico, 1, SEEK_CUR);
                while ((charTemp = fgetc(dico)) != '\n')
                {
                    charLine = (char*)realloc(charLine, i + 2);
                    strcat(charLine, &charTemp);
                    charLine[i + 1] = '\0';
                    i++;
                }
                fprintf(output, "%s", charLine);
                stop = 1;
            }
            else
            {
                while ((charTemp = fgetc(dico)) != '\n')
                {
                    fseek(dico, 1, SEEK_CUR);
                }
            }
        }
        rewind(dico);
    }

    free(charLine);

    fclose(output);
    fclose(input);
    fclose(dico);
}