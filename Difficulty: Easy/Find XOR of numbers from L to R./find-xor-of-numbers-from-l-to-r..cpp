// User function Template for C++

class Solution {
  public:
    int upto(int n){
        if(n % 4 == 0){
            return n;
        }else if(n % 4 == 1){
            return 1;
        }else if(n % 4 == 2){
            return n+1;
        }else{
            return 0;
        }
    }
    int findXOR(int l, int r) {
        // int xorRes = 0;
        
        // for(int i = l; i <= r; i++){
        //     xorRes = xorRes ^ i;
        // }
        
        // return xorRes;
        
        // 0100 - 4
        // 0101 - 5
        // 0001 - 1
        // 0110 - 6
        // 0111 - 7
        // 0111 - 7
        // 0000 - 0
        // 1000 - 8
        // 1000 - 8
        
        return upto(r) ^ upto(l-1);
    }
};
