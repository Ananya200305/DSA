class Solution {
public:
    // int helper(int n, vector<int>& dp){
    //     if(n == 0) return 1;
    //     if(n < 0) return 0;

    //     if(dp[n] != -1) return dp[n];

    //     int one = helper(n-1,dp);
    //     int two = helper(n-2,dp);

    //     return dp[n] = one + two;
    // }
    int climbStairs(int n) {

        // if(n == 0) return 1;

        // if(n < 0) return 0;

        // int one = climbStairs(n-1);
        // int two = climbStairs(n-2);

        if(n == 0) return 1;
        if(n == 1) return 1;

        vector<int> dp(n+1, -1);

        dp[0] = 1;
        dp[1] = 1;

        for(int i = 2; i < dp.size(); i++){
            dp[i] = dp[i-1] + dp[i-2];
        }

        return dp[n];
    }
};