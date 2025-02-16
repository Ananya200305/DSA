class Solution {
public:
    bool hasSpecialSubstring(string s, int k) {

        if(s.size() < k){
            return true;
        }

        int i = 0;
        double count = 1;

        while(i < s.size() - 1){
            if(s[i] == s[i+1]){
                count++;
            }else{
                if(count == k){
                    return true;
                }
                count = 1;
            }
            i++;
        }
        return count == k;
    }
};