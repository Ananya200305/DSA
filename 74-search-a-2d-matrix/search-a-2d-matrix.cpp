class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();
        
        int size = row*col;
        vector<int> arr(size);

        int i = 0;
        int j = 0;
        int k = 0;

        while(i < row){
            int j = 0;
            while(j < col){
                arr[k] = matrix[i][j];
                k++;
                j++;
            }
            i++;
        }

        int low = 0;
        int high = arr.size() - 1;

        while(low <= high){
            int mid = low + (high - low)/2;
            if(target == arr[mid]){
                return true;
            }else if(target < arr[mid]){
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        return false;
    }
};