#include <iostream>
#include <string>

using namespace std;


class Node {
public:
    string name;
    Node* next = nullptr;
};


class Stack {
private:
    Node* top = nullptr;
public:
    // PUSH
    void push(string newName) {
        Node* newNode = new Node();
        newNode->name = newName;
        newNode->next = top;
        top = newNode;
    }

    // POP
    void pop() {
        if (top == nullptr) return;
        Node* temp = top;
        top = top->next;
        delete temp;
    }

    // PEEK
    Node* peek() {
        return top;
    }
};

int main() {
    Stack myStack;


    myStack.push("Jessy");
    myStack.push("Anajana");
    myStack.push("Ahmad");
    myStack.push("Aimar");


    Node* display_node = myStack.peek();
    for(int i = 0; i < 4; i++){
        if (display_node != nullptr) {
            cout << display_node->name << endl;
            display_node = display_node->next;
        }
    }

    return 0;
}