class Solution {
  public:
    bool isEven(int n) {
        if((n & 1) ==  0){
            return true;
        }
        return false; 
    }
};