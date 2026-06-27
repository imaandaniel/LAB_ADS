#include <iostream>
#include <string>

using namespace std;


class Node {
public:
    string name;
    Node* next = nullptr;
};


class Queue {
private:
    Node* front = nullptr;
    Node* rear = nullptr;

public:

    void enqueue(string newName) {
        Node* newNode = new Node();
        newNode->name = newName;


        if (rear == nullptr) {
            front = rear = newNode;
            return;
        }


        rear->next = newNode;
        rear = newNode;
    }


    void dequeue() {
        if (front == nullptr) return;

        Node* temp = front;
        front = front->next;


        if (front == nullptr) {
            rear = nullptr;
        }

        delete temp;
    }


    Node* getFront() {
        return front;
    }
};

int main() {
    Queue myQueue;


    myQueue.enqueue("Aimar");
    myQueue.enqueue("Ahmad");
    myQueue.enqueue("Anajana");
    myQueue.enqueue("Jessy");


    Node* display_node = myQueue.getFront();
    for(int i = 0; i < 4; i++){
        if (display_node != nullptr) {
            cout << display_node->name << endl; 
            display_node = display_node->next; 
        }
    }
    
    return 0;
}