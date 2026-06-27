#include <iostream>
#include <string>

using namespace std;

struct Node {
    string name;
    Node* next = NULL;
};

Node* head = NULL;

void insert(string n) {
    Node* newNode = new Node();
    newNode->name = n;

    if (head == NULL) {
        head = newNode;
        newNode->next = head;
    } else {
        Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
    }
}

void deleteNode(string n) {
    if (head == NULL) return;

    if (head->name == n) {
        Node* toDelete = head;

        if (head->next == head) {
            head = NULL;
        } else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            head = head->next;
            temp->next = head;
        }
        delete toDelete;
        return;
    }

    Node* current = head;
    Node* prev = NULL;
    do {
        prev = current;
        current = current->next;
    } while (current != head && current->name != n);

    if (current != head) {
        prev->next = current->next;
        delete current;
    }
}

void display() {
    if (head == NULL) {
        cout << "Empty List" << endl;
        return;
    }
    Node* temp = head;
    do {
        cout << temp->name << " -> ";
        temp = temp->next;
    } while (temp != head);
    cout << head->name << endl;
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