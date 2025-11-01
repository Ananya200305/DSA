class Solution {
public:
    vector<vector<int>> two(vector<int>& nums, int target, int left, int right){
        vector<vector<int>> pairs;

        while(left < right){
            int sum = nums[left] + nums[right];

            if(target > sum){
                left++;
            }else if(target < sum){
                right--;
            }else{
                pairs.push_back({-target, nums[left], nums[right]});

                while(left < right && nums[left] == nums[left+1]) left++;
                while(left < right && nums[right] == nums[right-1]) right--;

                left++;
                right--;
            }
        }

        return pairs;
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        if(n < 3) return {};

        sort(nums.begin(), nums.end());

        vector<vector<int>> res;

        for(int i = 0; i < n-2; i++){
            if(i > 0 && nums[i] == nums[i-1]) continue;
            int first = -1 * nums[i];

            vector<vector<int>> twoSum = two(nums, first, i+1, n-1);

            for(auto p : twoSum){
                res.push_back(p);
            }
        }

        return res;
    }
};