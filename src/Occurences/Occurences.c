#include <stdlib.h>
#include <stdio.h>
#include "Occurences.h"


ListTree* occurence() {
    
    // Opening the file and initializing the variables
    FILE* file = fopen("Files/input.txt", "r");
    char c = 0;

    ListTree* begin_list = NULL;
    ListTree* temp = NULL;
    int i = 0;

    // Browse through the entire text file
    do {
        c = fgetc(file);
        if (c != EOF) {
            
            // Check if the character to be picked is already in the list
            if (verif_list(begin_list, c) == 0) {

                // If the character is not there, we add it
                if (i == 0) {
                    begin_list = create_new_link(c);
                    temp = begin_list;
                    i++;
                }
                else {
                    temp->next = create_new_link(c);
                    temp = temp->next;
                }
            }
        }
    } while (c != EOF);

    fclose(file);

    return begin_list;
}

ListTree* create_new_link(char c) {

    // Allocation of all new variables
    ListTree* link = (ListTree*)malloc(sizeof(ListTree));
    Node* new_node = (Node*)malloc(sizeof(Node));
    Data* new_data = (Data*)malloc(sizeof(Data));

    // Data initialization
    new_data->chara = c;
    new_data->occurence = 1;

    // Node initialization
    new_node->left = NULL;
    new_node->right = NULL;
    new_node->info = new_data;

    // Link initialization
    link->node = new_node;
    link->next = NULL;

    return link;
}

int verif_list(ListTree* l, char c) {
    ListTree* temp = l;

    // We go through the whole list
    while (temp != NULL) {

        // If the character has been found, its occurrence is incremented by 1.
        if ((temp)->node->info->chara == c) {
            (temp)->node->info->occurence = (temp)->node->info->occurence + 1 ;
            return 1;
        }
        temp = (temp)->next;
    }
    return 0;
}