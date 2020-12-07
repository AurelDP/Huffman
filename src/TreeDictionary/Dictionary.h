/*****************************************************************//**
 * \file   Dictionary.h
 * \brief  Header file containing the dictionary generation functions.
 * 
 * \author Aurelien DUVAL aurelien.duval.19@efrei.net
 * \date   December 2020
 *********************************************************************/

#ifndef DICTIONARY
#define DICTIONARY
#include "../Structures/Structures.h"

/**
 * \brief Function that writes a binary string to a dictionary and a binary search tree from a character tree. Example :
 * \code{.c}
 * find_path(tree, path, 0, &BSTtree, depth);
 * \endcode
 * \param Node* tree, Huffman tree.
 * \param char* path, string containing the binary code.
 * \param int count, counter corresponding to the current height of the tree.
 * \param NodeBST** BSTtree, the BST tree to modify.
 * \param int depth, the depth of the tree (used for node allocation).
 * \return Nothing.
 */
void find_path(Node* tree, char* path, int count, NodeBST** BSTtree, int depth);

/**
 * \brief Dictionary and BST creation function. Example :
 * \code{.c}
 * NodeBST* BSTtree = create_dictio(huffman_tree);
 * \endcode
 * \param Node* tree, Huffman tree.
 * \return NodeBST* BSTtree, the new binary search tree.
 */
NodeBST* create_dictio(Node* tree);

/**
 * \brief Calculation of the maximum depth of a tree. Example :
 * \code{.c}
 * char* path = (char*)malloc(depth_tree(tree));
 * \endcode
 * \param Node* tree, Huffman tree.
 * \return int, the depth.
 */
int depth_tree(Node* tree);

/**
 * \brief Inserting a node in a BST. Example :
 * \code{.c}
 * insert_ABR_node(BSTtree, path, tree->info->chara, depth);
 * \endcode
 * \param NodeBST** BSTtree, the BST tree.
 * \param char* path, the binary path of the new char.
 * \param char c, the new char.
 * \parem int depth, the depth used to allocate the new binary path.
 * \return Nothing.
 */
void insert_ABR_node(NodeBST** BSTtree, char* path, char c, int depth);

/**
 * \brief Creating a new node. Example :
 * \code{.c}
 * NodeBST* new = create_ABR_node(path, c, depth);
 * \endcode
 * \param char* path, the binary path of the new char.
 * \param char c, the new char.
 * \parem int depth, the depth used to allocate the new binary path.
 * \return Nothing.
 */
NodeBST* create_ABR_node(char* path, char c, int depth);

/**
 * \brief Simple memory free function.
 * \param NodeBST* node, the node to free.
 * \return Nothing.
 */
void free_node_ABR(NodeBST* node);

#endif