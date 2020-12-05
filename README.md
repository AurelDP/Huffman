# Huffman
The goal of the Huffman project is to realize a text file compressor based on the rewriting of characters in binary.

## Algorithm decomposition
| Name | Description |
| --- | ----------- |
| Occurrences | List and count the characters present in the text file |
| Tree and dictionary | Place these characters in a tree and output a binary dictionary associating a binary number to each character |
| Encoding | Write the new binary file using the dictionary already created |
| Decoding | Recovery of the dictionary and reconstruction of the text file from the binary file (**Not done**) |

### Context
This project is part of a continuous learning of the C language and is a group project graded in the framework of studies.

### Documentation
Documentation has been added to the Huffman project. Integrated in the `.h`, it is also visible in the `Doxygen` folder. In case of problems, it is advised to regenerate it from the `Doxywizard` software.

### Contributors
[Duval Aurélien](https://github.com/AurelDP) | [Paucton Rémi](https://github.com/Remi-paucton) | [Pépin Antoine](https://github.com/AntoinePEPIN) | [Pouget Lucien](https://github.com/Lucienpg) | [Rabiller Jean-Baptiste](https://github.com/JBRabiller)

# How to use?

Clone the repository on your computer.

### If you use Microsoft Visual Studio

Just run `Huffman.sln`.

### Otherwise

Copy [Huffman.exe](/x64/Debug) (`x64/Debug`) to the project root and run it.
