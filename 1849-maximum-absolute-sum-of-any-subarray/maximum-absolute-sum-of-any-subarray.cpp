class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int i = 0;
        int sum = 0;
        int maxSum = INT_MIN;
        int n = nums.size();
        while(i < n){
            sum += nums[i];
            maxSum = max(sum, maxSum);
            if(sum < 0){
                sum = 0;
            }
            i++;
        }

        i = 0;
        sum = 0;
        int minSum = INT_MAX;
        while(i < n){
            sum += nums[i];
            minSum = min(minSum,sum);
            if(sum > 0){
                sum = 0;
            }
            i++;
        }
        return max(abs(minSum),abs(maxSum));
    }
};