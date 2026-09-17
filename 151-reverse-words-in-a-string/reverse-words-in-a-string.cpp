class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());
        
        string ans = "";

        for(int i = 0 ; i < s.size(); i++){
            string word = "";
            while(i < s.size() && s[i] != ' '){
                word += s[i];
                i++;
            }

            if(!word.empty()){
                reverse(word.begin(), word.end());
                ans += " " + word;
            }
        }

        return ans.substr(1);
    }
};