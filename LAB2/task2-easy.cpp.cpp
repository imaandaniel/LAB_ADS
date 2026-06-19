#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

// Function to rotate the matrix layer by layer
void rotateMatrix(vector<vector<int>>& mat) {
    if (mat.empty() || mat[0].empty()) {
        return;
    }

    int top = 0;
    int bottom = mat.size() - 1;
    int left = 0;
    int right = mat[0].size() - 1;

    // Process the matrix ring by ring
    while (top < bottom && left < right) {

        // Store the first element of the next row.
        // This will replace the first element of the current top row.
        int prev = mat[top + 1][left];

        // 1. Move elements of the top row from left to right
        for (int i = left; i <= right; ++i) {
            int curr = mat[top][i];
            mat[top][i] = prev;
            prev = curr;
        }
        top++;

        // 2. Move elements of the rightmost column from top to bottom
        for (int i = top; i <= bottom; ++i) {
            int curr = mat[i][right];
            mat[i][right] = prev;
            prev = curr;
        }
        right--;

        // 3. Move elements of the bottom row from right to left
        for (int i = right; i >= left; --i) {
            int curr = mat[bottom][i];
            mat[bottom][i] = prev;
            prev = curr;
        }
        bottom--;

        // 4. Move elements of the leftmost column from bottom to top
        for (int i = bottom; i >= top; --i) {
            int curr = mat[i][left];
            mat[i][left] = prev;
            prev = curr;
        }
        left++;
    }
}

// Utility function to print the matrix nicely
void printMatrix(const vector<vector<int>>& mat) {
    for (const auto& row : mat) {
        for (int val : row) {
            // Using setw(4) and left alignment for clean spacing
            cout << left << setw(4) << val;
        }
        cout << endl;
    }
    cout << endl;
}

int main() {
    cout << "Example 1:" << endl;
    vector<vector<int>> matrix1 = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    rotateMatrix(matrix1);
    printMatrix(matrix1);

    cout << "Example 2:" << endl;
    vector<vector<int>> matrix2 = {
        {1,  2,  3,  4},
        {5,  6,  7,  8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };
    rotateMatrix(matrix2);
    printMatrix(matrix2);

    return 0;
}