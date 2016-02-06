/**
 * @file doublelinkedlist.c
 * @author janipallisuresh
 * @date 05 Feb 2016
 * @brief Contains implementation of the functions declared in doublelinkedlist.h.
 * @see http://
 */
 
#include "doublelinkedlist.h"

/**
* @function add_node_front
* @brief Adds a node at starting of the list
*/
void add_node_front(int data, d_node** head)
{
	d_node* newnode = (d_node*) malloc(sizeof(d_node));
	
	newnode->data = data;
	newnode->prev = NULL;
	newnode->next = (*head);
	if(*head) {
	(*head)->prev = newnode;
	}

	(*head) = newnode;
}

/**
* @function add_node_end
* @brief Adds a node at the end of the list.
*/
void add_node_end(int data, d_node** head)
{
	d_node* newnode = (d_node*) malloc(sizeof(d_node));
	d_node* move = (*head);
	
	newnode->data = data;
	newnode->prev = newnode->next = NULL;
	
	if(!(*head)) {
		(*head) = newnode;
		return;
	}
	
	while(move->next) {
		move = move->next;
	}
	
	move->next = newnode;
	newnode->prev = move;
}

/**
* @function add_node_at
* @brief Add the node at given location. location starts from '0'
* if at_loc is <= 0 then adds at the begining of the list.
* if at_loc is more than the size of the list then adds at the end.
*/
void add_node_at(int data, int at_loc, d_node** head)
{
	d_node* newnode;
	d_node* move = (*head);
	int loc = at_loc;
		
	newnode = (d_node*) malloc(sizeof(d_node));
	newnode->data = data;
	newnode->prev = newnode->next = NULL;
	
	if(!(*head)) {
		(*head) = newnode;
		return;
	}
	
	while(loc > 0) {
		if(move->next) {
			move = move->next;
			loc--;
		}
		else {
			break;
		}
	}

	if(loc > 0) {
        /* add at the end */
		move->next = newnode;
		newnode->prev = move;
		return;
	}

	/* insertion before 'move' node */
	newnode->prev = move->prev;
	if(move->prev) {
		move->prev->next = newnode;
	}
	move->prev = newnode;
	newnode->next = move;
	
	if(at_loc <= 0) {
		(*head) = newnode;
	}
}

/**
* @function delete_list
* @brief Delete the entire list starting from Head node.
*/
void delete_list(d_node** head)
{
	d_node* move = (*head);

	while(move) {
		move = (*head)->next;
		free((*head));
		(*head) = move;
	}
	(*head) = NULL;
	printf("LIST IS DELETED\n");
}

/**
* @function display_list
* @brief Print the list starting from Head node.
*/
void display_list(d_node* head)
{
	d_node* move = head;
	printf("The list is...\n");
	while(move) {
		printf("[%d]==", move->data);
		move = move->next;
	}
	printf("\\\n");
}

/**
* @function display_reverse_list
* @brief Prints the list in reverse order.
*/
void display_reverse_list(d_node* head)
{
	d_node* move = head;
	if(!move) {
		return;
	}
	
	while(move->next) {
		move = move->next;
	}
	printf("Printing the list in reverse order...\n");
	while(move) {
		printf("[%d]==", move->data);
		move = move->prev;
	}
	printf("\\\n");
}

/**
* @function remove_node
* @brief Removes the node based on the given 'data'
* It only deletes the first occurence of the node which matches with the given 'data'.
* Does not delete all the duplicates. 
*/
void remove_node(int data, d_node** head)
{
	d_node* move = (*head);
	if(!(*head)) {
		return;
	}
	/* Case 1:  If Head is the node to be removed. */
	if (move->data == data) {
		if(move->next) {	
			move->next->prev = NULL;
		}
		(*head) = move->next;
		free(move);
		return;
	}
	/* Case 2: Other than Head Node */
	while(move) {
		if(move->data == data) {
				(move->prev->next = move->next);
 				if (move->next) {
				move->next->prev = move->prev;
			}
			free(move);
			break;
		}
		
		move = move->next;
	}
	
}

/** 
* @function remove_node_front
* @brief Removes the first node
*/
void remove_node_front(d_node** head)
{
	if(!(*head))
		return;
	remove_node((*head)->data, head);
}

/**
* @function remove_node_end
* @brief Removes the last node
*/
void remove_node_end(d_node** head)
{
	d_node* move = (*head);
	
	if(!move) {
		return;
	}
	
	while(move->next) {
		move = move->next;
	}
	
	if(move->prev) {
		move->prev->next = NULL;
		free(move);
	} else {
		/* if it is head node */
		free(move);
		(*head) = NULL;
	}
}

/**
* @function remove_node_at
* @brief Removes the node at given location - 'at_loc'.
* if at_loc <=0 then removes the head node.
* If at_loc > than the size of the list then it returns withour deleting any node.
*/
void remove_node_at(int at_loc, d_node** head)
{
	d_node* move = (*head);
	int loc = at_loc;
	
	if(loc <=0 ){
		/* node to be removed is Head */
		remove_node_front(head);
		return;
	}
	
	while(loc > 0) {
		if(move->next) {
			move = move->next;
			loc--;
		}
		else {
			if(loc > 0)
				printf("End of list - Location not found\n");
			return;
		}
	}
	/* We can call - remove_node(move->data, head); but it again traverse the whole list to find the node with move->data */
	/* Now we know that node to be deleted is not the Head. So...*/
	move->prev->next = move->next;
	if(move->next) {
		move->next->prev = move->prev;
	}
	free(move);
}

/**
* @function remove_node_recursive
* @brief Recursive way of removing the node with given data.
*/
d_node* remove_node_recursive(int data, d_node** head)
{
	d_node* temp = NULL;
	if(!(*head)) {
		return NULL;
	}
	if((*head)->data == data) {
		if((*head)->next) {
			temp = (*head)->next;
			(*head)->next->prev = (*head)->prev;
		}

		free((*head));
		return temp;
	}
	
	(*head)->next =  remove_node_recursive(data, &((*head)->next));
	return (*head);
}

/**
* @function reverse_list
* @brief Reversing the double linked list
*/
void reverse_list(d_node** head)
{
	d_node* current = (*head);
	d_node* previous = NULL;
	d_node* move = NULL;
	
	while(current) {
		move = current->next;
		current->next = previous;
		current->prev = move;
		previous = current;
		current = move;
	}
	(*head) = previous;
}

/**
* @function reverse_list_recursive
* @brief Recursive way of reversing a double linked list
*/
void reverse_list_recursive(d_node** head)
{
	d_node* move;
	d_node* current, *temp;
	
	if(!(*head)) {
		return;
	}
	current = (*head);
	move = (*head)->next;
	
	if(!move) {
		current->prev = NULL;
		return;
	}
	temp = move;
    reverse_list_recursive(&move);
	current->next->next = current;
	current->next = current->prev;
	current->prev = temp;
	(*head) = move;
}
