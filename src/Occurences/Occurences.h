/*****************************************************************//**
 * \file   Occurences.h
 * \brief  Header file grouping together the functions for classifying the characters of a text file.
 * 
 * \author Remi PAUCTON remi.paucton@efrei.net
 * \date   December 2020
 *********************************************************************/

#ifndef OCCURENCES
#define OCCURENCES
#include "../Structures/Structures.h"

/**
 * \brief Function to create a list of data from a text file. Example :
 * \code{.c}
 * List* list = occurence();
 * \endcode
 * \param Nothing.
 * \return A list of data.
 */
List* occurence();

/**
 * \brief Creates an element of a list from a character and returns it. Example :
 * \code{.c}
 * temp->next = create_new_link(c);
 * \endcode
 * \param char c, character to put in the new element.
 * \return The new element containing the character and an occurrence of 1.
 */
List* create_new_link(char c);

/**
 * \brief Checks if the character is already in the list. Example :
 * \code{.c}
 * if (verif_list(begin_list, c) == 0) {
 * \endcode
 * \param List* l, list to check.
 * \param char c, character to verify.
 * \return 0 if the character is not in the list, 1 otherwise.
 */
int verif_list(List* l, char c);

#endif