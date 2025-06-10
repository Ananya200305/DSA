// User function Template for C++

class Solution {
  public:
    pair<int, int> get(int a, int b) {
        pair<int, int> res;
        
        a = a^b;
        b = a^b;
        a = a^b;
        
        res.first = a;
        res.second = b;
        
        return res;
    }
};