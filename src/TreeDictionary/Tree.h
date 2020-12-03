/*****************************************************************//**
 * \file   Tree.h
 * \brief  Header file containing the Huffman tree generation functions.
 * 
 * \author Aurelien DUVAL aurelien.duval.19@efrei.net
 * \date   December 2020
 *********************************************************************/

#ifndef TREE
#define TREE
#include "../Structures/Structures.h"


//-------------------------------------------------------------
// FONCTIONS DE TRANSFORMATION LISTE -> LISTE DE NOEUDS
//-------------------------------------------------------------

/**
 * \brief Node creation function.
 * \param Data* info, the information to be contained in the new node.
 * \return Node*, the new node created.
 */
Node* create_node(Data* info);

/**
 * \brief Function to create an element containing a node and a pointer to the following element.
 * \param Data* info, the information to be contained in the node of the new element.
 * \return ListTree*, the new element created.
 */
ListTree* create_list_tree(Data* info);

/**
 * \brief Function to transform a list of data into a list of nodes.
 * \param List* list, the list to be transformed.
 * \return ListTree*, the new list.
 */
ListTree* transform_list(List* list);


//-------------------------------------------------------------
// FONCTIONS DE TRANSFORMATION DE LA LISTE ET CREATION ARBRE
//-------------------------------------------------------------


/**
 * \brief Function that returns the minimum of a list of nodes. Example :
 * \code{.c}
 * Node* node_left = min_list(list);
 * \endcode
 * \param ListTree** list, initial list of which we want to find and delete the minimum.
 * \return Node*, the minimum node found.
 */
Node* min_list(ListTree** list);

/**
 * \brief Function that returns the minimum of a list of nodes. Example :
 * \code{.c}
 * Node* node_left = min_list(list);
 * \endcode
 * \param ListTree** list, initial list of which we want to find and delete the minimum.
 * \return Node*, the minimum node found.
 */
void suppr_min_list(ListTree** list, char c, int occ);

int size_of_list(ListTree* list);

Node* create_double_node(ListTree** list);

void insert_node(ListTree** list, Node* node);

Node* create_huffman_tree(ListTree** list);


//-------------------------------------------------------------
// FONCTIONS FREE
//-------------------------------------------------------------


void free_list(List* l);

void free_node(Node* node);


#endif