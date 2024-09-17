 // qsort.cpp

#include "volsort.h"

#include <cstdlib>
#include <array>
#include <iostream>

// Comparison function for numeric sorting with qsort - suggestion from class notes
int qsort_number_compare(const void *a, const void *b) {
    Node *nodeA = *(Node **)a;
    Node *nodeB = *(Node **)b;
    return nodeA->number - nodeB->number;
}

// Comparison function for string sorting - suggestion from class notes
int qsort_string_compare(const void *a, const void *b) {
    Node *nodeA = *(Node **)a;
    Node *nodeB = *(Node **)b;
    return nodeA->string.compare(nodeB->string);
}

/* Very similar to stl_sort function, adapted for qsort
 * Note: most of this code is copied directly from stl_sort */
void qsort_sort(List &l, bool numeric) {
    // Create an array to store pointers to the nodes
    Node** nodes = new Node*[l.size];
    
    // Fill the array with pointers to each node in the list
    Node* current = l.head;
    size_t index = 0;
    while (current != nullptr) {
        nodes[index++] = current;
        current = current->next;
    }
    
    // Sort the array using std::sort and the appropriate comparison function
    if (numeric) {
        std::qsort(nodes, l.size, sizeof(Node*), qsort_number_compare);
    } 
    else {
        std::qsort(nodes, l.size, sizeof(Node*), qsort_string_compare);
    }
    
    // Reconstruct the linked list by updating the next pointers
    for (size_t i = 0; i < l.size - 1; i++) {
        nodes[i]->next = nodes[i + 1];
    }
    nodes[l.size - 1]->next = nullptr; // Last node should point to nullptr
    
    // Update the head of the list
    l.head = nodes[0];
    
    // Clean up the allocated array
    delete[] nodes;
}
