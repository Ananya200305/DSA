class Solution {
  public:
    int k(int i, int W, vector<int> &val, vector<int> &wt, vector<vector<int>> & dp){
        if(i == 0){
            if(W >= wt[0]) return val[0];
            else return 0;
        }
        
        if(dp[i][W] != -1) return dp[i][W];
        
        int notPick = k(i-1, W, val, wt, dp);
        
        int pick = 0;
        if(W >= wt[i]){
            pick = val[i] + k(i-1, W-wt[i], val, wt, dp);
        }
        
        return dp[i][W] = max(pick, notPick);
    }
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        int n = val.size();
        vector<vector<int>>dp(n, vector<int>(W+1, -1));
        return k(n-1, W, val, wt, dp);
    }
};