class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        // int m = matrix.size();
        // int n = matrix[0].size();

        // vector<bool> row(m, false);
        // vector<bool> col(n, false);

        // for(int i = 0; i < m; i++){
        //     for(int j = 0; j < n; j++){
        //         if(matrix[i][j] == 0){
        //             row[i] = true;
        //             col[j] = true;
        //         }
        //     }
        // }

        // for(int i = 0;  i< m; i++){
        //     if(row[i]){
        //         for(int j = 0; j < n; j++){
        //             matrix[i][j] = 0;
        //         }
        //     }
        // }

        // for(int j = 0; j < n;j++){
        //     if(col[j]){
        //         for(int i = 0; i < m;i++){
        //             matrix[i][j] = 0;
        //         }
        //     }
        // }

        int row = matrix.size();
        int col = matrix[0].size();

        bool firstRow = false;
        bool firstCol = false;

        for(int i = 0; i < col; i++){
            if(matrix[0][i] == 0){
                firstRow = true;
                break;
            }
        }

        for(int j = 0; j < row; j++){
            if(matrix[j][0] == 0){
                firstCol = true;
                break;
            }
        }

        for(int i = 1; i < row; i++){
            for(int j = 1; j < col; j++){
                if(matrix[i][j] == 0){
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        for(int i = 1; i < row; i++){
            for(int j = 1; j < col; j++){
                if(matrix[i][0] == 0 || matrix[0][j] == 0){
                    matrix[i][j] = 0;
                }
            }
        }

        if(firstRow){
            for(int i = 0; i < col; i++){
                matrix[0][i] = 0;
            }
        }

        if(firstCol){
            for(int i = 0; i < row; i++){
                matrix[i][0] = 0;
            }
        }
    }
};