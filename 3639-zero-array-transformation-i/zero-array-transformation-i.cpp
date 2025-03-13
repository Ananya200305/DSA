class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> freq(n+1,0);

        for(auto j : queries){
            freq[j[0]]++;
            if(j[1]+1 < n){
                freq[j[1]+1]--;
            }
        }

        int prefix = 0;
        for(int i = 0; i < n; i++){
            prefix = prefix + freq[i];
            nums[i] = nums[i] - prefix;
            if(nums[i] > 0){
                return false;
            }
        }
        return true;
    }
};