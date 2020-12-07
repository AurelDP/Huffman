#pragma warning(disable:4996)
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Dictionary.h"


void find_path(Node* tree, char* path, int count, NodeBST** BSTtree, int depth) {
    if (tree != NULL) {

        // If we are on a leaf
        if (tree->right == NULL && tree->left == NULL) {

            // If the leaf corresponds to the root of the Huffman tree
            if (count == 0) {
                // There is only one character to code in the whole tree, we give it an arbitrary code
                path[count] = '0';
                path[count + 1] = '\0';
            }
            else
                path[count] = '\0';

            // A new node is inserted in the binary search tree based on the character and the binary code found
            insert_ABR_node(BSTtree, path, tree->info->chara, depth);

            // We add this code also in the dictionary (for a potential decoding)
            FILE* file = fopen("Files/dico.txt", "a");
            fprintf(file, "%c:", tree->info->chara);
            fprintf(file, "%s\n", path);
            fclose(file);
        }

        // If we are not on a leaf, we go right and left to add 0 or 1 to the binary string
        if (tree->right) {
            path[count] = '0';
            // Recursivity allows to find the code of each leaf of the tree
            find_path(tree->right, path, count + 1, BSTtree, depth);
        }
        if (tree->left) {
            path[count] = '1';
            find_path(tree->left, path, count + 1, BSTtree, depth);
        }
    }
}

NodeBST* create_dictio(Node* tree) {
    // We open and close the file to empty it
    FILE* file = fopen("Files/dico.txt", "w");
    fclose(file);

    // Initialization of variables
    char* path = NULL;
    NodeBST* BSTtree = NULL;

    // Tree depth recovery
    int depth = depth_tree(tree);

    // If the character is at the root, two characters are still needed to encode it
    if(depth <= 1)
        path = (char*)malloc(2);
    else
        // Otherwise we allocate as much memory as the depth of the tree to the binary path (avoids repetition of realloc)
        path = (char*)malloc(depth);

    // Creation of the dictionary and the binary tree
    find_path(tree, path, 0, &BSTtree, depth);

    free(path);
    return BSTtree;
}

// Simple tree depth recovery function
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
    // Creation of the new node and initialization of the variables
    NodeBST* new = create_ABR_node(path, c, depth);
    NodeBST* temp = *ABRtree;
    NodeBST* temp_old = temp;

    // If the BST is empty, the list takes the value of the new node
    if (*ABRtree == NULL)
        *ABRtree = new;
    
    // Otherwise, the new node is inserted at the right position in the tree
    else {

        do {
            temp_old = temp;

            // If the ASCII code of the new character node is bigger than the one of the node, we go to the right
            if ((int)c > (int)temp->info->chara) {
                temp = temp->right;

                // We fell on the leaf, so we can add the new node on the right side
                if (temp == NULL)
                    temp_old->right = new;
            }

            // Otherwise we go left
            else {
                temp = temp->left;
                if (temp == NULL)
                    temp_old->left = new;
            }

        } while (temp != NULL);
    }
}

NodeBST* create_ABR_node(char* path, char c, int depth) {
    // Allocation of variables
    NodeBST* new = (NodeBST*)malloc(sizeof(NodeBST));
    DataBST* data = (DataBST*)malloc(sizeof(DataBST));
    char* code = (char*)malloc(depth);
    
    // Code initialization
    strcpy(code, path);

    // Data initialization
    data->chara = c;
    data->code = code;

    // Node initialization
    new->left = NULL;
    new->right = NULL;
    new->info = data;

    return new;
}

// Simple memory free function
void free_node_ABR(NodeBST* node) {
    if (node != NULL) {
        free_node_ABR(node->left);
        free_node_ABR(node->right);
        free(node->info->code);
        free(node->info);
        free(node);
    }
}