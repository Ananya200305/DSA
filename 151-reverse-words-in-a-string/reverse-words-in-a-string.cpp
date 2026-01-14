class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());

        string res = "";

        for(int i = 0; i < s.size(); i++){
            string word = "";
            while(i < s.size() && s[i] != ' '){
                word.push_back(s[i]);
                i++;
            }

            if(!word.empty()){
                reverse(word.begin(), word.end());
                res += ' ' + word;
            }
        }

        return res.substr(1);
    }
};