// stl.cpp

#include "volsort.h"

#include <algorithm>
#include <iostream>
#include <array>

void stl_sort(List &l, bool numeric) {
    // Create an array to store pointers to the nodes
    Node** nodes = new Node*[l.size];
    
    // Fill the array with pointers to each node in the list
    Node* current = l.head;
    Node* end;
    size_t index = 0;
    while (current != NULL) {
        nodes[index++] = current;
        if(current->next == NULL) end = current; // Mark end of linked list
        current = current->next;
    }

    // Sort the array using std::sort and the appropriate comparison function
    if (numeric) {
        std::sort(nodes, &end, node_number_compare);
    } 
    else {
        std::sort(nodes, &end, node_string_compare);
    }
    
    std::cout << "Checkpoint" << std::endl; // For debugging

    // Reconstruct the linked list by updating the next pointers
    for (size_t i = 0; i < l.size - 2; ++i) {
        nodes[i]->next = nodes[i + 1];
    }
    nodes[l.size - 1]->next = NULL; // Last node should point to NULL
    
    // Update the head of the list
    l.head = nodes[0];
    
    // Clean up the allocated array
    delete[] nodes;
}
