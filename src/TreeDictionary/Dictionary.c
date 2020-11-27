#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Dictionary.h"


///Question E

char* codage_huffman(Node* arbre, char caractere, char* pile, int i) {

    char temp;

    if (arbre == NULL)
    {
        printf("[arbre vide]\n");
        return NULL;
    }

    pile = (char*)realloc(pile, i *sizeof(char));

    if (arbre->left->info == caractere)
    {   
        strcat_s(pile,i, '0');
        return pile;
    }

    else if (arbre->right->info == caractere)
    {
        strcat_s(pile,i, '1');
        return pile;
    }

    else {

        i = i + 1;

        temp = pile;
        strcat_s(pile,i, '0');
        pile = codage_huffman(arbre->left, caractere, pile, i);
        strcat_s(temp,i, '1');
        pile = codage_huffman(arbre->right, caractere, temp, i);
    }
}


void create_dico(Node* arbre, List* liste) {
    FILE* file;
    fopen_s(&file, "Files/dico.txt", "w");// [w] vide fichier si existant 

    char* pile;

    pile = (char*)malloc(sizeof(char));// creation chaine de caractère qui sera composé de 0 et 1

    while (liste != NULL)
    {
        pile = NULL;
        codage_huffman(arbre, liste->data->chara, pile, 1);
        fprintf(file, "%c : ", liste->data->chara);
        fprintf(file, "%c", pile);
        fputs("\n", file);
        liste = liste->next;
    }

    fclose(file);
}