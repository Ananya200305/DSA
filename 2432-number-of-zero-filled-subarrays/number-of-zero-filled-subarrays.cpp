class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        nums.push_back(1);
        long long count = 0;
        long long counter = 0;

        for(int i = 0 ; i < nums.size(); i++){
            if(nums[i] == 0){
                counter++;
            }else{
                count += (counter * (counter + 1))/2;
                counter = 0;
            }
        }

        return count;
    }
};