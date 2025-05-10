class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long sum1 = 0;
        long long sum2 = 0;

        bool zero1 = false;
        bool zero2 = false;

        for(int i = 0; i < nums1.size(); i++){
            sum1 = sum1 + nums1[i];
            if(nums1[i] == 0){
                zero1 = true;
                sum1++;
            }
        }

        for(int i = 0; i < nums2.size(); i++){
            sum2 = sum2 + nums2[i];
            if(nums2[i] == 0){
                zero2 = true;
                sum2++;
            }
        }

        if(sum1 > sum2 && zero2 == false){
            return -1;
        }

        if(sum1 < sum2 && zero1 == false){
            return -1;
        }

        return max(sum1, sum2);
    }
};