class Solution {
public:
    void helper(vector<int>& candidates, int target, vector<vector<int>>& res, vector<int>& curr, int index, int sum){
        if(sum == target){
            res.push_back(curr);
            return;
        }

        if(sum > target || index >= candidates.size()){
            return;
        }

        curr.push_back(candidates[index]);
        helper(candidates, target, res, curr, index, sum+candidates[index]);
        curr.pop_back();
        helper(candidates, target, res, curr, index+1, sum);
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>res;
        vector<int>curr;

        helper(candidates, target, res, curr, 0, 0);

        return res;
    }
};