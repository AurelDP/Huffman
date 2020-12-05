/*****************************************************************//**
 * \file   BinaryTranslation.h
 * \brief  Header file regrouping the functions for transforming text files into binary files.
 * 
 * \author Aurelien DUVAL aurelien.duval.19@efrei.net
 * \date   December 2020
 *********************************************************************/

#ifndef BINARY_TRANSLATION
#define BINARY_TRANSLATION

/**
 * \brief Converts a text file into a binary file.
 * \param Nothing.
 * \return 1 if file could be open, 0 if not.
 */
int text2binary();

/**
 * \brief Converts a text file into a binary file. Example :
 * \code{.c}
 * fprintf(file_bin, char2binary(c));
 * \endcode
 * \param char c, character to convert to binary.
 * \return A string of characters containing the binary code of the character given in parameter.
 */
char* char2binary(char c);

#endif