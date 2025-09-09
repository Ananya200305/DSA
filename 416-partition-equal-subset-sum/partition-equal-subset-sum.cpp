class Solution {
public:
    // bool helper(vector<int>& nums, int i, int target, vector<bool> & dp){
    //     if(target == 0) return true;
    //     if(i >= nums.size() || target < 0) return false;

    //     if(dp[i] != false) return dp[i];

    //     if(dp[i] = helper(nums, i + 1, target-nums[i], dp)){
    //         return true;
    //     }

    //     return dp[i] = helper(nums, i+1, target, dp);
    // }
    bool canPartition(vector<int>& nums) {
        int sum = 0;

        for(int num : nums){
            sum += num;
        }

        if(sum % 2 != 0) return false;

        vector<bool> dp(sum + 1 , false);

        dp[0] = true;
        sum = sum/2;

        for(int num : nums){
            for(int i = sum ; i >= num ; i--){
                if(dp[i-num]) dp[i] = true;
                if(dp[sum]) return true;
            }
        }
        return false;
    }
};