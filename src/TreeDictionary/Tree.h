#ifndef TREE
#define TREE
#include "../Structures/Structures.h"


//-------------------------------------------------------------
// FONCTIONS DE TRANSFORMATION LISTE -> LISTE DE NOEUDS
//-------------------------------------------------------------


Node* create_node(Data* info);

ListTree* create_list_tree(Data* info);

ListTree* transform_list(List* list);


//-------------------------------------------------------------
// FONCTIONS DE TRANSFORMATION DE LA LISTE ET CREATION ARBRE
//-------------------------------------------------------------


Node* min_list(ListTree** list);

void suppr_min_list(ListTree** list, char c, int occ);

int size_of_list(ListTree* list);

Node* create_double_node(ListTree** list);

void insert_node(ListTree** list, Node* node);

Node* create_huffman_tree(ListTree** list);


#endif