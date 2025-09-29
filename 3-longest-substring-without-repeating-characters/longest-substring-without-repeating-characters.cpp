class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0;
        unordered_map<char, int> map;
        int maxLen = 0;

        for(int r = 0; r < s.size(); r++){
            char c = s[r];

            if(map.find(c) != map.end() && map[c] >= l){
                l = map[c] + 1;
            }

            maxLen = max(maxLen, r-l+1);

            map[c] = r;
        }

        return maxLen;
    }
};