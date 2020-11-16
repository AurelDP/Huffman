#define _CRT_SECURE_NO_DEPRECATE                    // Bloque le rapport d'erreur de Visual Studio concernant la fonction "fopen"
#include <stdlib.h>
#include <stdio.h>
#include "Occurences.h"

Element* occurence() {

    FILE* file = fopen("file.txt", "r");

    char c;

    /*c = fgetc(file);
    Element* begin_list = creat_new_link (c);
    Element* temp = begin_list;
    printf("Lettre 1: %c\n", temp->character);
    printf("Occurence 1: %d\n", temp->number);*/

    Element* begin_list = NULL;
    Element* temp = begin_list;
    int i = 0;

    do {

        c = fgetc(file);
        if (c != EOF) {
            if (verif_list(begin_list, c) == 0) {

                /*
                Element* new_el = creat_new_link (c);
                temp->next = new_el;
                printf("stafal\n");
                */

                if (i == 0) {
                    begin_list = creat_new_link(c);
                    temp = begin_list;
                    i++;
                    printf("\nOK START\n");
                }
                else {
                    temp = creat_new_link(c);
                    printf("\nOK NEXT\n");
                }

            }
            printf("Lettre : %c\n", temp->character);
            printf("Occurence : %d\n", temp->number);
            temp = temp->next;
        }

    } while (c != EOF);

    rewind(file);
    fclose(file);

    return begin_list;

}



Element* creat_new_link(char c) {
    Element* link = malloc(sizeof(Element));
    link->character = c;
    link->number = 1;
    link->next = NULL;
    return link;

}


int verif_list(Element* l, char c) {
    Element* temp = l;

    while (temp != NULL) {

        printf("on est la 1 \n ");
        if ((temp)->character == c) {
            (temp)->number++;
            printf("on est la 2 \n ");
            return 1;
        }
        temp = (temp)->next;
    }
    return 0;
}





