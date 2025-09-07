class Solution {
public:
    // int helper(vector<vector<int>>& grid, int i, int j, vector<vector<int>>& dp){
    //     if(i == 0 && j == 0) return grid[0][0];
    //     if(i < 0 || j < 0) return 1e9;

    //     if(dp[i][j] != -1) return dp[i][j];

    //     int up = helper(grid, i-1, j, dp);
    //     int down = helper(grid, i, j-1, dp);

    //     return dp[i][j] = grid[i][j] + min(up,down); 
    // }
    int minPathSum(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();

        vector<vector<int>> dp(row, vector<int>(col,-1));

        dp[0][0] = grid[0][0];

        for(int i = 1; i < col; i++){
            dp[0][i] = grid[0][i] + dp[0][i-1];
        }

        for(int i = 1; i < row; i++){
            dp[i][0] = grid[i][0] + dp[i-1][0];
        }

        for(int i = 1; i < row ;i++){
            for(int j = 1; j < col; j++){
                dp[i][j] = grid[i][j] + min(dp[i-1][j] , dp[i][j-1]);
            }
        }

        return dp[row-1][col-1];
    }
};