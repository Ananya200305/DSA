class Solution:
    def helper(self, n: int, dp: List[int]) -> int:
        if n < 0:
            return 0
        
        if n == 0:
            return 1
        
        if dp[n] != -1:
            return dp[n]

        one = self.helper(n-1, dp)
        two = self.helper(n-2, dp)

        dp[n] = one+two

        return dp[n]
    
    def climbStairs(self, n: int) -> int:
        dp = [-1] * (n+1)
        return self.helper(n, dp)