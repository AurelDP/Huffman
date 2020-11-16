#ifndef OCCURENCES
#define OCCURENCES

typedef struct Data {
    char chara;
    int occurence;
}Data;

// Structure d'une liste
typedef struct List {
    struct Data* data;
    struct List* next;
}List;

List* occurence();
List* creat_new_link(char c);
int verif_list(List* l, char c);
void print_element(List* l);

#endif