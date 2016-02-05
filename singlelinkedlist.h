/**
 * @file singlelinkedlist.h
 * @author janipallisuresh
 * @date 05 Feb 2016
 * @brief Contains declarations of functions supported in operating single linked list.
 * @see http://
 */
#ifndef SINGLELINKEDLIST_HEADER
#define SINGLELINKEDLIST_HEADER

#include <stdio.h>
#include <stdlib.h>

/** 
* @brief structure of a node in double linked list.
* data: integer.
* next: pointer to next node in the list.
*/
typedef struct node {
	int data;
	struct node* next;
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
