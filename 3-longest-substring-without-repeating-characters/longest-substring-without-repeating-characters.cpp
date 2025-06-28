class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res = 0;

        unordered_map<char, int>lastSeen;

        int left = 0;
        int right = 0;

        for(int right = 0; right < s.size(); right++){
            int current = s[right];

            if(lastSeen.count(current) && lastSeen[current] >= left){
                left = lastSeen[current] + 1;
            }

            lastSeen[current] = right;

            res = max(res,right - left + 1);
        }

        return res;
    }
};