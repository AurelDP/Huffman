#include <stdlib.h>
#include <stdio.h>
#include "Tree.h"


//-------------------------------------------------------------
// LIST TRANSFORMATION AND TREE CREATION FUNCTIONS
//-------------------------------------------------------------


Node* min_list(ListTree** list) {
	// Initialization of variables
	ListTree* temp = NULL;
	Node* mini;

	if (*list != NULL) {

		// Retrieving the minimum of the list
		temp = *list;
		mini = temp->node;
		while (temp != NULL) {
			if (mini->info->occurence > temp->node->info->occurence) {
				mini = temp->node;
			}
			temp = temp->next;
		}

		// Removing the minimum from the list
		suppr_min_list(list, mini->info->chara, mini->info->occurence);
	}
	else {
		mini = NULL;
	}
	return mini;
}

void suppr_min_list(ListTree** list, char c, int occ) {
	// Initialization of variables
	ListTree* old = NULL;
	int stop = 0;

	if (*list != NULL) {

		// If the character and the occurrence correspond to the ones to be deleted
		if ((*list)->node->info->chara == c && (*list)->node->info->occurence == occ) {

			// Element deletion and memory free
			old = (*list);
			*list = (*list)->next;
			free(old);
			stop = 1;
		}

		// If the item has not been found, continue the search
		if (*list != NULL && stop == 0)
			suppr_min_list(&((*list)->next), c, occ);
	}
}

// Simple function that returns the size of a list
int size_of_list(ListTree* list) {
	if (list == NULL) {
		return 0;
	}
	else {
		return 1 + size_of_list(list->next);
	}
}


Node* create_double_node(ListTree** list) {
	// Allocation and initialization of variables from 2 minimums of the list
	Node* new_node = (Node*)malloc(sizeof(Node));
	Node* node_right = min_list(list);
	Node* node_left = min_list(list);
	Data* new_info = (Data*)malloc(sizeof(Data));

	// Initialization of new information
	new_info->chara = '\0';
	new_info->occurence = node_right->info->occurence + node_left->info->occurence;

	// Initialization of new node
	new_node->right = node_right;
	new_node->left = node_left;
	new_node->info = new_info;

	return new_node;
}

// Function to reinsert a node in a list of nodes
void insert_node(ListTree** list, Node* node) {
	ListTree* new_node = (ListTree*)malloc(sizeof(ListTree));
	new_node->node = node;
	new_node->next = *list;
	*list = new_node;
}

Node* create_huffman_tree(ListTree** list) {
	Node* tree;

	if (*list != NULL) {

		// As long as the node list contains more than one element
		while (size_of_list(*list) > 1) {

			// We merge the two minimum elements together and reinsert the newly created node
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
// FREE FUNCTIONS
//-------------------------------------------------------------


// Simple memory free function
void free_node(Node* node) {
	if (node != NULL) {
		free_node(node->left);
		free_node(node->right);
		free(node->info);
		free(node);
	}
}