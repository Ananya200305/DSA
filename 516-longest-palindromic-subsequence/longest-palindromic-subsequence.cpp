class Solution {
public:
    // int helper(string s, int i, int j, vector<vector<int>>& dp){
    //     if(i > j) return 0;
    //     if(i == j) return 1; 
    //     if(s[i] == s[j]){
    //         dp[i][j] =  2 + helper(s, i+1, j-1, dp);
    //     }else{
    //         dp[i][j] = max(helper(s,i+1,j, dp), helper(s,i,j-1,dp));
    //     }
    //     return dp[i][j];
    // }
    
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>>dp(n, vector<int>(n,0));
        // return helper(s, 0, n-1, dp);

        for(int i = 0 ; i < n ; i++) dp[i][i] = 1;

        for(int i = n-1 ; i >= 0; i--){
            for(int j = i+1; j < n; j++){
                if(s[i] == s[j]) dp[i][j] = 2 + dp[i+1][j-1];
                else dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
            }
        }

        return dp[0][n-1];
    }
};