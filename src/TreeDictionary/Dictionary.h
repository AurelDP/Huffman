#ifndef DICTIONARY
#define DICTIONARY

typedef struct Element {
    int number;
    char character;
    struct Element* next;
} Element;

typedef struct Tree {
    struct Data* info;
    struct Tree* right;
    struct Tree* left;
}Tree;

char* codage_huffman(Tree* arbre, char caractere, char* pile, int* i);
void create_dico();

#endif