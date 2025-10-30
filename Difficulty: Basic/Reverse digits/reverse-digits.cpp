class Solution {
  public:
    int reverseDigits(int n) {
        // Code here
        int ans = 0;
        
        while(n){
            int last = n%10;
            ans = ans * 10 + last;
            n = n/10;
        }
        
        return ans;
    }
};