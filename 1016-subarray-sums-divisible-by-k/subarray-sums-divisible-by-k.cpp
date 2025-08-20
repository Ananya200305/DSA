class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> map{{0,1}};
        int prefix = 0;
        int count = 0;

        for(int i = 0; i < nums.size(); i++){
            prefix += nums[i];

            int rem = ((prefix % k)+k)%k;

            if(map.count(rem)){
                count += map[rem];
            }

            map[rem]++;
        }

        return count;
    }
};