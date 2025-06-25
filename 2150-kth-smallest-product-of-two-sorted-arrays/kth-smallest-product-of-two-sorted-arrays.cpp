class Solution {
public:
    long long countTok(vector<int>& nums1, vector<int>& nums2, long long target){
        long long count = 0;

        for(int num1 : nums1){
            if(num1 == 0){
                if(target >= 0){
                    count += nums2.size();
                    continue;
                }
            }

            int left = 0;
            int right = nums2.size() -1;

            while(left <= right){
                int mid = left + (right - left)/2;
                long long product = 1LL * num1 * nums2[mid];

                if(product <= target){
                    if(num1 > 0){
                        left = mid + 1;
                    }else{
                        right = mid - 1;
                    }
                }else{
                    if(num1 > 0){
                        right = mid - 1;
                    }else{
                        left = mid + 1;
                    }
                }
            }
            count += (num1 > 0) ? left : (nums2.size() - left);
        }

        return count;
    }

    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        long long left = -1e10;
        long long right = 1e10;

        while(left <= right){
            long long mid = left + (right - left)/2;

            if(countTok(nums1, nums2, mid) < k){
                left = mid + 1;
            }else{
                right = mid - 1;
            }
        }

        return left;
    }
};