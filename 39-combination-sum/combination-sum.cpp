class Solution {
public:
    void helper(vector<int>& candidates, int target, int index, vector<vector<int>> &result, int sum, vector<int> &curr){
        if(sum == target){
            result.push_back(curr);
            return;
        }

        if(sum > target || index >= candidates.size()){
            return;
        }

        curr.push_back(candidates[index]);
        helper(candidates, target, index, result, sum + candidates[index], curr);
        curr.pop_back();
        helper(candidates, target, index+1, result, sum , curr);

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> curr;
        helper(candidates, target, 0, result, 0, curr);
        return result;
    }
};