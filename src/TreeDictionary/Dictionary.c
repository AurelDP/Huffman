#pragma warning(disable:4996)
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Dictionary.h"


int find_path(Node* tree, char c, char** path, int i) {
    int u = 0;
    if (tree == NULL) {
        return 0;
    }
    else {
        if (tree->info->chara == c) {
            *path = (char*)realloc(*path, sizeof(char));
            return 1;
        }
        else if (find_path(tree->right, c, path, i + 1)) {
            *path = (char*)realloc(*path, (strlen(*path) + 2) * sizeof(char));
            strcat(*path, "1");
            return 1;
        }
        else if (find_path(tree->left, c, path, i + 1)) {
            *path = (char*)realloc(*path, (strlen(*path) + 2) * sizeof(char));
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