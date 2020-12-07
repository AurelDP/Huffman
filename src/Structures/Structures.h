/*****************************************************************//**
 * \file   Structures.h
 * \brief  Header storing the different structures used in the project.
 * 
 * \author Aurelien DUVAL aurelien.duval.19@efrei.net
 * \date   December 2020
 *********************************************************************/

#ifndef STRUCTURES
#define STRUCTURES

/**
 * \typedef struct Data
 * \brief A data storing a character (char) and an occurrence (int).
 */
typedef struct Data {
	char chara;
	int occurence;
}Data;

/**
 * \typedef struct List
 * \brief A list of several data.
 */
typedef struct List {
	struct Data* data;
	struct List* next;
}List;

/**
 * \typedef struct ListTree
 * \brief A list of nodes (each node contains data and pointers to other nodes).
 */
typedef struct ListTree {
	struct Node* node;
	struct ListTree* next;
}ListTree;

/**
 * \typedef struct Node
 * \brief A node containing data and pointers to two other nodes.
 */
typedef struct Node {
	struct Data* info;
	struct Node* right;
	struct Node* left;
}Node;

typedef struct DataBST {
	char chara;
	char* code;
}DataBST;

typedef struct NodeBST {
	struct DataBST* info;
	struct NodeBST* right;
	struct NodeBST* left;
}NodeBST;

#endif