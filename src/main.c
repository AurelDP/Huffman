#include <stdlib.h>
#include <stdio.h>
#include "BinaryTranslation/BinaryTranslation.h"
#include "TreeDictionary/Tree.h"

int size_text(FILE* file);

int size_text(FILE* file) {
    int size = 0;
    char c;
    do {
        c = fgetc(file);
        if (c != EOF) {
            size++;
        }
    } while (c != EOF);
    rewind(file);
    return size;
}

int main() {
    text2binary();
    List* list = create_list(5);
    print_list(list);
    ListTree* list_tree = create_list_tree(list->data);
    print_list_tree(list_tree);
    exit(0);
}