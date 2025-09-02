class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLen = 0; 
        int left = 0;
        unordered_map<char, int> lastSeen;

        for(int i = 0 ; i < s.size(); i++){
            char c = s[i];

            if(lastSeen.find(c) != lastSeen.end() && lastSeen[c] >= left){
                left = lastSeen[c] + 1;
            }

            maxLen = max(maxLen, i - left + 1);

            lastSeen[c] = i;
        }

        return maxLen;
    }
};