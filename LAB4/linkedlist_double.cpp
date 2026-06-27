#include <iostream>
#include <string>

using namespace std;

struct Node {
    string name;
    Node* next = NULL;
    Node* prev = NULL;
};

Node* head = NULL;


void insert(string n) {
    Node* newNode = new Node();
    newNode->name = n;

    if (head == NULL) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = newNode;
        newNode->prev = temp;
    }
}


void deleteNode(string n) {
    if (head == NULL) return;


    if (head->name == n) {
        Node* toDelete = head;
        head = head->next;

        if (head != NULL) {
            head->prev = NULL;
        }

        delete toDelete;
        return;
    }


    Node* temp = head;
    while (temp != NULL && temp->name != n) {
        temp = temp->next;
    }


    if (temp != NULL) {

        if (temp->prev != NULL) {
            temp->prev->next = temp->next;
        }


        if (temp->next != NULL) {
            temp->next->prev = temp->prev;
        }

        delete temp;
    }
}


void display() {
    Node* temp = head;
    while (temp != NULL) {

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