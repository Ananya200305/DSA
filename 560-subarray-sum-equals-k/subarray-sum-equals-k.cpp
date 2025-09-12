class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int subArr = 0;
        unordered_map<int, int>map;
        map[0] = 1;
        int count = 0;

        for(int i = 0 ; i < nums.size(); i++){
            subArr += nums[i];
            int rem = subArr - k;

            if(map.find(rem) != map.end()){
                count += map[rem];
            }

            map[subArr]++;
        }

        return count;
    }
};