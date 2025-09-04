class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();

        for(int i = 0; i < row; i++){
            if(matrix[i][0] <= target && target <= matrix[i][col-1]){
                int l = 0;
                int r = col-1;
                while(l <= r){
                    int mid = l + (r-l)/2;
                    if(target == matrix[i][mid]){
                        return true;
                    }else if(matrix[i][mid] > target){
                        r = mid - 1;
                    }else{
                        l = mid + 1;
                    }
                }
            }
        }

        return false;
    }
};