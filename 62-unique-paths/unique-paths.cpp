class Solution {
public:

    // RECURSSION
    // int helper(int i, int j){
    //     if(i == 0 && j == 0) return 1;
    //     if(i < 0 || j < 0) return 0;

    //     return helper(i-1, j) + helper(i , j-1);
    // }


    // MEMOIZATION
    // int helper(int i, int j, vector<vector<int>> &dp){
    //     if(i == 0 && j == 0) return 1;
    //     if(i < 0 || j < 0) return 0;

    //     if(dp[i][j] != -1) return dp[i][j];

    //     return dp[i][j] = helper(i-1, j, dp) + helper(i , j-1, dp);
    // }

    int uniquePaths(int m, int n) {

        //RECURSSION
        //return helper(m-1, n-1);

        // MEMOIZATION
        // vector<vector<int>>dp(m, vector<int>(n,-1));
        // return helper(m-1, n-1, dp);

        // TABULATION
        vector<vector<int>>dp(m, vector<int>(n,-1));

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(i == 0 && j == 0){
                    dp[i][j] = 1;
                }else{
                    int up = i > 0 ? dp[i-1][j] : 0;
                    int left = j > 0 ? dp[i][j-1] : 0;
                    dp[i][j] = up + left;
                }
            }
        }

        return dp[m-1][n-1];
    }
};