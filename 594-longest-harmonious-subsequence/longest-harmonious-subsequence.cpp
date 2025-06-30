class Solution {
public:
    int findLHS(vector<int>& nums) {

        // O(n log n)

        // sort(nums.begin(), nums.end());

        // int left = 0; 
        // int maxLen = 0;

        // for(int right = 0; right < nums.size(); right++){
        //     while(nums[right] - nums[left] > 1){
        //         ++left;
        //     }

        //     if(nums[right] - nums[left] == 1){
        //         maxLen = max(maxLen , right - left + 1);
        //     }
        // }

        // return maxLen;

        // O(n)

        unordered_map<int , int> frequency;

        int maxLen = 0;

        for(int i = 0; i < nums.size(); i++){
            frequency[nums[i]]++;
        }

        for(auto& [n, f] : frequency){
            if(frequency.count(n + 1)){
                int len = f + frequency[n + 1];
                maxLen = max(maxLen, len);
            }
        }

        return maxLen;
    }
};