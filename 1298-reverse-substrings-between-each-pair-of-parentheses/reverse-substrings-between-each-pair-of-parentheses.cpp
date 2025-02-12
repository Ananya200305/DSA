class Solution {
public:
    string reverseParentheses(string s) {
        stack<char> st;
        string result = "";
        // int count = 0;

        for(int i = 0; i < s.length(); i++){
            if(s[i] == ')'){
                string temp = "";
                while(st.top() != '('){
                    temp.push_back(st.top());
                    st.pop();
                }
                st.pop();
                for(int j = 0; j < temp.size(); j++){
                        st.push(temp[j]);
                }
                continue;
            }
            st.push(s[i]);
        }
        while(!st.empty()){
            result.push_back(st.top());
            st.pop();
            // result.pop_back();
        }
        reverse(result.begin(),result.end());
        return result;
    }
};