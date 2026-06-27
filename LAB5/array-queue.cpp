#include <iostream>
#include <string>

using namespace std;

class ArrayQueue {
private:
    static const int MAX = 100;
    string arr[MAX];
    int frontIndex = 0;
    int rearIndex = -1;
    int count = 0;

public:
    // PUSH
    void enqueue(string newName) {
        if (count >= MAX) {
            cout << "Queue Overflow! Cannot enqueue." << endl;
            return;
        }
        rearIndex++;
        arr[rearIndex] = newName;
        count++;
    }

    // POP
    void dequeue() {
        if (count == 0) {
            cout << "Queue Underflow! Nothing to dequeue." << endl;
            return;
        }
        frontIndex++;
        count--;
    }

    // PEEK
    int getFrontIndex() {
        return frontIndex;
    }

    string getElementAt(int index) {
        if (index >= frontIndex && index <= rearIndex) {
            return arr[index];
        }
        return "";
    }
};

int main() {
    ArrayQueue myQueue;

    myQueue.enqueue("Aimar");
    myQueue.enqueue("Ahmad");
    myQueue.enqueue("Anajana");
    myQueue.enqueue("Jessy");

    int current_index = myQueue.getFrontIndex();
    for(int i = 0; i < 4; i++){
        if (myQueue.getElementAt(current_index) != "") {
            cout << myQueue.getElementAt(current_index) << endl; 
            current_index++; 
        }
    }
    
    return 0;
}