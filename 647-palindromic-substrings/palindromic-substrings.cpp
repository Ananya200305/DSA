class Solution {
public:
    int expand(string s, int left, int right){
        int t = 0;

        while(left >= 0 && right < s.size()){
            if(s[left] != s[right]) break;

            left--;
            right++;
            t++;
        }

        return t;
    }
    int countSubstrings(string s) {
        int ans = 0;
        for(int i = 0; i < s.size(); i++){
            ans += expand(s, i, i);
            ans += expand(s, i, i+1);
        }

        return ans;
    }
};