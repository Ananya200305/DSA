class Solution {
public:
    // Helper function to determine if the array can be split into `k` subarrays
    // with each subarray's sum <= maxSum
    bool canSplit(vector<int>& nums, int k, int maxSum) {
        int currentSum = 0, subarrays = 1;
        for (int num : nums) {
            if (currentSum + num > maxSum) {
                currentSum = num; // Start a new subarray
                subarrays++;
                if (subarrays > k) return false; // Too many subarrays
            } else {
                currentSum += num;
            }
        }
        return true;
    }
    
    int splitArray(vector<int>& nums, int k) {
        // Binary search bounds
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);
        int result = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (canSplit(nums, k, mid)) {
                result = mid; // Possible candidate, try for smaller largest sum
                high = mid - 1;
            } else {
                low = mid + 1; // Increase the largest sum
            }
        }
        return result;
    }
};
