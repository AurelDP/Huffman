#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Dictionary.h"


typedef struct Element {
    int number;
    char character;
    struct Element* next;
} Element;


typedef struct Tree {
    struct Data* info;
    struct Tree* right;
    struct Tree* left;
}Tree;

///Question E

char* codage_huffman(Tree* arbre, char caractere, char* pile, int* i) {

    if (arbre == NULL)
    {
        printf("[arbre vide]\n");
        return NULL;
    }

    if (arbre->left == NULL && arbre->right == NULL) return file;

    pile = (char*)realloc(pile, sizeof(char) * i);

    if (arbre->left->info == caractere)
    {   
        strcat(pile, '0');
        return file;
    }
    else
    {
        strcat(pile, '1');
        i = i + 1;
        return codage_huffman(arbre->right, caractere, file, i);
    }


}


void create_dico() {

        FILE* file = fopen("Files/dico.txt", "w");// [w] vide fichier si existant 

        
        Element* liste;
        Tree* arbre;
        char* pile;

        pile = (char*)malloc(sizeof(char));
        liste = list_huffman();// liste chainee de Caractere.
        arbre = tree_occurence(liste);// Question D

        while (liste != NULL)
        {
            pile = NULL;
            codage_huffman(arbre, liste->character, pile, 1);
            fprintf(file, "%c : ", liste->character);
            fprintf(file, "%c", pile);
            fputs("\n", file);
            liste = liste->next;
        }

        free_arbre(arbre);// cree fonction free un arbre
        free_element(liste);// cree fonction free un element
        fclose(file);
}