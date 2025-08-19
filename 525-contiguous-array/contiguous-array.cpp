class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int sum = 0;
        int maxLen = 0;
        unordered_map<int,int>lastSeen{{0,-1}};

        for(int i = 0 ; i < nums.size(); i++){
            sum += nums[i] == 1 ? 1 : -1;
            if(lastSeen.count(sum)) maxLen = max(maxLen, i - lastSeen[sum]);
            else lastSeen[sum] = i;
        }

        return maxLen;
    }
};