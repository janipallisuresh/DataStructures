/**
 * @file stack.c
 * @author janipallisuresh
 * @date 05 Feb 2016
 * @brief Stack Data structure implementation using single linked list.
 * Contains implementation of the functions declared in stack.h.
 * @see http://
 */
  #include "stack.h"
 
 
/**
* @function push_node
* @brief Push one element into the given Stack.
*/ 
  void push_node(int data, my_stack** myst)
  {
  	if(!(*myst)) {
  		(*myst) = (my_stack*) malloc(sizeof(my_stack));
  		(*myst)->top = NULL;
	}
  	add_node_front(data, (&(*myst)->top));
  }
  
/**
* @function pop_node
* @brief delete top element from the given Stack
*/
  void pop_node(my_stack** myst)
  {
  	if(!(*myst)) {
  		return;
	  }
	remove_node((*myst)->top->data, &((*myst)->top));
  	if(!((*myst)->top)){
  		free((*myst));
  		(*myst) = NULL;
	}
  }
  
/**
* @function delete_stack
* @brief Delete entire Stack
*/
  void delete_stack(my_stack** myst)
  {
  	if(!(*myst)) {
  		return;
	}
  	delete_list(&((*myst)->top));
  	free((*myst));
  	(*myst) = NULL;
  }
  
/**
* @function display_stack
* @brief display all elementes in the Stack
*/
  void display_stack(my_stack* myst)
  {
  	if(!myst) {
  		printf("Stack is empty...\n")	;
  		return;
	}
	display_list(myst->top);
  }
