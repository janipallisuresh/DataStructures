/**
 * @file doublelinkedlist.h
 * @author janipallisuresh
 * @date 05 Feb 2016
 * @brief Contains declarations of functions supported in operating double linked list.
 * @see http://
 */
 
#ifndef DOUBLELINKEDLIST_HEADER
#define DOUBLELINKEDLIST_HEADER

#include <stdio.h>
#include <stdlib.h>

/** 
* @brief structure of a node in double linked list.
* data: integer.
* prev: pointer to previous node in the list.
* next: pointer to next node in the list.
*/
typedef struct d_node {
	int data;
	struct d_node* prev;
	struct d_node* next;
}d_node;

void add_node_front(int data, d_node** head);
void add_node_end(int data, d_node** head);
void add_node_at(int data, int loc, d_node** head);

void display_list(d_node* head);
void display_reverse_list(d_node* head);

void remove_node(int data, d_node** head);
void remove_node_front(d_node** head);
void remove_node_end(d_node** head);
void remove_node_at(int at_loc, d_node** head);
d_node* remove_node_recursive(int data, d_node** head);

void reverse_list(d_node** head);
void reverse_list_recursive(d_node** head);

#endif

