class Solution {
public:
    int binarySearch(vector<int>& nums, int target){
        int left = 0;
        int right = nums.size()-1;

        while(left <= right){
            int mid = left + (right - left)/2;

            if(target == nums[mid]){
                return mid;
            }else if(target < nums[mid]){
                right = mid - 1;
            }else if(target > nums[mid]){
                left = mid + 1;
            }
        }

        return left;
    }
    int lengthOfLIS(vector<int>& nums) {
        vector<int>ans;

        for(int i = 0; i < nums.size(); i++){
            if(ans.empty() || ans.back() < nums[i]){
                ans.push_back(nums[i]);
            }else{
                int idx = binarySearch(ans, nums[i]);
                ans[idx] = nums[i];
            }
        }

        return ans.size();
    }
};