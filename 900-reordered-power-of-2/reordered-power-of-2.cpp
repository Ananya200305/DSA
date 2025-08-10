class Solution {
public:
    string countDigit(int n){
        string s = to_string(n);
        sort(s.begin(), s.end());
        return s;
    }
    bool reorderedPowerOf2(int n) {
        string target = countDigit(n);
        for(int i = 0; i < 31; i++){
            if(countDigit(1 << i) == target){
                return true;
            }
        }
        return false;
    }
};