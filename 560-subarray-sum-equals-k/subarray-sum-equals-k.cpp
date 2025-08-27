class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        int count = 0;
        int subarr = 0;
        map[0] = 1;

        for(int i = 0; i < nums.size(); i++){
            subarr += nums[i];
            int rem = subarr - k;

            if(map.find(rem) != map.end()){
                count+= map[rem];
            }

            map[subarr]++;
        }

        return count;
    }
};