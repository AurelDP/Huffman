#ifndef DICTIONARY
#define DICTIONARY
#include "../Structures/Structures.h"


char* codage_huffman(Node* arbre, char caractere, char* pile, int* i);
void create_dico(Node* arbre, List* liste);

#endif