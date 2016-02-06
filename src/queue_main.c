#include "queue.h"

/**
* @brief Testing the functionality of Queue
*/
int main(int argc, char* argv[]) 
{
	my_queue* Q1 = NULL;
	my_queue* Q2 = NULL;
	int i = 0;
	pop_node(&Q1);
	
	for(i=1; i<=10; i++) {
		push_node(i, &Q1);
		push_node(i+10, &Q2);
	}
	printf("QUEUE 1:\n"); display_queue(Q1);
	printf("QUEUE 2:\n"); display_queue(Q2);
	
	for(i=1; i<=10; i++) {
		pop_node(&Q1);
	}
	
	delete_queue(&Q2);
	
	printf("QUEUE 1:\n"); display_queue(Q1);
	printf("QUEUE 2:\n"); display_queue(Q2);
		
	for(i=10; i<=20; i++) {
		push_node(i, &Q1);
		push_node(i+10, &Q2);
	}
	printf("QUEUE 1:\n"); display_queue(Q1);
	printf("QUEUE 2:\n"); display_queue(Q2);
	delete_queue(&Q1);
	delete_queue(&Q2);
	return 0;
}
