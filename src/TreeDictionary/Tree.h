#ifndef TREE
#define TREE

// Information d'une liste ou d'un noeud
typedef struct Data {
	char chara;
	int occurence;
}Data;

// Structure d'une liste
typedef struct List {
	struct Data* data;
	struct List* next;
}List;

// Structure d'une liste de noeuds
typedef struct ListTree {
	struct Node* node;
	struct ListTree* next;
}ListTree;

// Structure d'un noeud d'arbre
typedef struct Node {
	struct Data* info;
	struct Node* right;
	struct Node* left;
}Node;

//-------------------------------------------------------------
// FONCTIONS DE CREATION DE LA LISTE (Rémi)
//-------------------------------------------------------------


Data* create_data(char c, int oc);

List* create_element(Data* data);

List* create_list(int number);

void print_data(Data* data);

void print_list(List* list);


//-------------------------------------------------------------
// FONCTIONS DE TRANSFORMATION LISTE -> LISTE DE NOEUDS
//-------------------------------------------------------------


Node* create_node(Data* info);

ListTree* create_list_tree(Data* info);

ListTree* transform_list(List* list);

void print_list_tree(ListTree* list);

//-------------------------------------------------------------
// FONCTIONS DE TRANSFORMATION LISTE -> LISTE DE NOEUDS
//-------------------------------------------------------------


Data* min_list(List* list);

void suppr_min_list(List** list, char c, int occ);

int size_of_list(List* list);

Node* create_double_node(List* list);

#endif