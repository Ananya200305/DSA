class Solution:
    # def helper(self, i: int, j: int, dp: List[List[int]]) -> int:
    #     if i < 0 or j < 0: 
    #         return 0
    #     if i == 0 and j == 0:
    #         return 1

    #     if dp[i][j] != -1:
    #         return dp[i][j]
        
    #     up = self.helper(i-1, j, dp)
    #     left = self.helper(i, j-1, dp)

    #     dp[i][j] = up + left

    #     return dp[i][j]

    def uniquePaths(self, m: int, n: int) -> int:
        dp = [[-1 for _ in range(n)] for _ in range(m)]

        for i in range(m):
            for j in range(n):
                if i == 0 and j == 0:
                    dp[i][j] = 1
                else:
                    right = dp[i][j-1] if j > 0 else 0
                    down = dp[i-1][j] if i > 0 else 0
                    dp[i][j] = right + down
                
        return dp[m-1][n-1]