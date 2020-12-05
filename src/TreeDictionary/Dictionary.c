#pragma warning(disable:4996)
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Dictionary.h"


void find_path(Node* tree, char* path, int count) {
    if (tree->right == NULL && tree->left == NULL) {
        if (count == 0)
            path[count] = '0';
        else
            path[count] = '\0';
        FILE* file = fopen("Files/dico.txt", "a");
        fprintf(file, "%c:", tree->info->chara);
        fprintf(file, "%s\n", path);
        fclose(file);
    }
    if (tree->right) {
        path[count] = '1';
        find_path(tree->right, path, count + 1);
    }
    if (tree->left) {
        path[count] = '0';
        find_path(tree->left, path, count + 1);
    }
}

void create_dictio(Node* tree) {
    FILE* file = fopen("Files/dico.txt", "w");
    fclose(file);

    char* path = (char*)malloc(depth_tree(tree));

    find_path(tree, path, 0);

    free(path);
}

int depth_tree(Node* tree) {
    if (tree == NULL) {
        return 0;
    }
    else {
        int left = depth_tree(tree->left);
        int right = depth_tree(tree->right);
        if (left > right)
            return 1 + depth_tree(tree->left);
        else
            return 1 + depth_tree(tree->right);
    }
}