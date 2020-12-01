#ifndef DICTIONARY
#define DICTIONARY
#include "../Structures/Structures.h"


/*
char* codage_huffman(Node* arbre, char caractere, char* pile, int i);
void create_dico(Node* arbre, List* liste);
*/

int find_path(Node* tree, char c, char** path, int i);
void create_dictio(Node* tree, List* l);

#endif