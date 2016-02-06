/**
 * @file stack.h
 * @author janipallisuresh
 * @date 06 Feb 2016
 * @brief Implementing Stack Data structure using Single linked list.
 * Contains declarations of functions supported in operating Queue DS.
 * @see http://
 */
 
#ifndef STACK_HEADER
#define STACK_HEADER

#include "singlelinkedlist.h"

/** 
* @brief stack DS with Top pointer.
* top: pointer to the top node in the stack
*/
typedef struct my_stack {
	s_node* top;
}my_stack;

void push_node(int data, my_stack** myst);
void pop_node(my_stack** myst);
void delete_stack(my_stack** myst);
void display_stack(my_stack* myst);

#endif
