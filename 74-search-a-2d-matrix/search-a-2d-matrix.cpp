class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();

        int left = 0;
        int right = row * col - 1;

        while(left <= right){
            int mid = left + (right - left)/2;

            int midVal = matrix[mid/col][mid%col];

            cout << midVal << endl;

            if(midVal == target){
                return true;
            }else if(midVal > target){
                right = mid - 1;
            }else{
                left = mid + 1;
            }
        }

        return false;
    }
};