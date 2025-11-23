class Solution {
public:
    int helper(int i, int sum, vector<int>& nums, vector<vector<int>>& dp){
        if(i == nums.size()){
            return (sum == 0 ? 0 : INT_MIN/2);
        }

        if(dp[i][sum] != -1) return dp[i][sum];

        int pick = nums[i] + helper(i+1, (sum+nums[i])%3, nums, dp);
        int unpick = helper(i+1, sum, nums, dp);

        return dp[i][sum] = max(pick, unpick);
    }
    int maxSumDivThree(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp(n, vector<int>(3, -1));
        int ans = helper(0, 0, nums, dp);
        return (ans < 0) ? 0 : ans;
    }
};