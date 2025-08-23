class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int maxLen = 0;
        unordered_set<int>s(nums.begin(), nums.end());

        for(int num : s){
            if(s.find(num-1) == s.end()){
                int len = 1;
                int curr = num;

                while(s.find(curr + 1) != s.end()){
                    len++;
                    curr++;
                }

                maxLen = max(maxLen, len);
            }
        }

        return maxLen;
    }
};