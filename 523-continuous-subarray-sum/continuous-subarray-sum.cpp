class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int prefix = 0;
        unordered_map<int, int> lastSeen{{0,-1}};
        for(int i = 0; i < nums.size(); i++){
            prefix += nums[i];
            int rem = prefix % k;

            if(lastSeen.count(rem)){
                if(i - lastSeen[rem] >= 2) return true;
            }else{
                lastSeen[rem] = i;
            }
        }
        return false;
    }
};