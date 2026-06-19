#include <iostream>
#include <string>

using namespace std;

struct Node {
    string name;
    Node* next = NULL;
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
    }
}

// delete
void deleteNode(string n) {
    if (head == NULL) return; // Nothing to delete

    // If the one we want to delete is the first node
    if (head->name == n) {
        Node* toDelete = head;
        head = head->next;
        delete toDelete;
        return;
    }


    Node* temp = head;
    while (temp->next != NULL && temp->next->name != n) {
        temp = temp->next;
    }


    if (temp->next != NULL) {
        Node* toDelete = temp->next;
        temp->next = temp->next->next;
        delete toDelete;
    }
}

// display
void display() {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->name << " -> ";
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