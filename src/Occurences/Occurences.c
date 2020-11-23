#define _CRT_SECURE_NO_DEPRECATE                    // Bloque le rapport d'erreur de Visual Studio concernant la fonction "fopen"
#include <stdlib.h>
#include <stdio.h>
#include "Occurences.h"

List* occurence() {
    
    FILE* file = fopen("Files/input.txt", "r");
    char c;

    List* begin_list = NULL;
    List* temp = NULL;
    int i = 0;

    do {
        c = fgetc(file);
        if (c != EOF) {

            if (verif_list(begin_list, c) == 0) {

                if (i == 0) {
                    begin_list = creat_new_link(c);
                    temp = begin_list;
                    i++;
                }
                else {
                    temp->next = creat_new_link(c);
                    temp = temp->next;
                }
            }
        }
    } while (c != EOF);

    rewind(file);
    fclose(file);

    return begin_list;
}

List* creat_new_link(char c) {
    List* link = malloc(sizeof(List));
    Data* data= malloc(sizeof(Data));
    data->chara = c;
    data->occurence= 1;
    link->data = data;
    link->next = NULL;
    return link;
}

int verif_list(List* l, char c) {
    List* temp = l;

    while (temp != NULL) {
        if ((temp)->data->chara == c) {
            (temp)->data->occurence = (temp)->data->occurence + 1 ;
            return 1;
        }
        temp = (temp)->next;
    }
    return 0;
}