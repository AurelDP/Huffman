#ifndef OCCURENCES
#define OCCURENCES

typedef struct Element {
    int number;
    char character;
    struct Element* next;
} Element;

Element* occurence();
Element* creat_new_link(char c);
int verif_list(Element* l, char c);
void print_element(Element* l);

#endif