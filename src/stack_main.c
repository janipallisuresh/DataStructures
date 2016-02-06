#include "stack.h"

/**
* @brief Testing the functionality of Stack DS
*/
int main(int argc, char* argv[])
{
	my_stack* S1 = NULL;
	my_stack* S2 = NULL;
	int i = 0;
	
	pop_node(&S1);
	
	for(i=1; i<=10; i++) {
		push_node(i, &S1);
		push_node(i+10, &S2);
	}
	printf("STACK 1:\n"); display_stack(S1);
	printf("STACK 2:\n"); display_stack(S2);
	
	for(i=1; i<=5; i++) {
     	pop_node(&S1);
     	pop_node(&S2);
	}
	
	printf("STACK 1:\n"); display_stack(S1);
	printf("STACK 2:\n"); display_stack(S2);
	
	delete_stack(&S2);
	
	for(i=1; i<=10; i++) {
     	pop_node(&S1);
	}
	
	printf("STACK 1:\n"); display_stack(S1);
	printf("STACK 2:\n"); display_stack(S2);
		
	for(i=10; i<=20; i++) {
		push_node(i, &S1);
		push_node(i+10, &S2);
	}
	printf("STACK 1:\n"); display_stack(S1);
	printf("STACK 2:\n"); display_stack(S2);
	delete_stack(&S1);
	delete_stack(&S2);
	return 0;
}
