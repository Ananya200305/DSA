class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long sum1 = 0;
        long long sum2 = 0;

        bool zero1 = 0;
        bool zero2 = 0;

        for(int i = 0; i < nums1.size(); i++){
            sum1 = sum1 + nums1[i];
            if(nums1[i] == 0){
                zero1 = 1;
                sum1++;
            }
        }

        for(int i = 0; i < nums2.size(); i++){
            sum2 = sum2 + nums2[i];
            if(nums2[i] == 0){
                zero2 = 1;
                sum2++;
            }
        }

        if(sum1 > sum2 && zero2 == 0){
            return -1;
        }
        if(sum2 > sum1 && zero1 == 0){
            return -1;
        }

        return max(sum1, sum2);
    }
};