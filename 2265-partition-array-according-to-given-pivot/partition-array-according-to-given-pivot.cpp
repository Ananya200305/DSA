class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int left = 0;
        int right = nums.size() - 1;

        vector<int> result(nums.size(), 0);

        for(int i = 0, j = nums.size()-1; i < nums.size(); i++, j--){
            if(nums[i] < pivot){
                result[left] = nums[i];
                left++;
            }
            if(nums[j] > pivot){
                result[right] = nums[j];
                right--;
            }
        }

        while(left <= right){
            result[left] = pivot;
            left++;
        }

        return result;
    }
};