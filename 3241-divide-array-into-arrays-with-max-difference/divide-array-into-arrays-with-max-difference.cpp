class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;

        for(int i = 0 ; i < nums.size(); i=i+3){
            int a = nums[i];
            int b = nums[i+1];
            int c = nums[i+2];
            if(c - a > k){
                return {};
            }
            res.push_back({a,b,c});
        }

        return res;
    }
};