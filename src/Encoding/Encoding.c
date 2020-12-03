#include <stdlib.h>
#include <stdio.h>
#include "Encoding.h"


void encod() {

    FILE* input = fopen("Files/input.txt", "r");
    FILE* output = fopen("Files/huffman.txt", "w");
    FILE* dico = fopen("Files/dico.txt", "r");

    char charInput;
    char charDico;
    char charLine;
    int stop = 0;

    while ((charInput = fgetc(input)) != EOF)
    {
        stop = 0;

        while ((charDico = fgetc(dico)) != EOF && stop == 0)
        {
            if ((charDico == charInput))
            {
                fseek(dico, 1, SEEK_CUR);
                while ((charLine = fgetc(dico)) != '\n')
                {
                    fputc(charLine, output); // On peut mettre les '010..' dans une chaine et seulement le push dans le fichier à la fin (ça optimisera un peu surement)
                }
                stop = 1;
            }
            else
            {
                while ((charLine = fgetc(dico)) != '\n')
                {
                    fseek(dico, 1, SEEK_CUR);
                }
            }
        }
        rewind(dico);
    }

    fclose(output);
    fclose(input);
    fclose(dico);
}