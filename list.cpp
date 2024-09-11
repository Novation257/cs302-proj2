#include "volsort.h"

// Constructor - Copied from Lab4 list.cpp from CS202
List::List() {
    head = NULL;
}

// Deconstructor - Copied from Lab4 list.cpp from CS202
List::~List() {
    if (head == NULL) {     // If the LL is not already empty...
        Node *p= head;          // Retrieve first node
        while (p != NULL) {     // While there are still nodes in the chain...
            Node *next = p->next;   // Retrieve next linked node
            delete p;               // Delete current node
            p = next;               // Navigate to next node
        }
    }
}

// Compares the int values stored in two nodes - returns true if a > b
bool node_number_compare(const Node *a, const Node *b) {
    return(a->number > b->number);
}

// Compares the strings stored in two nodes - returns true if a > b
bool node_string_compare(const Node *a, const Node *b) {
    return(a->string > b->string);
}
