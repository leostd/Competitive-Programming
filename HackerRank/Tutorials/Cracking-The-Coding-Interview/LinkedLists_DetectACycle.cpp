/*
Detect a cycle in a linked list. Note that the head pointer may be 'NULL' if the list is empty.

A Node is defined as: 
    struct Node {
        int data;
        struct Node* next;
    }
*/

bool has_cycle(Node* head) {
    // Complete this function
    // Do not write the main method
    Node *a = head;
    Node *b = head;
    while(b != NULL && b->next != NULL)
    {
        a = a->next;
        b = b->next->next;
        if (a == b)
            return true;
    }
    return false;
}
