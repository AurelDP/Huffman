#include <stdlib.h>
#include <stdio.h>
#include "BinaryTranslation/BinaryTranslation.h"
#include "Occurences/Occurences.h"
#include "TreeDictionary/Tree.h"
#include "TreeDictionary/Dictionary.h"

/*int size_text(FILE* file);

int size_text(FILE* file) {
    int size = 0;
    char c;
    do {
        c = fgetc(file);
        if (c != EOF) {
            size++;
        }
    } while (c != EOF);
    rewind(file);
    return size;
}*/

int main(){
    printf("Start encoding :\n\n");
    printf("Character recovery and classification...\n");
    List* list = occurence();
    ListTree* list_tree = transform_list(list);
    printf("Creation of the Huffman tree...\n");
    Node* huffman_tree = create_huffman_tree(&list_tree);
    create_dico(huffman_tree, list);

    free(list);
    free(list_tree);
    printf("Encoding complete !\n\n");
    exit(0);
}