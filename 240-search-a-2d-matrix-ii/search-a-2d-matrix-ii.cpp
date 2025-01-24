class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int i = 0;
      

        int row = matrix.size();
        int col = matrix[0].size();

        while(i < row){
            int j = 0;
            while(j < col){
          
                if(matrix[i][j] == target){
                return true;
            }
                j++;
            }
            
            i++;
        }
        return false;
    }
};