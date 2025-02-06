class Solution {
public:
    string longestPalindrome(string s) {
        if(s.length() <= 1){
            return s;
        }
        string result = "";
        
        for(int i = 1; i < s.length(); i++){
            int low = i;
            int high = i;
            while(low >= 0 && high < s.length() && s[low] == s[high]){
                string p = s.substr(low, high-low+1);
                low--;
                high++;

                if(p.length() > result.length()){
                    result = p;
                }
            }

            low = i-1;
            high = i;
            while(low >= 0 && high < s.length() && s[low] == s[high]){
                string p = s.substr(low, high-low+1);
                low--;
                high++;
                
                if(p.length() > result.length()){
                    result = p;
                }
            }
        }
        return result;
    }
};