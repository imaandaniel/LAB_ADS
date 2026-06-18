#include <iostream>
#include <vector>

using namespace std;

// HELPER: Finds the row index of the maximum element in a given column.
// Since it's the maximum in this column, we automatically know it's
// greater than its top and bottom neighbors.
int getRowWithMaxElement(const vector<vector<int>>& mat, int col) {
    int maxRow = 0;
    for (int i = 0; i < mat.size(); i++) {
        if (mat[i][col] > mat[maxRow][col]) {
            maxRow = i;
        }
    }
    return maxRow;
}

vector<int> findPeakGrid(vector<vector<int>>& mat) {
    int cols = mat[0].size();
    int leftCol = 0;
    int rightCol = cols - 1;

    while (leftCol <= rightCol) {
        int midCol = leftCol + (rightCol - leftCol) / 2;

        // Step 1: Get the biggest number in the middle column
        int maxRow = getRowWithMaxElement(mat, midCol);
        int currVal = mat[maxRow][midCol];

        // Step 2: Check the left and right neighbors (safely avoiding out-of-bounds)
        bool leftIsBigger = (midCol > 0 && mat[maxRow][midCol - 1] > currVal);
        bool rightIsBigger = (midCol < cols - 1 && mat[maxRow][midCol + 1] > currVal);

        // Step 3: Decide where to go next
        if (!leftIsBigger && !rightIsBigger) {
            // It's strictly greater than or equal to all neighbors
            return {maxRow, midCol};
        }
        else if (leftIsBigger) {
            // A bigger neighbor is on the left, so a peak must exist leftward
            rightCol = midCol - 1;
        }
        else {
            // Otherwise, a peak must exist rightward
            leftCol = midCol + 1;
        }
    }

    return {-1, -1};
}

int main() {
    vector<vector<int>> mat = {
        {10, 20, 15},
        {21, 30, 14},
        {7,  16, 32}
    };

    vector<int> peak = findPeakGrid(mat);
    cout << "[" << peak[0] << ", " << peak[1] << "]" << endl;
    return 0;
}