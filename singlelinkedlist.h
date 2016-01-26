#ifndef SINGLELINKEDLIST_HEADER
#define SINGLELINKEDLIST_HEADER

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node* link;
} node;

void add_node(int add_data, node** head);
void display_list(node* head);
int find_remove_loop(node** head);
void remove_node(int remove_data, node** head);
node* remove_node_recursive(int remove_data, node** head);
void reverse_list(node** head);
void reverse_list_recursive(node** head);
node* reverse_list_group(int group_count, node** head);

#endif
