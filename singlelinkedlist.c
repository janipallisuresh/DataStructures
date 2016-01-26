#include "singlelinkedlist.h"

/* Function: add_node
 * Create a new node and add it to the list.
 */
void add_node(int add_data, node** head)
{
	node *newnode = (node*) malloc(sizeof(node));
	newnode->data = add_data;
	newnode->link = NULL;
	if(*head) {
		newnode->link = *head;
	}
	*head = newnode;
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

/* FUNCTION: find_remove_loop
 * Remove all duplicate nodes in the list
 */
int find_remove_loop(node** head)
{
	node* first = (*head);
	node* second = (*head);
	int i = 0, dup = -1;
	int loop_nodes_count = 1;
	
	if(!(*head)) {
		return dup;
	}
	
	while( first && second && second->link) {
		first = first->link;
        second = second->link->link;
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
	while(first->link != second){
	    first = first->link;
	    loop_nodes_count++;
	}
	
	/* Start one ponter from head and increment another to no of nodes inside the loop */
	first = (*head);
	second = (*head);
	for(i=0; i<loop_nodes_count; i++) {
	    second = second->link;
	}
	
	/* now move the two pointers - they will meet at the exact loop node */
	while(first != second){
	    first = first->link;
	    second = second->link;
	}
	
	/* move to last node to remove the loop */
	while(second->link != first){
	    second = second->link;
	}
	second->link = NULL;
	return first->data;
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

/* Function: remove_recursive
 * Removes the node by traversing the list recursively
 * Usage: head = remove_recursive(<x>, &head);
 */
node* remove_node_recursive(int remove_data, node** head)
{
	node* temp = NULL;
	if (!(*head))
		return (*head);
	
	if(remove_data == (*head)->data) {
	    temp = (*head)->link;
		free(*head);
		return temp;
	}
	/* if data is not matched then assigning return value to (*head)->link will preserve the linked list as is.*/
	(*head)->link = remove_node_recursive(remove_data, &((*head)->link));
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

/* FUNCTION: reverse_list_group
 * Reverse the linked list as groups.
 * Example: 
 * If INPUT list is - 1 2 3 4 5 6 7 8 and group_count is 3 then
 * OUTPUT Will be   - 3 2 1 6 5 4 8 7
 */
node* reverse_list_group(int group_count, node** head)
{
	node* previous = NULL;
	node* current = (*head);
	node* next = NULL;
	int count = 0;
	
	if (group_count <= 0)
		return (*head);
	
	while(current && count < group_count){
		next = current->link;
		current->link = previous;
		previous = current;
		current = next;
		count++;
	}
	if (next) {
		(*head)->link = reverse_list_group(group_count, &next);
	}
	
	(*head) = previous; /* Not really required but just to make sure head pointer is proper -
	                     - even if caller function does not catch up and assigns the return pointer to head. */
	return previous;
}
