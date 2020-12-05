#include <stdlib.h>
#include <stdio.h>
#include "Tree.h"


//-------------------------------------------------------------
// FONCTIONS DE TRANSFORMATION LISTE -> LISTE DE NOEUDS
//-------------------------------------------------------------


Node* create_node(Data* info) {
	Node* new_node = (Node*)malloc(sizeof(Node));
	new_node->info = info;
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
	ListTree* temp = new_list;
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


//-------------------------------------------------------------
// FONCTIONS DE TRANSFORMATION DE LA LISTE ET CREATION ARBRE
//-------------------------------------------------------------


Node* min_list(ListTree** list) {
	ListTree* temp = NULL;
	Node* mini;
	if (*list != NULL) {
		temp = *list;
		mini = temp->node;
		while (temp != NULL) {
			if (mini->info->occurence > temp->node->info->occurence) {
				mini = temp->node;
			}
			temp = temp->next;
		}
		suppr_min_list(list, mini->info->chara, mini->info->occurence);
	}
	else {
		mini = NULL;
	}
	return mini;
}

void suppr_min_list(ListTree** list, char c, int occ) {
	ListTree* old = NULL;
	int stop = 0;
	if (*list != NULL) {
		if ((*list)->node->info->chara == c && (*list)->node->info->occurence == occ) {
			old = (*list);
			*list = (*list)->next;
			free(old);
			stop = 1;
		}
		if (*list != NULL && stop == 0)
			suppr_min_list(&((*list)->next), c, occ);
	}
}

int size_of_list(ListTree* list) {
	if (list == NULL) {
		return 0;
	}
	else {
		return 1 + size_of_list(list->next);
	}
}

Node* create_double_node(ListTree** list) {
	Node* new_node = (Node*)malloc(sizeof(Node));
	Node* node_right = min_list(list);
	Node* node_left = min_list(list);
	Data* new_info = (Data*)malloc(sizeof(Data));
	new_node->right = node_right;
	new_node->left = node_left;
	new_info->chara = '\0';
	new_info->occurence = node_right->info->occurence + node_left->info->occurence;
	new_node->info = new_info;
	return new_node;
}

void insert_node(ListTree** list, Node* node) {
	ListTree* new_node = (ListTree*)malloc(sizeof(ListTree));
	new_node->node = node;
	new_node->next = *list;
	*list = new_node;
}

Node* create_huffman_tree(ListTree** list) {
	Node* tree;
	if (*list != NULL) {
		while (size_of_list(*list) > 1) {
			Node* new_node = create_double_node(list);
			insert_node(list, new_node);
		}
		tree = (*list)->node;
	}
	else {
		tree = NULL;
	}
	return tree;
}


//-------------------------------------------------------------
// FONCTIONS FREE
//-------------------------------------------------------------


void free_list(List* l) {
	if (l != NULL) {
		free_list(l->next);
		free(l);
	}
}

void free_node(Node* node) {
	if (node != NULL) {
		free_node(node->left);
		free_node(node->right);
		free(node->info);
		free(node);
	}
}