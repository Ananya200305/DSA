class Solution {
public:
    void permutation(int i, vector<int>& nums, vector<vector<int>>& res){
        if(i == nums.size()){
            res.push_back(nums);
            return;
        }

        for(int j = i; j < nums.size(); j++){
            swap(nums[i], nums[j]);
            permutation(i+1, nums, res);
            swap(nums[i], nums[j]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>res;
        permutation(0, nums, res);
        return res;
    }
};