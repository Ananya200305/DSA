class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int rows = mat.size();
        int cols = mat[0].size();
        int left = 0, right = cols - 1;

        while (left <= right) {
            int midCol = left + (right - left) / 2;

            // Find the row with the largest value in the middle column
            int maxRow = 0;
            for (int row = 1; row < rows; ++row) {
                if (mat[row][midCol] > mat[maxRow][midCol]) {
                    maxRow = row;
                }
            }

            // Get neighbors of the maximum value in the middle column
            int leftNeighbor = (midCol > 0) ? mat[maxRow][midCol - 1] : -1;
            int rightNeighbor = (midCol < cols - 1) ? mat[maxRow][midCol + 1] : -1;

            // Check if the current element is a peak
            if (mat[maxRow][midCol] > leftNeighbor && mat[maxRow][midCol] > rightNeighbor) {
                return {maxRow, midCol}; // Found a peak
            }

            // If the left neighbor is greater, move to the left half
            if (leftNeighbor > mat[maxRow][midCol]) {
                right = midCol - 1;
            } 
            // Otherwise, move to the right half
            else {
                left = midCol + 1;
            }
        }

        return {}; // This point is never reached for valid input
    }
};
