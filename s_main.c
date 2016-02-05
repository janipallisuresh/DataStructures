/* Testing Single Linked List Code */
#include "singlelinkedlist.h"

/**
* @brief Testing the functionality of Single linked list.
*/
int main()
{
	int i=10;
	node* head = NULL;
	node* temp = NULL;
	node* temp1 = NULL;
	int count = 1;
	
	remove_node(4, &head);
	head = remove_node_recursive(1, &head);
	display_list(head);
	reverse_list(&head);
	reverse_list_recursive(&head);
	reverse_list_group(3, &head);
	find_remove_loop(&head);

	for(i=10; i>0; i--) {
		add_node(i, &head);
	}
	display_list(head);
	remove_node(4, &head);
	display_list(head);
	reverse_list_recursive(&head);
	head = remove_node_recursive(1, &head);
	display_list(head);
	head = remove_node_recursive(10, &head);
	reverse_list(&head);
	display_list(head);
	reverse_list_group(3, &head);
	display_list(head);
	
	/* make a loop to test the function */
	temp = head;
	while(temp->next != NULL) 
	{
	    if(count == 4)
	     temp1 = temp;
	    temp = temp->next;
	    count++;
	}
	temp->next = temp1;

	printf("Loop at Node: %d\n", find_remove_loop(&head));
	display_list(head);
	printf("Loop at Node: %d\n", find_remove_loop(&head));
	return 0;
}
