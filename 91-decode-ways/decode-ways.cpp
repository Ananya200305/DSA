class Solution {
public:
    int helper(string & s, int i, vector<int>& dp){
        if(i == s.size()){
            return 1;
        }

        if(s[i] == '0'){
            return 0;
        }

        int ways = 0;

        if(dp[i] != -1) return dp[i];

        ways = ways + helper(s, i+1, dp);

        if((i + 1) < s.size()){
            int nums = (s[i] - '0') * 10 + (s[i+1] - '0');
            if(nums >= 10 && nums <= 26){
                ways = ways + helper(s, i+2, dp);
            }
        }

        return dp[i] = ways;
    }
    int numDecodings(string s) {
        vector<int>dp(s.size()+1, -1);
        return helper(s, 0, dp);
    }
};