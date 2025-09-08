class Solution {
public:
    // int helper(vector<vector<int>>& triangle, int i, int j, vector<vector<int>>&dp){
    //     int n = triangle.size();

    //     if(i == n-1) return triangle[i][j];

    //     if(dp[i][j] != -1) return dp[i][j];

    //     int down = helper(triangle, i+1, j,dp);
    //     int downRight = helper(triangle, i+1, j+1, dp);

    //     return dp[i][j] = triangle[i][j] + min(down, downRight);
    // }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int>dp(n,0);
        
        for(int i = 0; i < n; i++){
            dp[i] = triangle[n-1][i];
        }

        for(int i = n - 2; i >= 0 ; i--){
            for(int j = 0; j <= i; j++){
                int down = triangle[i][j] + dp[j];
                int downRight = triangle[i][j] + dp[j+1];

                dp[j] = min(down , downRight);
            }
        }

        return dp[0];
    }
};