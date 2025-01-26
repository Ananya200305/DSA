class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int counter = 0;
        int i = 0;

        while (i < nums.size() - 1) {
            int sum1 = 0;
            int sum2 = 0;

            int k = 0;
            while(k <= i){
                sum1 += nums[k];
                k++;
            }

            int j = nums.size() - 1;
            while(j > i){
                sum2 += nums[j];
                j--;
            }

            if(abs(sum1 - sum2) % 2 == 0){
                counter++;
            }
            i++;
        }

        return counter;
    }
};
