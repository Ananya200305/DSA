class Solution {
public:
    int rob(vector<int>& nums) {
        // int n = nums.size();
        // vector<int> dp(n,-1);

        // dp[0] = nums[0];

        // for(int i = 1; i < n; i++){
        //     int pick = nums[i];
        //     if(i > 1){
        //         pick = pick + dp[i-2];
        //     }
        //     int notPick = 0 + dp[i-1];
        //     dp[i] = max(pick, notPick);
        // }

        // return dp[n-1];

        int n = nums.size();
        int prev1 = nums[0];
        int prev2 = 0;
        int currI = 0;

        for(int i = 1; i < n; i++){
            int pick = nums[i];
            if(i > 1){
                pick = pick + prev2;
            }
            int notPick = 0 + prev1;
            currI = max(pick, notPick);
            prev2 = prev1;
            prev1 = currI;
        }

        return prev1;
    }
};