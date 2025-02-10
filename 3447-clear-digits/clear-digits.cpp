class Solution {
public:
    string clearDigits(string s) {
        stack <char> st;
        string result = "";
        for(int i = 0; i < s.length(); i++){
            if(!isdigit(s[i])){
                st.push(s[i]);
            }else if(!st.empty()){
                st.pop();
            }
        }

        while(!st.empty()){
            result = st.top() + result;
            st.pop();
        }
        return result;
    }
};