class Solution {
  public:
    int setBits(int n) {
        // Write Your Code here
        int count = 1;
        
        while(n != 1){
            if(n % 2 == 1){
                count++;
            }
            n = n/2;
        }
        
        
        return count;
    }
};