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
 * \brief Converts one character into binary code. Example :
 * \code{.c}
 * char2binary(c, &bin);
 * \endcode
 * \param char c, character to convert to binary.
 * \param char** string, string that will contain the binary code.
 * \return Nothing.
 */
void char2binary(char c, char** string);

#endif