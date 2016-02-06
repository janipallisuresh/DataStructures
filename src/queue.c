/**
 * @file queue.c
 * @author janipallisuresh
 * @date 05 Feb 2016
 * @brief Queue Data structure implementation using double linked list.
 * Contains implementation of the functions declared in queue.h.
 * @see http://
 */
 
#include "queue.h"

/**
* @function push_node
* @brief Push one element into the given Queue.
*/
void push_node(int data, my_queue** myq)
{
	if(!(*myq)) {
		(*myq) = (my_queue*) malloc(sizeof(my_queue));
		(*myq)->front = (*myq)->rear = NULL;
	}

	add_node_end(data, &((*myq)->rear));
	if ( (*myq)->rear->prev == NULL && (*myq)->rear->next == NULL ) {
		/* It is the first node */
		(*myq)->front = (*myq)->rear;
	}
	else {
		(*myq)->rear = (*myq)->rear->next;
	}
}

/**
* @function pop_node
* @brief delete one element from the given Queue.
*/
void pop_node(my_queue** myq)
{
	
	if(!(*myq))
		return;
	remove_node_front(&((*myq)->front));
	if(!((*myq)->front)) {
		/* Queue is empty */
		(*myq)->rear = NULL;
	}
}

/**
* @function delete_queue
* @brief Delete entire queue
*/
void delete_queue(my_queue** myq)
{
    delete_list(&((*myq)->front));
    (*myq)->rear = NULL;
    free((*myq));
    (*myq) = NULL;
}

/**
* @function display_queue
* @brief display all elementes in the Queue.
*/
void display_queue(my_queue* myq)
{
	if(!myq) {
		printf("Queue is empty...\n");
		return;
	}
	display_list(myq->front);
}
