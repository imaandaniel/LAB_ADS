#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;

        int rows = matrix.size();
        int cols = matrix[0].size();
        int maxArea = 0;

        // dp[i][j] will store the number of consecutive 1s
        // ending at matrix[i][j] going left.
        vector<vector<int>> dp(rows, vector<int>(cols, 0));

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {

                if (matrix[i][j] == 1) {
                    // 1. Calculate width of 1s for the current row ending at j
                    dp[i][j] = (j == 0) ? 1 : dp[i][j - 1] + 1;

                    // 2. Now, look upwards from the current cell to build rectangles
                    int currentWidth = dp[i][j];

                    // Loop 'k' goes from the current row 'i' straight up to row 0
                    for (int k = i; k >= 0; k--) {

                        // The rectangle's width is bottlenecked by the shortest width we see looking up
                        currentWidth = min(currentWidth, dp[k][j]);

                        // If we hit a 0 above us, the width becomes 0, and we can't go higher
                        if (currentWidth == 0) break;

                        // Calculate area: width * height (which is i - k + 1)
                        int currentHeight = i - k + 1;
                        int currentArea = currentWidth * currentHeight;

                        // Update our maximum area found so far
                        maxArea = max(maxArea, currentArea);
                    }
                }
            }
        }

        return maxArea;
    }
};

int main() {
    // 1. Set up the test matrix from the example
    vector<vector<int>> matrix = {
        {0, 1, 1, 0},
        {1, 1, 1, 1},
        {1, 1, 1, 1},
        {1, 1, 0, 0}
    };

    // 2. Instantiate the Solution class
    Solution solution;

    // 3. Call the method and store the result
    int result = solution.maximalRectangle(matrix);

    // 4. Print the result to the console
    cout << "The area of the largest rectangle is: " << result << endl;

    return 0;
}