class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>res(2,-1);
        int low = 0; 
        int high = nums.size()-1;

        while(low <= high){
            int mid = low + (high - low)/2;
            if(nums[mid] < target){
                low = mid + 1;
            }else{
                high = mid - 1;
            }
        }

        if(low < nums.size() && nums[low] == target){
            res[0] = low;
        }

        high = nums.size() - 1;

        while(low <= high){
            int mid = low + (high - low)/2;
            if(nums[mid] > target){
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }

        if(high >= 0 && nums[high] == target){
            res[1] = high;
        }

        return res;
    }
};