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
	//std::cout << "checkpoint: " << std::endl;
	tmp = qsort(l.head, numeric);
	l.head = tmp;
}



Node *qsort(Node *head, bool numeric) {

	Node *ptr = head;
	Node *pivot;
	pivot = ptr; //pivot

	Node *left;
	Node *right; 

	left = ptr->next; //The left pointer is the "next" Node in the list

	//right is the last node in the list
	for (ptr = head; ptr != NULL; ptr = ptr->next) {
		if ((ptr->next) == NULL) {
			right = ptr;
			break;
		}
	}

	partition(head, pivot, *&left, *&right, numeric); //split list into right and left lists

	right = qsort(pivot->next, numeric); //return of right side
	left = qsort(head, numeric); //return of left side


	head = concatenate(left, right); //concatenate right and left nodes
	return head; //ultimately return head of list
}



void partition(Node *head, Node *pivot, Node *&left, Node *&right, bool numeric) {

	bool tORf;

	while (true) {

		//break if left's index equal to the right's, 
		
		if (left == right) {
			head = pivot->next;
			pivot->next = left->next;
			left->next = pivot;
			break;
		}

		if (left >= right) {
			head = pivot->next;
			right->next = pivot;
			pivot->next = right;
			break;
		}

		//Finds a number for the left that is >= than pivot
		while (true) {

			if (numeric == true) {
				tORf = node_number_compare(left, pivot);
			}

			else {
				tORf = node_string_compare(left, pivot);
			}

			if (tORf == true) {
				break;
			}

			// increment the left pointer if left not >= to pivot
			else {
				if (left->next != NULL) {
					left = left->next;
				}
			}
		}


		//Finds a number for the right that is <= than pivot

		while (true) {


			if (numeric == true) {
				tORf = node_number_compare(pivot, right);
			}

			else {
				tORf = node_string_compare(pivot, right);
			}

			if (tORf == true) {
				break;
			}

			else {

				//code to decrement pointer if right is not <= to pivot
				for (Node *ptr = head; ptr != NULL; ptr = ptr->next) {			
					if (ptr->next == right) {
						right = ptr;
						break;
					}
				}
			}
		}



		//Now swap two numbers
		Node *tmp = new Node;

		tmp->number = left->number; //save left's data into temporary node
		tmp->string = left->string;

		left->number = right->number; //transfer right's data into left
		left->string = right->string;

		right->number = tmp->number; //transfer left's data in temporary node into right 
		right->string = tmp->string;
	}

	return;

}



Node *concatenate(Node *left, Node *right) {

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

