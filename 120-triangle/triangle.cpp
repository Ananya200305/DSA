class Solution {
public:
    // int helper(vector<vector<int>>& triangle, int i, int j, vector<vector<int>>& dp){
    //     int n = triangle.size();
    //     if(i == n-1) return triangle[i][j];

    //     if(dp[i][j] != -1) return dp[i][j];

    //     int down = helper(triangle, i+1, j, dp);
    //     int downR = helper(triangle, i+1, j+1, dp);

    //     return dp[i][j] = triangle[i][j] + min(down, downR);
    // }


    int minimumTotal(vector<vector<int>>& triangle) {
        int ans = INT_MAX;
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        for(int i = 0; i < n; i++){
            dp[n-1][i] = triangle[n-1][i];
        }

        for(int i = n-2; i >= 0; i--){
            for(int j = 0; j <= i; j++){
                int down = dp[i+1][j];
                int downR = dp[i+1][j+1];

                dp[i][j] = triangle[i][j] + min(down, downR);
            }
        }
    
        return dp[0][0];
    }
};