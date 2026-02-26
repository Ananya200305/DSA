class Solution {
  public:
    int nthRoot(int n, int m) {
        
        if(m == 0) return 0;
        
        int low = 1;
        int high = m;
        
        while(low <= high){
            int mid = low + (high - low)/2;
            long long value = pow(mid, n);
            
            if(value == m){
                return mid;
            }else if(value > m){
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        
        return -1;
    };
};