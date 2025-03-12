class Solution {
public:
    int binarySearch(vector<int>& nums, int target){
        int low = 0; 
        int high = nums.size() - 1;
        int result = nums.size();

        while(low <= high){
            int mid = low + (high - low)/2;
            if(nums[mid] < target){
                low = mid + 1;
            }else{
                result = mid;
                high = mid - 1;
            }
        }
        return result;
    }

    int maximumCount(vector<int>& nums) {
        int n = nums.size();
        int negative = binarySearch(nums,0);
        int positive = n - binarySearch(nums,1);
        return max(negative,positive);
    }
};