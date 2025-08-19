class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool>dp(s.size()+1, 0);
        dp[0] = true;
        unordered_set<string> sets(wordDict.begin(), wordDict.end());
        for(int i = 1; i <= s.size(); i++){
            for(int j = 0; j < i; j++){
                if(dp[j] && sets.count(s.substr(j, i-j))){
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[s.size()];
    }
};