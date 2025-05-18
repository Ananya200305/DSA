class Solution {
public:
    int sumOfDigit(int nums){
        int num = abs(nums);
        int sum = 0;

        while(num > 0){
            sum += num%10;
            num = num / 10;
        }

        return sum;
    }
    int smallestIndex(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++){
            if(sumOfDigit(nums[i]) == i){
                return i;
            }
        }
        return -1;
    }
};