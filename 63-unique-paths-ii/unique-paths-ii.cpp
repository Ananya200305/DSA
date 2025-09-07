class Solution {
public:
    int helper(vector<vector<int>>& obstacleGrid, int i, int j, vector<vector<int>>&dp){
        if(i == 0 && j == 0) return 1;
        if(i < 0 || j < 0) return 0;

        int up = 0;
        int left = 0;

        if(dp[i][j] != -1) return dp[i][j];

        if(i-1 >= 0 && obstacleGrid[i-1][j] != 1){
            up = helper(obstacleGrid, i-1, j, dp);
        }

        if(j-1 >= 0 && obstacleGrid[i][j-1] != 1){
            left = helper(obstacleGrid, i, j-1, dp);
        }

        return dp[i][j] = up + left;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int row = obstacleGrid.size();
        int col = obstacleGrid[0].size();

        if(obstacleGrid[0][0] == 1 || obstacleGrid[row-1][col-1] == 1){
            return 0;
        }

        vector<vector<int>> dp(row, vector<int>(col,-1));

        return helper(obstacleGrid, row - 1, col - 1, dp);
    }
};