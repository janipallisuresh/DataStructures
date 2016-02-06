#include "doublelinkedlist.h"

/**
* @brief Testing the functionality of Double linked list.
*/
int main(int argc, char* argv[])
{
    d_node* head = NULL;
    int i=0;


    for (i=0; i<10; i++) {
        add_node_front(i, &head);
        add_node_at(i, i, &head);
        add_node_end(i+10, &head);
    }
    display_reverse_list(head);
    display_list(head);
    reverse_list(&head);
    display_list(head);
    reverse_list_recursive(&head);
    display_list(head);
    
    printf("###########################\n");
    for (i=9; i>=0; i-- ) {
        head = remove_node_recursive(i, &head);
        remove_node_at(i, &head);
        remove_node(i-9, &head);
    }
    display_list(head);
    display_reverse_list(head);
    delete_list(&head);
    return 0;

}
