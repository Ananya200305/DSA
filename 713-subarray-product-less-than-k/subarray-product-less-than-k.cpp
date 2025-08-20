class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k <= 1) return 0;
        int left = 0; 
        int prod = 1;
        int count = 0;

        for(int right = 0; right < nums.size(); right++){
            prod = prod * nums[right];

            while(prod >= k && left < nums.size()){
                if(nums[left]){
                    prod = prod / nums[left];
                }
                left++;
            }

            count += (right - left + 1);
        }

        return count;
    }
};