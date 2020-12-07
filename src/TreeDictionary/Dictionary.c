#pragma warning(disable:4996)
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Dictionary.h"


void find_path(Node* tree, char* path, int count, NodeBST** BSTtree, int depth) {
    if (tree != NULL) {
        if (tree->right == NULL && tree->left == NULL) {
            if (count == 0) {
                path[count] = '0';
                path[count + 1] = '\0';
            }
            else
                path[count] = '\0';
            insert_ABR_node(BSTtree, path, tree->info->chara, depth);
            FILE* file = fopen("Files/dico.txt", "a");
            fprintf(file, "%c:", tree->info->chara);
            fprintf(file, "%s\n", path);
            fclose(file);
        }
        if (tree->right) {
            path[count] = '0';
            find_path(tree->right, path, count + 1, BSTtree, depth);
        }
        if (tree->left) {
            path[count] = '1';
            find_path(tree->left, path, count + 1, BSTtree, depth);
        }
    }
}

NodeBST* create_dictio(Node* tree) {
    FILE* file = fopen("Files/dico.txt", "w");
    fclose(file);
    char* path = NULL;
    NodeBST* BSTtree = NULL;
    int depth = depth_tree(tree);

    if(depth <= 1)
        path = (char*)malloc(2);    // If the character is at the root, two characters are still needed to encode it
    else
        path = (char*)malloc(depth);

    find_path(tree, path, 0, &BSTtree, depth);

    free(path);
    return BSTtree;
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

void insert_ABR_node(NodeBST** ABRtree, char* path, char c, int depth) {
    NodeBST* new = create_ABR_node(path, c, depth);
    NodeBST* temp = *ABRtree;
    NodeBST* temp_old = temp;
    if (*ABRtree == NULL)
        *ABRtree = new;
    else {
        do {
            temp_old = temp;
            if ((int)c > (int)temp->info->chara) {
                temp = temp->right;
                if (temp == NULL)
                    temp_old->right = new;
            }
            else {
                temp = temp->left;
                if (temp == NULL)
                    temp_old->left = new;
            }
        } while (temp != NULL);
    }
}

NodeBST* create_ABR_node(char* path, char c, int depth) {
    NodeBST* new = (NodeBST*)malloc(sizeof(NodeBST));
    DataBST* data = (DataBST*)malloc(sizeof(DataBST));
    char* code = (char*)malloc(depth);
    new->left = NULL;
    new->right = NULL;
    data->chara = c;
    strcpy(code, path);
    data->code = code;
    new->info = data;
    return new;
}

void free_node_ABR(NodeBST* node) {
    if (node != NULL) {
        free_node_ABR(node->left);
        free_node_ABR(node->right);
        free(node->info->code);
        free(node->info);
        free(node);
    }
}