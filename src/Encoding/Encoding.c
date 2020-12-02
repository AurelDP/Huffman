#include <stdlib.h>
#include <stdio.h>
#include "Encoding.h"




int Encod()
{
    int i = 2;
    FILE* fichier = NULL;
    char* caractereActuel = 0;
    char caractere;
    ListDico* Recup;
    Recup = malloc(sizeof(ListDico));
    fichier = fopen("Files/dico.txt", "r");

    

    if (fichier != NULL)
    {
        caractere = fgetc(fichier); // On lit le caractère
        caractereActuel = caractere;

        while (caractereActuel != EOF)
        {
                caractere = fgetc(fichier);

                if (caractere != '\n'){
                    if (caractere == ':') {
                        Recup->lettre = caractereActuel;
                        printf("%c", Recup->lettre); // On l'affiche
                        caractereActuel = NULL;
                        i = 1;
                    }
                    else{
                    caractereActuel = realloc(caractereActuel ,i * sizeof(char));
                    caractereActuel = caractereActuel + caractere;
                    i += 1;
                    }
                }
                else {
                    Recup->code = caractereActuel;
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