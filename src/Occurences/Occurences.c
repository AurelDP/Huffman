#include <stdlib.h>
#include <stdio.h>
#include "Occurences.h"


ListTree* occurence() {
    
    FILE* file = fopen("Files/input.txt", "r");
    char c = 0;

    ListTree* begin_list = NULL;
    ListTree* temp = NULL;
    int i = 0;

    do {
        c = fgetc(file);
        if (c != EOF) {

            if (verif_list(begin_list, c) == 0) {

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

    rewind(file);
    fclose(file);

    return begin_list;
}

ListTree* create_new_link(char c) {
    ListTree* link = (ListTree*)malloc(sizeof(ListTree));
    Node* new_node = (Node*)malloc(sizeof(Node));
    Data* new_data = (Data*)malloc(sizeof(Data));
    new_data->chara = c;
    new_data->occurence = 1;
    new_node->left = NULL;
    new_node->right = NULL;
    new_node->info = new_data;
    link->node = new_node;
    link->next = NULL;
    return link;
}

int verif_list(ListTree* l, char c) {
    ListTree* temp = l;

    while (temp != NULL) {
        if ((temp)->node->info->chara == c) {
            (temp)->node->info->occurence = (temp)->node->info->occurence + 1 ;
            return 1;
        }
        temp = (temp)->next;
    }
    return 0;
}