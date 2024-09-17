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
        nodes[index] = current;
		index++;
        current = current->next;
    }
	
	//	std::cout<< "checkpoint" << std::endl;

    // Sort the array using std::sort and the appropriate comparison function
	
	//std::cout << l.size << std::endl;

	
    if (numeric) {
        std::sort(nodes, nodes + l.size, node_number_compare_lt);
    } 
    else {
        std::sort(nodes, nodes + l.size, node_string_compare_lt);
    }
	/*while (true) {
	std::cout << nodes[4]->string;
	}*/

    // Reconstruct the linked list by updating the next pointers
    for (size_t i = 0; i < l.size - 1; i++) {
        nodes[i]->next = nodes[i+1];
    }
    nodes[l.size - 1]->next = NULL; // Last node should point to NULL
    
    // Update the head of the list
    l.head = nodes[0];
    
    // Clean up the allocated array
    delete[] nodes;
}
