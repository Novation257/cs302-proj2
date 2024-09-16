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
    size_t index = 0;
    while (current != nullptr) {
        nodes[index++] = current;
        current = current->next;
    }
    
    // Sort the array using std::sort and the appropriate comparison function
    if (numeric) {
        std::sort(nodes, nodes + l.size, node_number_compare);
    } 
    else {
        std::sort(nodes, nodes + l.size, node_string_compare);
    }
    
    // Reconstruct the linked list by updating the next pointers
    for (size_t i = 0; i < l.size - 1; ++i) {
        nodes[i]->next = nodes[i + 1];
    }
    nodes[l.size - 1]->next = nullptr; // Last node should point to nullptr
    
    // Update the head of the list
    l.head = nodes[0];
    
    // Clean up the allocated array
    delete[] nodes;
}
