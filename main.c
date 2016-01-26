#include "singlelinkedlist.h"

int main()
{
	int i=10;
	node* head = NULL;
		remove_node(4, &head);
		reverse_list(&head);
		head = remove_node_recursive(1, &head);
		reverse_list_recursive(&head);
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
	remove_node(2, &head);
	display_list(head);
	return 0;
}
