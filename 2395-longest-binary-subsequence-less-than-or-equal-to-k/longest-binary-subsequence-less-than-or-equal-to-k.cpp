class Solution {
public:
    int longestSubsequence(string s, int k) {
        int len = 0;
        int bit = 0;
        long long val = 0;

        for(int i = s.size() - 1; i >= 0; i--){
            if(s[i] == '0'){
                len++;
            }else{
                if(bit < 32){
                    long long power = 1LL << bit;
                    if(val + power <= k){
                        val += power;
                        len++;
                    }
                }
            }
            bit++;
        }

        return len;
    }
};