#include <stdlib.h>
#include <stdio.h>
#include "Encoding.h"


void encod(NodeBST* BSTtree) {

    FILE* input = fopen("Files/input.txt", "r");
    FILE* output = fopen("Files/huffman.txt", "w");

    char charInput;
    NodeBST* temp;

    // We recover each character of the text file
    while ((charInput = fgetc(input)) != EOF) {

        temp = BSTtree;

        // As long as the character we are looking for is not found in the tree, we search right or left according to the ASCII code (ABR)
        while (charInput != temp->info->chara) {
            if ((int)charInput > (int)temp->info->chara)
                temp = temp->right;
            else
                temp = temp->left;
        }

        // When the character is found in the tree, we write its code in the output file
        fprintf(output, temp->info->code);

    }

    fclose(output);
    fclose(input);
}