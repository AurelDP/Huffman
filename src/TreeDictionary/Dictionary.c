#pragma warning(disable:4996)
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Dictionary.h"


/*char* codage_huffman(Node* arbre, char caractere, char* pile, int i) {

    char* temp;

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
        strcat_s(pile, i, '0');
        pile = codage_huffman(arbre->left, caractere, pile, i);
        strcat_s(temp, i, '1');
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
}*/

int find_path(Node* tree, char c, char** path, int i) {
    int u = 0;
    if (tree == NULL) {
        return 0;
    }
    else {
        if (tree->info->chara == c) {
            *path = (char*)realloc(*path, sizeof(char));
            *path[0] = '\0';
            return 1;
        }
        else if (find_path(tree->right, c, path, i + 1)) {
            while (*path[u] != '\0') {
                u++;
            }
            printf("\n nouvelle taille = %d\n", (strlen(*path) + 2) * sizeof(char));
            *path = (char*)realloc(*path, (strlen(*path) + 2) * sizeof(char));
            *path[u] = '1';
            printf("\n0 = %c, 1 = %c\n", *path[u], *path[u + 1]);
            printf("Indice du \\0 : %d\n", u + 1);
            *path[u + 1] = '\0';
            u = 0;
            //strcat(path, "1");
            return 1;
        }
        else if (find_path(tree->left, c, path, i + 1)) {
            while (*path[u] != '\0') {
                u++;
            }
            *path = (char*)realloc(*path, (strlen(*path) + 2) * sizeof(char));
            *path[u] = '0';
            printf("\n0 = %c, 1 = %c\n", *path[u], *path[u+1]);
            *path[u + 1] = '\0';
            u = 0;
            //strcat(path, "0");
            return 1;
        }
        else {
            return 0;
        }
    }
}

void create_dictio(Node* tree, List* l) {
    FILE* file;
    char* path = (char*)malloc(sizeof(char));

    fopen_s(&file, "Files/dico.txt", "w");

    while (l != NULL) {
        path = realloc(path, sizeof(char));
        path = '\0';
        find_path(tree, l->data->chara, &path, 1);
        printf("\n\nPath : %s\n\n", path);
        fprintf(file, "%c : ", l->data->chara);
        fprintf(file, "%s\n", path);
        l = l->next;
    }

    free(path);
    fclose(file);
}