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
typedef struct s_node {
	int data;
	struct s_node* next;
} s_node;

void add_node(int add_data, s_node** head);
void add_node_end(int add_data, s_node** head);
void add_node_front(int add_data, s_node** head);
void delete_list(s_node** head);
void display_list(s_node* head);
int find_remove_loop(s_node** head);
void remove_node(int remove_data, s_node** head);
s_node* remove_node_recursive(int remove_data, s_node** head);
void reverse_list(s_node** head);
void reverse_list_recursive(s_node** head);
s_node* reverse_list_group(int group_count, s_node** head);

#endif
