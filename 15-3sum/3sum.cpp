class Solution {
public:
    // // Function to find two numbers that sum to `target`
    // vector<vector<int>> twoSum(vector<int>& nums, int target, int left, int right) {
    //     vector<vector<int>> pairs;
        
    //     while (left < right) {
    //         int sum = nums[left] + nums[right];

    //         if (sum > target) {
    //             right--; // Decrease sum by moving right pointer
    //         } else if (sum < target) {
    //             left++; // Increase sum by moving left pointer
    //         } else {
    //             pairs.push_back({-target, nums[left], nums[right]});
                
    //             // Skip duplicate elements
    //             while (left < right && nums[left] == nums[left + 1]) left++;
    //             while (left < right && nums[right] == nums[right - 1]) right--;

    //             left++;
    //             right--;
    //         }
    //     }
    //     return pairs;
    // }
    vector<vector<int>> twoSum (vector<int>& nums, int target, int i, int j){
        vector<vector<int>> pairs;

        while(i < j){
            int sum = nums[i] + nums[j];

            if(sum > target){
                j--;
            }else if(sum < target){
                i++;
            }else{
                pairs.push_back({-target, nums[i], nums[j]});

                while(i < j && nums[i] == nums[i+1]) i++;
                while(i < j && nums[j] == nums[j-1]) j--;

                i++;
                j--;
            }
        }
        return pairs;
    }

    vector<vector<int>> threeSum(vector<int>& nums) {
    //     int n = nums.size();
    //     if (n < 3) return {}; // Edge case: If fewer than 3 elements, return empty

    //     vector<vector<int>> result;

    //     // Sort the array for two-pointer approach
    //     sort(nums.begin(), nums.end());

    //     // Iterate through each number and find pairs using twoSum
    //     for (int i = 0; i < n - 2; i++) {
    //         // Skip duplicates to avoid repeated triplets
    //         if (i > 0 && nums[i] == nums[i - 1]) continue;

    //         int target = -nums[i]; // We need two numbers that sum to `-nums[i]`
    //         vector<vector<int>> pairs = twoSum(nums, target, i + 1, n - 1);

    //         // Append valid pairs to result
    //         for (auto& pair : pairs) {
    //             result.push_back(pair);
    //         }
    //     }
    //     return result;

        int n = nums.size();

        if(n < 3){
            return {};
        }

        sort(nums.begin(), nums.end());

        vector<vector<int>> result;

        for(int i = 0 ; i < n-2; i++){
            if(i > 0 && nums[i] == nums[i-1]) continue;

            int target = - nums[i];

            vector<vector<int>> pairs = twoSum(nums, target, i+1, n-1);

            for(auto& pair : pairs){
                result.push_back(pair);
            }
        }

        return result;
    }
};

