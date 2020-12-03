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
 * \brief Deletes an item from a list based on its information. Example :
 * \code{.c}
 * suppr_min_list(&((*list)->next), c, occ);
 * \endcode
 * \param ListTree** list, list in which we want to remove the item.
 * \param char c, information on the item to be deleted.
 * \param int occ, information on the item to be deleted.
 * \return Nothing.
 */
void suppr_min_list(ListTree** list, char c, int occ);

/**
 * \brief Simple function that gives the size of a list of nodes.
 * \param ListTree* list, the list.
 * \return int, the size of the list.
 */
int size_of_list(ListTree* list);

/**
 * \brief Function to create a node from two old nodes.
 * \param ListTree** list, the initial list containing all nodes.
 * \return Node*, the new node created.
 */
Node* create_double_node(ListTree** list);

/**
 * \brief Function used to insert a node in a list of nodes.
 * \param ListTree** list, the initial list containing all nodes.
 * \param Node* node, the node to insert.
 * \return Nothing.
 */
void insert_node(ListTree** list, Node* node);

/**
 * \brief Huffman tree creation function. Example :
 * \code{.c}
 * Node* huffman_tree = create_huffman_tree(&list_tree);
 * \endcode
 * \param ListTree** list, list from which the Huffman tree is created.
 * \return Node*, the new Huffman tree.
 */
Node* create_huffman_tree(ListTree** list);


//-------------------------------------------------------------
// FONCTIONS FREE
//-------------------------------------------------------------


/**
 * \brief Simple function for free a list.
 * \param List* l, the list.
 * \return Nothing.
 */
void free_list(List* l);

/**
 * \brief Simple function for free a node.
 * \param Node* node, the node.
 * \return Nothing.
 */
void free_node(Node* node);


#endif