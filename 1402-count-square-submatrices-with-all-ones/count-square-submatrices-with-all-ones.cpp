class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        int res = 0;

        for(int i = row - 1; i >= 0; i--){
            for(int j = col-1; j >= 0; j--){
                if(matrix[i][j] == 1 && i < row - 1 && j < col - 1){
                    matrix[i][j] = min(min(matrix[i+1][j], matrix[i][j+1]), matrix[i+1][j+1]) + 1;
                }
                res += matrix[i][j];
            }
        }

        return res;
    }
};