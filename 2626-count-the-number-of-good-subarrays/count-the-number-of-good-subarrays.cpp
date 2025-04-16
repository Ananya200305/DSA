class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        long long ans = 0;
        long long pair = 0;
        int left = 0;
        unordered_map <int , int> freq;

        for(int right = 0; right < nums.size(); right++){
            int val = nums[right];

            pair = pair + freq[val];
            freq[val]++;

            while(pair >= k){
                ans = ans + (nums.size() - right);
                int out = nums[left++];
                freq[out]--;
                pair = pair - freq[out]; 
            }
        }

        return ans;
    }
};