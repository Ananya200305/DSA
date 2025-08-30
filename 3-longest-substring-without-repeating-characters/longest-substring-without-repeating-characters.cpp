class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> lastSeen;
        int left = 0;
        int maxLen = 0;

        for(int right = 0 ; right < s.size(); right++){
            char c = s[right];
            if(lastSeen.find(c) != lastSeen.end() && lastSeen[c] >= left){
                left = lastSeen[c] + 1;
            }

            lastSeen[c] = right;
            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};