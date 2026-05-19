// User function Template for C++
class Solution {
  public:
    int helper(int n){
        return n*n*n;
    }
    bool armstrongNumber(int n) {
        int temp = n;
        
        int sum = 0;
        
        while(temp > 0){
            int digit = temp % 10;
            
            sum += helper(digit);
            
            temp = temp /10;
        }
        
        if(sum == n){
            return true;
        }
        
        return false;
    }
};