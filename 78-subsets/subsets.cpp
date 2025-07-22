class Solution {
public:
    void helper(vector<int>& nums, int index, vector<int>& current, vector<vector<int>>& result){
        result.push_back(current);

        for(int i = index; i < nums.size(); i++){
            current.push_back(nums[i]);
            helper(nums,i+1,current,result);
            current.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        // vector<vector<int>> result;
        // result.push_back({});
        // for(int i = 0; i < nums.size(); i++){
        //     int size = result.size();
        //     for(int j = 0; j < size; j++){
        //         vector<int> temp = result[j];
        //         temp.push_back(nums[i]);
        //         result.push_back(temp);
        //     }
        // }
        // return result;

        vector<vector<int>> result;
        vector<int> current;
        helper(nums, 0, current, result);
        return result;
    }
};