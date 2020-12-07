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
// LIST TRANSFORMATION AND TREE CREATION FUNCTIONS
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
 * Node* huffman_tree = create_huffman_tree(&list);
 * \endcode
 * \param ListTree** list, list from which the Huffman tree is created.
 * \return Node*, the new Huffman tree.
 */
Node* create_huffman_tree(ListTree** list);


//-------------------------------------------------------------
// FREE FUNCTIONS
//-------------------------------------------------------------


/**
 * \brief Simple function for free a node.
 * \param Node* node, the node.
 * \return Nothing.
 */
void free_node(Node* node);


#endif