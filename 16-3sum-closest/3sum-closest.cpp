class Solution {
public:
    int twoSum(vector<int>& nums, int target, int i, int j){
        int closest = nums[i] + nums[j];

        while(i < j){
            int sum = nums[i] + nums[j];

            if(abs(target - sum) < abs(target - closest)){
                closest = sum;
            }

            if(sum < target){
                i++;
            }else if(sum > target){
                j--;
            }else{
                return sum;
            }
        }
        return closest;
    }

    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        if(n < 3) return 0;
        sort(nums.begin(), nums.end());
        int closest = nums[0] + nums[1] + nums[2];

        for(int i = 0 ; i < n-2; i++){
            if(i > 0 && nums[i] == nums[i-1]) continue;

            int twoSumTarget = target - nums[i];
            int twoSumClosest = twoSum(nums, twoSumTarget, i+1, n-1);
            int sum = nums[i] + twoSumClosest;

            if(abs(target - sum) < abs(target - closest)){
                closest = sum;
            }

            if(closest == target) return closest;
        }

        return closest;
    }
};