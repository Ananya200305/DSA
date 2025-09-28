class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;

        for(int i = 0; i < nums.size(); i++){
            int rem = target - nums[i];

            if(map.find(rem) != map.end()){
                return {i, map[rem]};
            }

            map[nums[i]] = i;
        }

        return {};
    }
};