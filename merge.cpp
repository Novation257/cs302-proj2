#include "volsort.h"

//Forward declarations of helper functions used in the merge sort process.
Node *msort(Node *head, bool numeric);
void split(Node *head, Node *&left, Node *&right);
Node *merge(Node *left, Node *right, bool numeric);

//Main function for merge sort. It starts the sorting process for a given list.
void merge_sort(List &l, bool numeric) {
    l.head = msort(l.head, numeric); //Calls the msort function to sort the list and assigns the sorted head back to the list.
}

//Recursive merge sort implementation. Takes in the head of the list and a boolean 'numeric' flag for comparing nodes.
Node *msort(Node *head, bool numeric) {
    //Base case: if the list is empty or has only one node, it's already sorted.
    if (!head || !head->next) return head;

    Node *left = nullptr;  // Initialize pointers for the left and right halves of the list.
    Node *right = nullptr;

    //Split the list into two halves.
    split(head, left, right);

    //Recursively sort both halves.
    left = msort(left, numeric);
    right = msort(right, numeric);

    //Merge the two sorted halves and return the result.
    return merge(left, right, numeric);
}

//Splits the list into two halves: 'left' and 'right'. This uses the "Tortoise and Hare" strategy.
void split(Node *head, Node *&left, Node *&right) {
    if (!head || !head->next) { //If the list has zero or one element, no split is necessary.
        left = head;             //The entire list becomes the left half.
        right = nullptr;         //The right half is empty.
    } else {
        Node *slow = head;       //Slow pointer moves one step at a time.
        Node *fast = head->next; //Fast pointer moves two steps at a time.

        //Move through the list until 'fast' reaches the end.
        //When 'fast' reaches the end, 'slow' will be at the middle of the list.
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        //'left' starts at the head of the list.
        left = head;

        //'right' starts at the node after 'slow' (i.e., the middle of the list).
        right = slow->next;

        //Disconnect the two halves by making 'slow' the last node of the left half.
        slow->next = nullptr;
    }
}

//Merges two sorted linked lists (left and right) into a single sorted list.
//The 'numeric' flag determines whether to compare based on numeric or string values.
Node *merge(Node *left, Node *right, bool numeric) {
    Node *result = nullptr; // Initialize the resulting merged list.

    //Base cases: if either list is empty, return the other.
    if (!left) return right;
    if (!right) return left;

    //Compare the nodes based on the 'numeric' flag.
    if ((numeric && node_number_compare(left, right)) || //If numeric, compare using numbers.
        (!numeric && node_string_compare(left, right))) { //If not numeric, compare using strings.
        result = left;                  //'left' node is smaller, so it becomes the next node in the merged list.
        result->next = merge(left->next, right, numeric); //Recursively merge the rest of the left and right lists.
    } else {
        result = right;                 //'right' node is smaller, so it becomes the next node in the merged list.
        result->next = merge(left, right->next, numeric); //Recursively merge the rest of the left and right lists.
    }

    return result; //Return the merged list.
}
