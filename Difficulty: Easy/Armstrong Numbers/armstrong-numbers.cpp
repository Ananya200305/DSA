// User function Template for C++
class Solution {
  public:
    bool armstrongNumber(int n) {
        int ans = 0;
        int copy = n;
        while(copy){
            int digit = copy % 10;
            ans += digit * digit * digit;
            copy = copy/10;
        }
        
        return n == ans;
    }
};