class Solution {
public:
    bool possible(vector<int>& nums, int k, int maxSum){
        int currSum = 0;
        int subarray = 1;
        for(int i = 0; i< nums.size(); i++){
            if(currSum + nums[i] > maxSum){
                currSum = nums[i];
                subarray++;
                if(subarray > k){
                    return false;
                }
            }else{
                currSum += nums[i];
            }
            
        }
        return true;
    };
    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);
        int result = high;

        while(low <= high){
            int mid = low + (high - low)/2;
            if(possible(nums,k,mid)){
                result = mid;
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        return result;
    }
};
