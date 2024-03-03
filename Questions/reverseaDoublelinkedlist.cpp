/*
Psedo_code
Procedure reverseDoublyLinkedList(head):
    // Initialize pointers
    prev = nullptr
    current = head
    next = nullptr

    // Traverse the list and reverse pointers
    while current is not null:
        next = current.next
        current.next = prev
        current.prev = next  // Update prev pointer for the original last node
        prev = current
        current = next

    // Update head to the new head (original tail)
    head = prev

    return head
*/
//fullcode
#include <iostream>

using namespace std;

// Node structure for doubly-linked list
struct Node {
    int data;
    Node* prev;
    Node* next;

    Node(int val) : data(val), prev(nullptr), next(nullptr) {}
};

// Function to reverse a doubly-linked list
Node* reverseDoublyLinkedList(Node* head) {
    // Initialize pointers
    Node* prev = nullptr;
    Node* current = head;
    Node* next = nullptr;

    // Traverse the list and reverse pointers
    while (current != nullptr) {
        next = current->next;
        current->next = prev;
        current->prev = next;  // Update prev pointer for the original last node
        prev = current;
        current = next;
    }

    // Update head to the new head (original tail)
    head = prev;

    return head;
}

// Function to print the doubly-linked list
void printDoublyLinkedList(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Create a sample doubly-linked list
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->prev = head;
    head->next->next = new Node(3);
    head->next->next->prev = head->next;

    cout << "Original doubly-linked list: ";
    printDoublyLinkedList(head);

    // Reverse the doubly-linked list
    head = reverseDoublyLinkedList(head);

    cout << "Reversed doubly-linked list: ";
    printDoublyLinkedList(head);

    return 0;
}
