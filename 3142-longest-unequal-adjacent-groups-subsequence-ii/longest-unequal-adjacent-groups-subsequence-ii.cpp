class Solution {
private:
    int hammingCode(string& a, string& b){
        int diff = 0;
        for(size_t i = 0; i < a.size(); i++){
            if(a[i] != b[i]){
                diff++;
            }
        }
        return diff;
    }
public:
    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n = words.size();
        vector<int> dp(n,1);
        vector<int> prev(n,-1);
        int max_idx = 0;
        int max_len = 1;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
                if((groups[i] != groups[j]) && (words[i].length() == words[j].length())&&
                (hammingCode(words[i], words[j]) == 1)){
                    if(dp[j] + 1 > dp[i]){
                        dp[i] = dp[j] + 1;
                        prev[i] = j;
                    }
                }
            }
            if(max_len < dp[i]){
                    max_len = dp[i];
                    max_idx = i;
            }
        }

        vector<string> res;

        for (int i = max_idx; i != -1; i = prev[i]) {
            res.push_back(words[i]);
        }
        reverse(res.begin(), res.end());
        return res;

    }
};