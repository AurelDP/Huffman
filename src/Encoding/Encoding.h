/*****************************************************************//**
 * \file   Encoding.h
 * \brief  Header file containing the encoding function.
 * 
 * \author Antoine PEPIN antoine.pepin@efrei.net
 * \date   December 2020
 *********************************************************************/

#ifndef ENCODING
#define ENCODING
#include "../Structures/Structures.h"

/**
 * \brief Converts each character in the text file to a character encoded by the BST. Example :
 * \code{.c}
 * encod(BSTtree);
 * \endcode
 * \param NodeBST* BSTtree, binary search tree containing characters and their codes.
 * \return Nothing.
 */
void encod(NodeBST* BSTtree);

#endif