#include <stdlib.h>
#include <stdio.h>
#include "Encoding.h"




int Encod()
{
    FILE* fichier = NULL;
    char caractereActuel = 0;
    ListDico* Recup;
    Recup = malloc(sizeof(ListDico));
    fichier = fopen("Files/dico.txt", "r");


    if (fichier != NULL)
    {

        while (caractereActuel != EOF)
        {
                caractereActuel = fgetc(fichier); // On lit le caractère
                //if (caractereActuel)
                Recup->lettre = caractereActuel;
                printf("%c", Recup->lettre); // On l'affiche
        } 

        fclose(fichier);
    }

    return 0;
}