#define _CRT_SECURE_NO_DEPRECATE                    // Bloque le rapport d'erreur de Visual Studio concernant la fonction "fopen"
#include <stdlib.h>
#include <stdio.h>
#include "Occurences.h"

Element* occurence() {

    FILE* file = fopen("file.txt", "r");
    char c;

    Element* begin_list = NULL;
    Element* temp = NULL;
    int i = 0;

    do {

        c = fgetc(file);
        if (c != EOF) {
            if (verif_list(begin_list, c) == 0) {

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
        if ((temp)->character == c) {
            (temp)->number++;
            return 1;
        }
        temp = (temp)->next;
    }
    return 0;
}





