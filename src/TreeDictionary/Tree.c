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

List* create_element(Data* data) {
	List* el = (List*)malloc(sizeof(List));
	el->data = data;
	el->next = NULL;
	return el;
}

List* create_list(int number) {
	List* list = NULL;
	List* temp = NULL;
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

void print_list(List* list) {
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


Node* create_node(Data* info) {
	Node* new_node = (Node*)malloc(sizeof(Node));
	new_node->info->occurence = info->occurence;
	new_node->info->chara = info->chara;
	new_node->right = NULL;
	new_node->left = NULL;
	return new_node;
}

ListTree* create_list_tree(Data* info) {
	ListTree* new_list = (ListTree*)malloc(sizeof(ListTree));
	new_list->next = NULL;
	new_list->node = create_node(info);
	return new_list;
}

ListTree* transform_list(List* list) {
	ListTree* new_list = NULL;
	ListTree * temp = new_list;
	if (list != NULL) {
		new_list = create_list_tree(list->data);
		temp = new_list;
		list = list->next;
	}
	while (list != NULL) {
		temp->next = create_list_tree(list->data);
		temp = temp->next;
		list = list->next;
	}
	return new_list;
}

void print_list_tree(ListTree* list) {
	printf("\nLISTE TREE : \n");
	while (list != NULL) {
		print_data(list->node->info);
		list = list->next;
	}
	printf("\n");
}

//-------------------------------------------------------------
// FONCTIONS DE TRANSFORMATION LISTE -> LISTE DE NOEUDS
//-------------------------------------------------------------


Data* min_list(List* list) {
	List* temp = NULL;
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

void suppr_min_list(List** list, char c, int occ) {
	List* old = NULL;
	if ((*list) != NULL) {
		suppr_min_list(&((*list)->next), c, occ);
		if ((*list)->data->chara == c && (*list)->data->occurence == occ) {
			old = (*list);
			(*list) = (*list)->next;
			free(old);
		}
	}
}

int size_of_list(List* list) {
	if (list == NULL) {
		return 0;
	}
	else {
		return 1 + size_of_list(list->next);
	}
}

Node* create_double_node(List* list) {
	Node* new_node = (Node*)malloc(sizeof(Node));
	Node* node_right = create_node(min_list(list));
	Node* node_left = create_node(min_list(list));
	new_node->right = node_right;
	new_node->left = node_left;
	new_node->info->occurence = node_right->info->occurence + node_left->info->occurence;
	return new_node;
}