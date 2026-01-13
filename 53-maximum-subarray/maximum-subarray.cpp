class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sub = nums[0];
        int maxSub = nums[0];

        for(int i = 1; i < nums.size(); i++){
            sub = max(sub + nums[i], nums[i]);
            maxSub = max(maxSub, sub);
        }

        return maxSub;
    }
};