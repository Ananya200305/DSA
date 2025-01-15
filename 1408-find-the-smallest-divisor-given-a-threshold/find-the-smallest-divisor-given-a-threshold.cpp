class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int max = nums[0];
        for(int i = 0; i < nums.size() ; i++){
            if(max < nums[i]){
                max = nums[i];
            }
        }

        int low = 1;
        int high = max;
        while(low < high){
            int mid = low + (high - low)/2;
            int divisor = 0;
            for(int i = 0; i < nums.size(); i++){
                divisor += (nums[i]+mid-1)/mid;
            }
            if(divisor <= threshold){
                high = mid;
            }else{
                low = mid + 1;
            }
        }
        return low;
    }
};