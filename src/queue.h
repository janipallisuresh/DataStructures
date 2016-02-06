/**
 * @file queue.h
 * @author janipallisuresh
 * @date 06 Feb 2016
 * @brief Implementing Queue Data structure using Double linked list.
 * Contains declarations of functions supported in operating Queue DS.
 * @see http://
 */
 
#ifndef QUEUE_HEADER
#define QUEUE_HEADER

#include "doublelinkedlist.h"

/** 
* @brief Queue DS with front and rear pointers.
* front: pointer to first node in the queue.
* rear:  pointer to last node in the queue.
*/
typedef struct my_queue {
	d_node* front;
	d_node* rear;
}my_queue;

void push_node(int data, my_queue** myq);
void pop_node(my_queue** myq);
void delete_queue(my_queue** myq);
void display_queue(my_queue* myq);


#endif
