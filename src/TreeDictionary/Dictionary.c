#pragma warning(disable:4996)
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Dictionary.h"


int find_path(Node* tree, char c, char** path) {
    if (tree == NULL) {
        return 0;
    }
    else {
        if (tree->info->chara == c) {
            *path = (char*)realloc(*path, 1);
            *path[0] = '\0';
            return 1;
        }
        else if (find_path(tree->right, c, path)) {
            *path = (char*)realloc(*path, strlen(*path) + 2);
            strcat(*path, "1");
            return 1;
        }
        else if (find_path(tree->left, c, path)) {
            *path = (char*)realloc(*path, strlen(*path) + 2);
            strcat(*path, "0");
            return 1;
        }
        else {
            return 0;
        }
    }
}

void create_dictio(Node* tree, List* l) {
    FILE* file;
    char* path = (char*)malloc(1);

    file = fopen("Files/dico.txt", "w");

    while (l != NULL) {
        path[0] = '\0';
        find_path(tree, l->data->chara, &path);
        strrev(path);
        fprintf(file, "%c : ", l->data->chara);
        fprintf(file, "%s\n", path);
        l = l->next;
    }

    free(path);
    fclose(file);
}