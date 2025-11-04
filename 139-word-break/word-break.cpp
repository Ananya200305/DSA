class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool>flag(s.size()+1, false);
        flag[0] = true;

        unordered_set<string>sets(wordDict.begin(), wordDict.end());

        for(int i = 1; i <= s.size(); i++){
            for(int j = 0; j < i; j++){
                if(flag[j] && sets.count(s.substr(j, i - j))){
                    flag[i] = true;
                    break;
                }
            }
        }

        return flag[s.size()];
    }
};