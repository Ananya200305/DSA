class Solution {
public:
    int helper(vector<vector<int>>& grid, int k, int sum, int i, int j, vector<vector<vector<int>>>& dp){
        if(i == 0 && j == 0){
            return ((sum + grid[0][0]) % k == 0) ? 1 : 0;
        }
        if(i < 0 || j < 0) return 0;

        if(dp[i][j][sum] != -1) return dp[i][j][sum];

        int up = helper(grid, k, (sum + grid[i][j])%k, i-1, j, dp);
        int left = helper(grid, k, (sum + grid[i][j])% k, i, j-1, dp);

        return dp[i][j][sum] = (up + left) % 1000000007;
    }
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int ans = 0;
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<vector<int>>> dp(
            row, 
            vector<vector<int>>(col, vector<int>(k, -1))
        );
        ans = helper(grid, k, 0, row - 1, col-1, dp);
        return ans;
    }
};