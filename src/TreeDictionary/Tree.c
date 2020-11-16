#include <stdlib.h>
#include <stdio.h>
#include "Tree.h"


//-------------------------------------------------------------
// FONCTIONS DE CREATION DE LA LISTE (Rémi)
//-------------------------------------------------------------


Data* create_data(char c, int oc) {
	Data* data = (Data*)malloc(sizeof(Data));
	data->chara = c;
	data->occurence = oc;
	return data;
}

Element* create_element(Data* data) {
	Element* el = (Element*)malloc(sizeof(Element));
	el->data = data;
	el->next = NULL;
	return el;
}

Element* create_list(int number) {
	Element* list = NULL;
	Element* temp = NULL;
	if (number > 0) {
		for (int i = 0; i < number; i++) {
			if (i == 0) {
				Data* data = create_data(i + 65, i + 1);
				list = create_element(data);
				temp = list;
			}
			else {
				Data* data = create_data(i + 65, i + 1);
				temp->next = create_element(data);
				temp = temp->next;
			}
		}
	}
	return list;
}

void print_data(Data* data) {
	printf("\n%c x %d", data->chara, data->occurence);
}

void print_list(Element* list) {
	printf("\nLISTE : \n");
	while (list != NULL) {
		print_data(list->data);
		list = list->next;
	}
	printf("\n");
}


//-------------------------------------------------------------
// FONCTIONS DE TRANSFORMATION LISTE -> LISTE DE NOEUDS
//-------------------------------------------------------------





//-------------------------------------------------------------
// FONCTIONS DE TRANSFORMATION LISTE -> LISTE DE NOEUDS
//-------------------------------------------------------------


Data* min_list(Element* list) {
	Element* temp = NULL;
	Data* mini = (Data*)malloc(sizeof(Data));
	if (list != NULL) {
		temp = list;
		mini->occurence = temp->data->occurence;
		while (temp != NULL) {
			if (mini->occurence < temp->data->occurence) {
				mini->occurence = temp->data->occurence;
			}
			temp = temp->next;
		}
		suppr_min_list(&list, mini->chara, mini->occurence);
	}
	return mini;
}

void suppr_min_list(Element** list, char c, int occ) {
	Element* old = NULL;
	if ((*list) != NULL) {
		suppr_min_list(&((*list)->next), c, occ);
		if ((*list)->data->chara == c && (*list)->data->occurence == occ) {
			old = (*list);
			(*list) = (*list)->next;
			free(old);
		}
	}
}

int size_of_list(Element* list) {
	if (list == NULL) {
		return 0;
	}
	else {
		return 1 + size_of_list(list->next);
	}
}

Tree* create_node(Element* list) {
	Tree* new_node = (Tree*)malloc(sizeof(Tree);
	Tree* left = (Tree*)malloc(sizeof(Tree));
	Tree* right = (Tree*)malloc(sizeof(Tree));
	right->info = min_list(list);
	left->info = min_list(list);
	new_node->right = right;
	new_node->left = left;
	new_node->info->occurence = right->info->occurence + left->info->occurence;
	new_node->info->chara = NULL;
	return new_node;
}