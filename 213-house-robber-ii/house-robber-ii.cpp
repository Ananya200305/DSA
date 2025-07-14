class Solution {
public:
    int helper(vector<int>& nums, int start, int end) {
        int prev1 = nums[start];
        int prev2 = 0;
        int currI = 0;

        for(int i = start+1; i <= end; i++){
            int pick = nums[i];
            if(i > 1){
                pick = pick + prev2;
            }
            int notPick = 0 + prev1;
            currI = max(pick, notPick);
            prev2 = prev1;
            prev1 = currI;
        }

        return prev1;
    }

    int rob(vector<int>& nums) {
        int n = nums.size();

        if(n==0) return 0;
        if(n==1) return nums[0];

        int case1 = helper(nums, 0, n-2);
        int case2 = helper(nums,1,n-1);

        return max(case1, case2);
    }
};