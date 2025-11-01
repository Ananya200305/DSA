class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int>map;

        for(int n : nums){
            if(map.find(n) != map.end()){
                return true;
            }
            map[n]++;
        }

        return false;
    }
};