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
 * \brief Function that returns a string of characters consisting of 0 or 1 depending on the path taken to arrive at a given character. Example :
 * \code{.c}
 * if (find_path(tree->right, c, path)) {
 * \endcode
 * \param Node* tree, Huffman tree.
 * \param char c, character to search.
 * \param char** path, string to be modified when the character has been found.
 * \return int i, 1 if the current character is the right one, 0 otherwise.
 */
int find_path(Node* tree, char c, char** path);

/**
 * \brief Dictionary creation function. Example :
 * \code{.c}
 * create_dictio(huffman_tree, list)
 * \endcode
 * \param Node* tree, Huffman tree.
 * \param List* l, list of characters in the text file.
 * \return Nothing.
 */
void create_dictio(Node* tree, List* l);

#endif