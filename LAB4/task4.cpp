#include <iostream>
#include <string>

using namespace std;

struct Node {
    string name;
    Node* next = NULL;
    Node* prev = NULL; // NEW: Pointer to the previous node
};

Node* head = NULL;

// insert
void insert(string n) {
    Node* newNode = new Node();
    newNode->name = n;

    if (head == NULL) {
        head = newNode; // First node becomes the head
    } else {
        Node* temp = head;
        while (temp->next != NULL) { // Walk to the very end
            temp = temp->next;
        }

        temp->next = newNode; // Attach the new node at the end
        newNode->prev = temp; // NEW: Point the new node's 'prev' back to the current end
    }
}

// delete
void deleteNode(string n) {
    if (head == NULL) return; // Nothing to delete

    // Case 1: If the one we want to delete is the first node
    if (head->name == n) {
        Node* toDelete = head;
        head = head->next; // Move head to the second node

        if (head != NULL) {
            head->prev = NULL; // NEW: The new head has no previous node
        }

        delete toDelete;
        return;
    }

    // Walk through the list to find the EXACT node we want to delete
    Node* temp = head;
    while (temp != NULL && temp->name != n) {
        temp = temp->next;
    }

    // If we found it (temp is not NULL)
    if (temp != NULL) {
        // NEW: Repair the forward link of the previous node
        if (temp->prev != NULL) {
            temp->prev->next = temp->next;
        }

        // NEW: Repair the backward link of the next node
        if (temp->next != NULL) {
            temp->next->prev = temp->prev;
        }

        delete temp; // Free the memory
    }
}

// display
void display() {
    Node* temp = head;
    while (temp != NULL) {
        // Changed the arrow to <-> to represent the two-way links!
        cout << temp->name << " <-> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main() {
    insert("Aimar");
    insert("Ahmad");
    insert("Anajana");
    insert("Jessy");

    cout << "After inserting:" << endl;
    display();

    deleteNode("Ahmad");

    cout << "\nAfter deleting Ahmad:" << endl;
    display();

    return 0;
}