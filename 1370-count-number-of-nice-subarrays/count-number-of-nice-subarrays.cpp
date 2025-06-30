class Solution {
public:
    int atMost(vector<int>& nums, int k){
        if( k < 0 ) return 0;

        int count = 0;
        int l = 0;
        int one = 0;

        for(int r = 0 ; r < nums.size() ; r++){
            if(nums[r]) one++;

            while(one > k){
                if(nums[l] == 1) one--;
                l++;
            }

            count += (r - l + 1);
        }

        return count;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        
        for(int i = 0; i < nums.size(); i++){
            nums[i] = nums[i] % 2;
        }

        return atMost(nums,k) - atMost(nums,k-1);
    }
};