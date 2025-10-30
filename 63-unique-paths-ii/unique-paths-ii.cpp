class Solution {
public:
    int helper(vector<vector<int>>& grid, int i, int j, vector<vector<int>>& dp){
        int row = grid.size();
        int col = grid[0].size();

        if(i < 0 || j < 0) return 0;
        if(grid[i][j] == 1) return 0;
        if(i == 0 && j == 0) return 1;

        if(dp[i][j] != -1) return dp[i][j];

        int up = helper(grid, i-1, j, dp);
        int left = helper(grid, i , j-1, dp);

        return dp[i][j] = up + left;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();

        vector<vector<int>> dp(row, vector<int>(col, -1));

        return helper(grid, row-1, col-1, dp);
    }
};