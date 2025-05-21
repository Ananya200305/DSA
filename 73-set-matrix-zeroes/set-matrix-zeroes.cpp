class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        // int rows = matrix.size();
        // if (rows == 0) return;
        // int cols = matrix[0].size();
        // bool firstRowZero = false;
        // bool firstColZero = false;

        // // Check if the first row needs to be zeroed
        // for (int j = 0; j < cols; ++j) {
        //     if (matrix[0][j] == 0) {
        //         firstRowZero = true;
        //         break;
        //     }
        // }

        // // Check if the first column needs to be zeroed
        // for (int i = 0; i < rows; ++i) {
        //     if (matrix[i][0] == 0) {
        //         firstColZero = true;
        //         break;
        //     }
        // }

        // // Use first row and column to mark zeros
        // for (int i = 1; i < rows; ++i) {
        //     for (int j = 1; j < cols; ++j) {
        //         if (matrix[i][j] == 0) {
        //             matrix[i][0] = 0;
        //             matrix[0][j] = 0;
        //         }
        //     }
        // }

        // // Zero out marked rows except the first row
        // for (int i = 1; i < rows; ++i) {
        //     if (matrix[i][0] == 0) {
        //         for (int j = 1; j < cols; ++j) {
        //             matrix[i][j] = 0;
        //         }
        //     }
        // }

        // // Zero out marked columns except the first column
        // for (int j = 1; j < cols; ++j) {
        //     if (matrix[0][j] == 0) {
        //         for (int i = 1; i < rows; ++i) {
        //             matrix[i][j] = 0;
        //         }
        //     }
        // }

        // // Zero out the first row if needed
        // if (firstRowZero) {
        //     for (int j = 0; j < cols; ++j) {
        //         matrix[0][j] = 0;
        //     }
        // }

        // // Zero out the first column if needed
        // if (firstColZero) {
        //     for (int i = 0; i < rows; ++i) {
        //         matrix[i][0] = 0;
        //     }
        // }

        int m = matrix.size();
        int n = matrix[0].size();

        vector<bool> row(m, false);
        vector<bool> col(n, false);

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(matrix[i][j] == 0){
                    row[i] = true;
                    col[j] = true;
                }
            }
        }

        for(int i = 0;  i< m; i++){
            if(row[i]){
                for(int j = 0; j < n; j++){
                    matrix[i][j] = 0;
                }
            }
        }

        for(int j = 0; j < n;j++){
            if(col[j]){
                for(int i = 0; i < m;i++){
                    matrix[i][j] = 0;
                }
            }
        }
    }
};