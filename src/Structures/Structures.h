#ifndef STRUCTURES
#define STRUCTURES

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

typedef struct ListDico {
	char lettre;
	char code;
	struct ListDico* next;
}ListDico;

#endif