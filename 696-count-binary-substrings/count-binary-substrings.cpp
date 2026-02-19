class Solution {
public:
    int countBinarySubstrings(string s) {
        int res = 0;
        int streak = 1;
        int prev = 0;

        for(int i = 1; i < s.size(); i++){
            if(s[i] == s[i-1]){
                streak++;
            }else{
                prev = streak;
                streak = 1;
            }

            if(streak <= prev){
                res++;
            }
        }

        return res;
    }
};