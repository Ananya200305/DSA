class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // for(int i = 0; i < nums.size(); i++){
        //     for(int j = i + 1; j < nums.size(); j++){
        //         if(nums[i] + nums[j] == target){
        //             return {i,j};
        //         }
        //     }
        // }
        // return {};

        unordered_map<int, int> mp;

        for(int i = 0; i < nums.size(); i++){
            int num = nums[i];
            int more = target - num;
            if(mp.find(more) != mp.end()){
                return {mp[more],i};
            }
            mp[num] = i;
        }

        return {};
    } 
};