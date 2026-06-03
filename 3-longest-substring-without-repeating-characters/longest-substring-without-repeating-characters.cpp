class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> lastSeen;

        int l = 0;
        int maxLen = 0;

        for(int r = 0; r < s.size(); r++){
            char ch = s[r];

            if(lastSeen.find(ch) != lastSeen.end() && l <= lastSeen[ch]){
                l = lastSeen[ch] + 1;
            }

            maxLen = max(maxLen, r - l + 1);
            lastSeen[s[r]] = r;
        }

        return maxLen;
    }
};