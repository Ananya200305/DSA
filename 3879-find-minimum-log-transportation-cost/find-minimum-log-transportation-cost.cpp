class Solution {
public:
    long long minCuttingCost(int n, int m, int k) {
        long long costn = LLONG_MAX;
        long long costm = LLONG_MAX;
        
        if(n <= k && m <= k){
            return 0;
        }

        if(n > k){
            long long len1 = k;
            long long len2 = n - k;
            costn = len1 * len2;
        } else {
            costn = 0;
        }

        if(m > k){
            long long len1 = k;
            long long len2 = m - k;
            costm = len1 * len2;
        } else {
            costm = 0;
        }

        return costn + costm;
    }
};
