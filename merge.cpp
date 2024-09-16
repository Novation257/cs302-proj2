// merge.cpp
#include "volsort.h"

Node *msort(Node *head, bool numeric);
void split(Node *head, Node *&left, Node *&right);
Node *merge(Node *left, Node *right, bool numeric);

void merge_sort(List &l, bool numeric) {
    l.head = msort(l.head, numeric);
}

Node *msort(Node *head, bool numeric) {
    if (!head || !head->next) return head;

    Node *left = nullptr;
    Node *right = nullptr;
    split(head, left, right);

    left = msort(left, numeric);
    right = msort(right, numeric);

    return merge(left, right, numeric);
}

void split(Node *head, Node *&left, Node *&right) {
    if (!head || !head->next) {
        left = head;
        right = nullptr;
    } else {
        Node *slow = head;
        Node *fast = head->next;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        left = head;
        right = slow->next;
        slow->next = nullptr;
    }
}

Node *merge(Node *left, Node *right, bool numeric) {
    Node *result = nullptr;

    if (!left) return right;
    if (!right) return left;

    if ((numeric && node_number_compare(left, right)) || (!numeric && node_string_compare(left, right))) {
        result = left;
        result->next = merge(left->next, right, numeric);
    } else {
        result = right;
        result->next = merge(left, right->next, numeric);
    }

    return result;
}
