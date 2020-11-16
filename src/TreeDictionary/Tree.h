#ifndef TREE
#define TREE

typedef struct Data {
	char chara;
	int occurence;
}Data;

typedef struct Element {
	struct Data* data;
	struct Element* next;
}Element;

typedef struct Node {
	struct Tree* tree;
	struct Node* next;
}Node;

typedef struct Tree {
	struct Data* info;
	struct Tree* right;
	struct Tree* left;
}Tree;

Data* create_data(char c, int oc);
Element* create_element(Data* data);
Element* create_list(int number);

void print_data(Data* data);
void print_list(Element* list);

Data* min_list(Element* list);
void suppr_min_list(Element** list, char c, int occ);

int size_of_list(Element* list);

Tree* create_node(Data* info);
Tree* create_double_node(Element* list);

#endif