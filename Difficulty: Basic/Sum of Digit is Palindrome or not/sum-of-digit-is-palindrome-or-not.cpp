// User function Template for C++

class Solution {
  public:
    bool isPal(int x){
        int reverse = 0;
        int copy = x;
        
        while(copy){
            int last = copy % 10;
            reverse = reverse * 10 + last;
            copy = copy / 10;
        }
        
        return x == reverse;
    }
    bool isDigitSumPalindrome(int n) {
        int sum = 0;
        
        while(n){
            int last = n % 10;
            sum += last;
            n = n /10;
        }
        
        if(isPal(sum)){
            return true;
        }
        
        return false;
    }
};