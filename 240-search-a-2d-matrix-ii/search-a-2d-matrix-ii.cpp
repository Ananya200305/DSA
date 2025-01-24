class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int i = 0;
        int j = 0;
        int main = 0;

        int row = matrix.size();
        int col = matrix[0].size();

        while(i < row){
            int j = 0;
            while(j < col){
                main = matrix[i][j];
                if(main == target){
                return true;
            }
                j++;
            }
            
            i++;
        }
        return false;
    }
};