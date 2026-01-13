class Solution {
public:
    int helper(int x, int y, vector<vector<int>>& dp){
        if(x == 0 && y == 0) return 1;
        if(x < 0 || y < 0) return 0;

        if(dp[x][y] != -1) return dp[x][y];

        return dp[x][y] = helper(x-1, y, dp) + helper(x, y-1, dp);
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m, vector<int>(n,-1));
        return helper(m-1, n-1, dp);
    }
};