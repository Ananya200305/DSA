class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0;
        int maxLen = 0;
        unordered_map<char, int> lastSeen;

        for(int r = 0; r < s.size(); r++){
            char c = s[r];

            if(lastSeen.find(c) != lastSeen.end() && lastSeen[c] >= l){
                l = lastSeen[c]+1;
            }

            maxLen = max(maxLen, r-l+1);

            lastSeen[c] = r;
        }

        return maxLen;
    }
};