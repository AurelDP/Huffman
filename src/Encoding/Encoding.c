#include <stdlib.h>
#include <stdio.h>
#include "Encoding.h"


void encod() {

    FILE* input = fopen("Files/input.txt", "r");
    FILE* output = fopen("Files/output.txt", "w");
    FILE* dico = fopen("Files/dico.txt", "r");


    char caractere;
    char car;
    char ca;
    int i = 0;
    int stop = 0;


    while ((caractere = fgetc(input)) != EOF)
    {
        stop = 0;
        printf("\n(%c) , ", caractere);
        i++;
        while ((car = fgetc(dico)) != EOF && stop==0)
        {
            printf("%c", car);
            if ((car == caractere))
            {
                fseek(dico, 1, SEEK_CUR);
                while ((ca = fgetc(dico)) != '\n')
                {
                    printf("\n%c\n", ca);
                    fputc(ca, output);
                }
                stop = 1;
            }
            else
            {
                while ((ca = fgetc(dico)) != '\n')
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