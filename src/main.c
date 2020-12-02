#include <stdlib.h>
#include <stdio.h>
#include "BinaryTranslation/BinaryTranslation.h"
#include "Occurences/Occurences.h"
#include "TreeDictionary/Tree.h"

int main(){
    printf("Start encoding :\n\n");
    printf("Character recovery and classification...\n");
    List* list = occurence();
    ListTree* list_tree = transform_list(list);
    printf("Creation of the Huffman tree...\n");
    Node* huffman_tree = create_huffman_tree(&list_tree);
    free_list(list);
    free(list_tree);
    free_node(huffman_tree);
    printf("Encoding complete !\n\n");
    Encod();
    exit(0);
}