#include <stdlib.h>
#include <stdio.h>
#include "Encoding.h"


int Encod()
{
    int i = 1;
    FILE* fichier = NULL;
    char* caractereActuel = (char*)malloc(sizeof(char));
    char caractere;
    ListDico* Recup;
    Recup = malloc(sizeof(ListDico));
    fichier = fopen("Files/dico.txt", "r");

    

    if (fichier != NULL)
    {
        caractere = fgetc(fichier); // On lit le caractère
        caractereActuel[0] = caractere;

        while (caractere != EOF)
        {
                caractere = fgetc(fichier);
                //printf("%c", caractere);
                if (caractere != '\n'){
                    if (caractere == ':') {
                        Recup->lettre = caractereActuel[i-1];
                        //printf("%c", Recup->lettre); // On l'affiche
                        caractereActuel = NULL;
                    }
                    else{
                    i += 1;
                    caractereActuel = realloc(caractereActuel ,i * sizeof(char));
                    caractereActuel[i-1] = caractere;
                    }
                }
                else {
                    Recup->code = malloc(i * sizeof(char));
                    for (int y = 0; y < i; y++) {
                        Recup->code = Recup->code + caractereActuel[y];
                    }
                    ListDico* Recup2 = NULL;
                    Recup2 = malloc(sizeof(ListDico));
                    Recup->next = Recup2;
                    Recup = Recup->next;
                    caractereActuel = NULL;
                    i = 1;
                }
        } 

        fclose(fichier);
    }

    return 0;
}

