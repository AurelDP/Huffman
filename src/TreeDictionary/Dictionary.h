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
 * \brief Function that writes a binary string to a dictionary from a character tree. Example :
 * \code{.c}
 * find_path(tree, path, 0);
 * \endcode
 * \param Node* tree, Huffman tree.
 * \param char* path, string containing the binary code.
 * \param int count, counter corresponding to the current height of the tree.
 * \return Nothing.
 */
void find_path(Node* tree, char* path, int count);

/**
 * \brief Dictionary creation function. Example :
 * \code{.c}
 * create_dictio(huffman_tree, list)
 * \endcode
 * \param Node* tree, Huffman tree.
 * \return Nothing.
 */
void create_dictio(Node* tree);

/**
 * \brief Calculation of the maximum depth of a tree. Example :
 * \code{.c}
 * char* path = (char*)malloc(depth_tree(tree));
 * \endcode
 * \param Node* tree, Huffman tree.
 * \return int, the depth.
 */
int depth_tree(Node* tree);

#endif