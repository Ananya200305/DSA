class Solution {
public:
    char kthCharacter(int k) {
        string s = "a";

        while(s.length() < k){
            string help = "";

            for(char c : s){
                if(c == 'z'){
                    help.push_back('a');
                }else{
                    help.push_back(c+1);
                }
            }

            s += help;
        }
        

        return s[k-1];
    }
};