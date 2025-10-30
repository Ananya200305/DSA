class Solution {
public:
    // int helper(vector<vector<int>>& grid, int i, int j, vector<vector<int>>& dp){
    //     int row = grid.size();
    //     int col = grid[0].size();

    //     if(i < 0 || j < 0) return 0;
    //     if(grid[i][j] == 1) return 0;
    //     if(i == 0 && j == 0) return 1;

    //     if(dp[i][j] != -1) return dp[i][j];

    //     int up = helper(grid, i-1, j, dp);
    //     int left = helper(grid, i , j-1, dp);

    //     return dp[i][j] = up + left;
    // }


    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();

        if(grid[0][0] == 1 || grid[row-1][col-1] == 1){
            return 0;
        }


        vector<vector<int>> dp(row, vector<int>(col, 0));

        dp[0][0] = 1;

        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(grid[i][j] == 1){
                    dp[i][j] = 0;
                }else if (i == 0 && j == 0) {
                    continue;  
                }else{
                    int right = j > 0 ? dp[i][j-1] : 0;
                    int down = i > 0 ? dp[i-1][j] : 0;

                    dp[i][j] = right + down ;
                }
            }
        }

        return dp[row-1][col-1];
    }
};