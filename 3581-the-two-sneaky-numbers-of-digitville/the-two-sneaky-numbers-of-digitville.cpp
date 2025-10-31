class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        unordered_map<int, int>map;

        for(int i = 0 ; i < nums.size(); i++){
            map[nums[i]]++;
        }

        vector<int>ans;

        for(auto [key, val] : map){
            if(val >= 2){
                ans.push_back(key);
            }
        }

        return ans;
    }
};