#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "BinaryTranslation/BinaryTranslation.h"
#include "Occurences/Occurences.h"
#include "TreeDictionary/Tree.h"
#include "TreeDictionary/Dictionary.h"
#include "Encoding/Encoding.h"

int main(){
    char choice = '0';
    int stop = 0;

    printf("-------------------------\n"
        "     Huffman project\n"
        "-------------------------\n");

    while (stop == 0) {

        do {
            printf("\n\nWhat is your choice:\n"
                " 1 - Launch Huffman encoder\n"
                " 2 - Launch Huffman decoder (warning: the decoder is not operational)\n"
                " 3 - How to use Huffman project?\n"
                " 4 - Close the program");
            printf("\nYour choice: ");
            gets(&choice);
        } while (choice != '1' && choice != '2' && choice != '3' && choice != '4');

        if (choice == '1') {
            if (text2binary()) {
                clock_t begin = clock();
                printf("\nStart encoding :\n\n");
                printf("Character recovery and classification...\n");
                List* list = occurence();
                ListTree* list_tree = transform_list(list);
                printf("Creation of the Huffman tree...\n");
                Node* huffman_tree = create_huffman_tree(&list_tree);
                printf("Creation of the dictionary...\n");
                NodeBST* BSTtree = create_dictio(huffman_tree);
                printf("Encoding...\n");
                encod(BSTtree);
                free_list(list);
                free_node(huffman_tree);
                free_node_ABR(BSTtree);
                printf("Encoding completed in %.2f seconds !\n\n", (clock() - begin) / (float)CLOCKS_PER_SEC);
                stop = 1;
            }
        }
        else if (choice == '2') {
            printf("\n\nThis part of the program is not implemented, please excuse us.\n"
                "\nPress ENTER to return to the main menu...");
            getchar();
            choice = '0';
        }
        else if (choice == '3'){
            printf("\n\nDescription of the project:\n"
                "The Huffman project is a program that allows you to transform a text file into a compressed file.\n"
                "The file to be compressed must be named \"input.txt\" and placed in the \"Files\" file.\n"
                "The compressed file will be \"huffman.txt\".\n"
                "\nPress ENTER to return to the main menu...");
            getchar();
            choice = '0';
        }
        else {
            printf("\nWell.. Ok, bye!\n");
            stop = 1;
        }

    }
    
    exit(0);
}