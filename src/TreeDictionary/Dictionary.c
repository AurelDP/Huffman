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

    char temp;

    if (arbre == NULL)
    {
        printf("[arbre vide]\n");
        return NULL;
    }

    pile = (char*)realloc(pile, sizeof(char) * i);

    if (arbre->left->info == caractere)
    {   
        strcat(pile, '0');
        return pile;
    }

    if (arbre->right->info == caractere)
    {
        strcat(pile, '1');
        return pile;
    }

    i = i + 1;

    temp = pile;
    strcat(pile, '0');
    codage_huffman(arbre->left, caractere, pile, i);
    strcat(temp, '1');
    codage_huffman(arbre->right, caractere, temp, i);
}


void create_dico() {

        FILE* file = fopen("Files/dico.txt", "w");// [w] vide fichier si existant 

        
        Element* liste;
        Tree* arbre;
        char* pile;

        pile = (char*)malloc(sizeof(char));// creation chaine de caractère qui sera composé de 0 et 1
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