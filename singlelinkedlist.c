#include "singlelinkedlist.h"

/* Function: add_node
 * Create a new node and add it to the list.
 */
void add_node(int add_data, node** head)
{
	node *newnode = malloc(sizeof(node));
	newnode->data = add_data;
	newnode->link = (void*)NULL;
	if(*head) {
		newnode->link = *head;
	}
	*head = newnode;
}

/* Function: remove_node
 * Removes node with given data.
 */
void remove_node(int remove_data, node** head)
{
	node* current = (*head);
	node* previous = current;
	
	/*1. if Head is not null and the node to be removed is HEAD*/
	if( (*head) && (remove_data == (*head)->data) ) {
		(*head) = current->link;
		free(current);
		return;
	}
	/* 2. If the node to be removed is other than Head */
	while(current){
		if(remove_data == current->data) {
			previous->link = current->link;
            free(current);
			break;
		}
		previous = current;
		current = current->link;
	}
}

/* Function: display_list
 * Print the single linked list.
 */
void display_list(node* head)
{
	node* current = head;
	while(current) {
		printf("[%d]-->", current->data);
		current = current->link;
	}
	printf("\\\n");
}

/* Function: remove_recursive
 * Removes the node by traversing the list recursively
 * Usage: head = remove_recursive(<x>, &head);
 */
node* remove_node_recursive(int remove_data, node** head)
{
	node* temp = NULL;
	if (!(*head))
		return;
	
	if(remove_data == (*head)->data) {
	    temp = (*head)->link;
		free(*head);
		return temp;
	}
	/* if data is not matched then assigning return value to (*head)->link will preserve the linked list as is.*/
	(*head)->link = remove_recursive(remove_data, &((*head)->link));
	return *head;
}

/* Function: reverse_list
 * Reverse the given single linked list
 */
void reverse_list(node** head)
{
	node* previous = NULL;
	node* current = (*head);
	node* next = NULL;
	
	while(current){
		next = current->link;  /* first store the next node */
		current->link = previous; /* now link the current node to its previous node */
		previous = current;  /* make current node as previous for the next iteration */
		current = next;  /* further move to next node */
	}
	(*head) = previous; /* since we moved until current is null, our first node is now stored in previous pointer */
}

/* Function: reverse_list_recursive
 * Reverse the linked list recursively
 */
void reverse_list_recursive(node** head)
{
	node* current = NULL;
	node* next = NULL;
	if(!(*head)) {
		return;
	}
	current = (*head);
	next = (*head)->link;
	if(!next) {
		return;
	}
	reverse_list_recursive(&next); 
	current->link->link = current; /* Link the node which is next to the "Current node" To 'current' node */
	current->link = NULL;          /* Remove the existing link */
	
	(*head) = next; /* 'next' in the last iteration is the head now. so assign that to 'head' in every iteration */
}
