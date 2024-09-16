// volsort.h

#ifndef VOLSORT_H
#define VOLSORT_H

#include <string>
#include <iostream>

struct Node {
    std::string string;
    int         number;
    Node       *next;
};

struct List {
    Node       *head;
    size_t      size;

    List(); 					// define in list.cpp - COMPLETED
    ~List();					// define in list.cpp - COMPLETED

    void push_front(const std::string &s) { 	//define below - COMPLETED
      // Allocate a new node, copying supplied data into it.
      Node *nn = new Node;
      nn->string = s;
      nn->number = stoi(s);

      nn->next = head; // Set new node's pointer to the current head (will be null if LL is empty)
      head = nn;       // Set the LL's head node to the new node (push front)
    }
};


// Functions -------------------------------------------------------------------

bool node_number_compare(const Node *a, const Node *b); 	//implement in list.cpp to avoid compile-time issues, used by quick, merge and stl - COMPLETED
bool node_string_compare(const Node *a, const Node *b);		//implement in list.cpp to avoid compile-time issues, merge and stl - COMPLETED

// void dump_node(Node *n) { // implement in this file (volsort.h) to make it easier for TAs to grade
//     for (Node *head = n; head->next != NULL; n = n->next) {
//         std::cout << n->number << " ";
//     }
//     std::cout << std::endl;
// }

void stl_sort(List &l, bool numeric);	// define in stl.cpp - sort using std::sort
void qsort_sort(List &l, bool numeric);	// define in qsort.cpp - sort using qsort from cstdlib
void merge_sort(List &l, bool numeric);	// define in merge.cpp - your implementation
void quick_sort(List &l, bool numeric);	// define in quick.cpp - your implementation

#endif
