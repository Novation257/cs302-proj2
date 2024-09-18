// quick.cpp

#include "volsort.h"

#include <iostream>

// Prototypes

Node *qsort(Node *head, bool numeric);
void  partition(Node *head, Node *pivot, Node *&left, Node *&right, bool numeric);
Node *concatenate(Node *left, Node *right);

// Implementations

void quick_sort(List &l, bool numeric) {
	Node *tmp;
	tmp = qsort(l.head, numeric);
	l.head = tmp;
}



Node *qsort(Node *head, bool numeric) {
	if(head == NULL) return NULL;	// Base case

	Node *pivot = head; // Make pivot the first node in the LL(acts as single node)
	Node *left, *right; // Create left and right pointers(act as LLs)

	partition(head->next, pivot, *&left, *&right, numeric); //split list into right and left lists

	left = qsort(left, numeric); //sort left side 
	right = qsort(right, numeric); //sort right side
	
	// Concatenate left, pivot, and right
	pivot->next = right;
	head = concatenate(left, pivot);

	return head; //ultimately return head of list
}


// Splits the given linked list (head) into two sublists (left: <=pivot, right: >=pivot)
void partition(Node *head, Node *pivot, Node *&left, Node *&right, bool numeric) {
	Node *curr = head;

	while(curr != NULL) {
		std::cout << "started sort cycle" << std::endl;
		Node *nextNode = curr->next; // Store next node, as curr->next gets overwritten
		std::cout << "stored next" << std::endl;
		std::cout << pivot->number << " starting sort " << curr->number << std::endl;
		// If current is less than the pivot (according to selected comparison function), push_front to left sublist
		if(( (numeric && node_number_compare(curr, pivot)) || (!numeric && node_string_compare(curr,pivot)) )) { 
			curr->next = left;
			left = curr;
		} else { // Else, push_front to right sublist
			curr->next = right;
			right = curr;
		}
		std::cout << "ended sort" << std::endl;
		curr = nextNode; // Move to next node in LL
		std::cout << "ended sort cycle" << std::endl;
	}
	return;
}



Node *concatenate(Node *left, Node *right) {
	if(left == NULL) return right;

	//sets left's last element's next pointer equal to right's first element. Returns 
	//the head Node (left's first element)
	Node *ptr;
	for (ptr = left; ptr != NULL; ptr = ptr->next) {
		if (ptr->next == NULL) {
			ptr->next = right;
			break;
		}
	}
	return left;
}

