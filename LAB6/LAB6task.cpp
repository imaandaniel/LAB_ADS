#include <iostream>

using namespace std;

struct Node {
    int value;
    Node* left = NULL;
    Node* right = NULL;
};

Node* root = NULL;

void insert(int val) {
    Node* newNode = new Node();
    newNode->value = val;

    if (root == NULL) {
        root = newNode;
        return;
    }

    Node* temp = root;
    while (true) {
        if (val < temp->value) {
            if (temp->left == NULL) {
                temp->left = newNode;
                break;
            }
            temp = temp->left;
        } else {
            if (temp->right == NULL) {
                temp->right = newNode;
                break;
            }
            temp = temp->right;
        }
    }
}

bool search(int target) {
    Node* temp = root;
    cout << "\nStarting search for: " << target << endl;

    while (temp != NULL) {
        cout << "  Comparing with Node (" << temp->value << ")... ";

        if (target == temp->value) {
            cout << target << " == " << temp->value << ". Match found!" << endl;
            return true;
        }
        else if (target < temp->value) {
            cout << target << " < " << temp->value << ". Going LEFT." << endl;
            temp = temp->left;
        }
        else {
            cout << target << " > " << temp->value << ". Going RIGHT." << endl;
            temp = temp->right;
        }
    }

    cout << "  Hit a dead end (NULL). The number is not in the tree." << endl;
    return false;
}

void displayDetailed(Node* node) {
    if (node == NULL) return;

    if (node->left == NULL && node->right == NULL) {
        cout << node->value;
        return;
    }

    cout << "(";
    if (node->left != NULL) {
        displayDetailed(node->left);
        cout << " <- ";
    }

    cout << node->value;

    if (node->right != NULL) {
        cout << " -> ";
        displayDetailed(node->right);
    }
    cout << ")";
}

void display() {
    if (root == NULL) {
        cout << "Tree is empty." << endl;
        return;
    }
    displayDetailed(root);
    cout << endl;
}

int main() {
    insert(4);
    insert(2);
    insert(1);
    insert(3);
    insert(6);
    insert(5);
    insert(7);

    cout << "Detailed Tree Structure:" << endl;
    display();

    int target;
    cout << "\nEnter a number to search for: ";
    cin >> target;

    if (search(target)) {
        cout << "\nResult: Found it! " << target << " is in the tree." << endl;
    } else {
        cout << "\nResult: Sorry, " << target << " is missing from the tree." << endl;
    }

    return 0;
}