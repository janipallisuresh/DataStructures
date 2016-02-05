/**
 * @file singlelinkedlist.c
 * @author janipallisuresh
 * @date 05 Feb 2016
 * @brief Contains implementation of the functions declared in singlelinkedlist.h.
 * @see http://
 */
 
#include "singlelinkedlist.h"

/**
 * @function add_node
 * @brief Create a new node and add it to the list.
 */
void add_node(int add_data, s_node** head)
{
	s_node* newnode = (s_node*) malloc(sizeof(s_node));
	newnode->data = add_data;
	newnode->next = NULL;
	if(*head) {
		newnode->next = *head;
	}
	*head = newnode;
}

/**
 * @function display_list
 * @brief Print the single linked list.
 */
void display_list(s_node* head)
{
	s_node* current = head;
	while(current) {
		printf("[%d]-->", current->data);
		current = current->next;
	}
	printf("\\\n");
}

/**
 * @@function find_remove_loop
 * @brief Remove all duplicate nodes in the list
 */
int find_remove_loop(s_node** head)
{
	s_node* first = (*head);
	s_node* second = (*head);
	int i = 0, dup = -1;
	int loop_nodes_count = 1;
	
	if(!(*head)) {
		return dup;
	}
	
	while( first && second && second->next) {
		first = first->next;
        second = second->next->next;
		if(first->data == second->data) {
			dup = 0;
			break;
		}
	}
		
	if(dup != 0 ) {
	    printf("No LOOP PRESENT IN THE LIST\n");
	    return dup;
	}
	/* Count the number of nodes inside the loop */
	while(first->next != second){
	    first = first->next;
	    loop_nodes_count++;
	}
	
	/* Start one ponter from head and increment another to no of nodes inside the loop */
	first = (*head);
	second = (*head);
	for(i=0; i<loop_nodes_count; i++) {
	    second = second->next;
	}
	
	/* now move the two pointers - they will meet at the exact loop node */
	while(first != second){
	    first = first->next;
	    second = second->next;
	}
	
	/* move to last node to remove the loop */
	while(second->next != first){
	    second = second->next;
	}
	second->next = NULL;
	return first->data;
}

/**
 * @function remove_node
 * @brief Removes node with given data.
 */
void remove_node(int remove_data, s_node** head)
{
	s_node* current = (*head);
	s_node* previous = current;
	
	/*1. if Head is not null and the node to be removed is HEAD*/
	if( (*head) && (remove_data == (*head)->data) ) {
		(*head) = current->next;
		free(current);
		return;
	}
	/* 2. If the node to be removed is other than Head */
	while(current){
		if(remove_data == current->data) {
			previous->next = current->next;
            free(current);
			break;
		}
		previous = current;
		current = current->next;
	}
}

/** 
 * @function remove_recursive
 * @brief Removes the node by traversing the list recursively
 * Usage: head = remove_recursive(<x>, &head);
 */
s_node* remove_node_recursive(int remove_data, s_node** head)
{
	s_node* temp = NULL;
	if (!(*head))
		return (*head);
	
	if(remove_data == (*head)->data) {
	    temp = (*head)->next;
		free(*head);
		return temp;
	}
	/* if data is not matched then assigning return value to (*head)->next will preserve the linked list as is.*/
	(*head)->next = remove_node_recursive(remove_data, &((*head)->next));
	return *head;
}

/**
 * @function reverse_list
 * @brief Reverse the given single linked list
 */
void reverse_list(s_node** head)
{
	s_node* previous = NULL;
	s_node* current = (*head);
	s_node* next = NULL;
	
	while(current){
		next = current->next;  /* first store the next node */
		current->next = previous; /* now link the current node to its previous node */
		previous = current;  /* make current node as previous for the next iteration */
		current = next;  /* further move to next node */
	}
	(*head) = previous; /* since we moved until current is null, our first node is now stored in previous pointer */
}

/**
 * @function reverse_list_recursive
 * @brief Reverse the linked list recursively
 */
void reverse_list_recursive(s_node** head)
{
	s_node* current = NULL;
	s_node* next = NULL;
	if(!(*head)) {
		return;
	}
	current = (*head);
	next = (*head)->next;
	if(!next) {
		return;
	}
	reverse_list_recursive(&next); 
	current->next->next = current; /* Link the node which is next to the "Current node" To 'current' node */
	current->next = NULL;          /* Remove the existing link */
	
	(*head) = next; /* 'next' in the last iteration is the head now. so assign that to 'head' in every iteration */
}

/** 
 * @function reverse_list_group
 * @brief Reverse the linked list as groups.
 * Example: 
 * If INPUT list is - 1 2 3 4 5 6 7 8 and group_count is 3 then
 * OUTPUT Will be   - 3 2 1 6 5 4 8 7
 */
s_node* reverse_list_group(int group_count, s_node** head)
{
	s_node* previous = NULL;
	s_node* current = (*head);
	s_node* next = NULL;
	int count = 0;
	
	if (group_count <= 0)
		return (*head);
	
	while(current && count < group_count){
		next = current->next;
		current->next = previous;
		previous = current;
		current = next;
		count++;
	}
	if (next) {
		(*head)->next = reverse_list_group(group_count, &next);
	}
	
	(*head) = previous; /* Not really required but just to make sure head pointer is proper -
	                     - even if caller function does not catch up and assigns the return pointer to head. */
	return previous;
}
