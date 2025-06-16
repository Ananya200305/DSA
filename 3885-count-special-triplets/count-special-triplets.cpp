class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        const int MOD = 1e9 + 7;
        int n = nums.size();
        long long result = 0;

        unordered_map<int, int> leftCount;
        unordered_map<int, int> rightCount;

        // Initialize rightCount with frequencies of all elements
        for (int num : nums) {
            rightCount[num]++;
        }

        for (int j = 0; j < n; ++j) {
            rightCount[nums[j]]--;  // j is now the current center

            int target = 2 * nums[j];
            long long left = leftCount[target];
            long long right = rightCount[target];

            result = (result + (left * right) % MOD) % MOD;

            leftCount[nums[j]]++;  // j becomes part of left for future iterations
        }

        return result;
    }
};