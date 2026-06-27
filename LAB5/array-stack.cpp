#include <iostream>
#include <string>

using namespace std;

class ArrayStack {
private:
    static const int MAX = 100; 
    string arr[MAX];            
    int topIndex = -1;          

public:
    // PUSH
    void push(string newName) {
        if (topIndex >= MAX - 1) {
            cout << "Stack Overflow! Cannot push." << endl;
            return;
        }
        topIndex++;               
        arr[topIndex] = newName;  
    }

    // POP
    void pop() {
        if (topIndex < 0) {
            cout << "Stack Underflow! Nothing to pop." << endl;
            return;
        }
        topIndex--; 
    }

    // PEEK
    int getTopIndex() {
        return topIndex;
    }

    string getElementAt(int index) {
        if (index >= 0 && index <= topIndex) {
            return arr[index];
        }
        return "";
    }
};

int main() {
    ArrayStack myStack;

    myStack.push("Jessy");
    myStack.push("Anajana");
    myStack.push("Ahmad");
    myStack.push("Aimar");

    int current_index = myStack.getTopIndex();
    for(int i = 0; i < 4; i++){
        if (current_index >= 0) {
            cout << myStack.getElementAt(current_index) << endl; 
            current_index--; 
        }
    }
    
    return 0;
}