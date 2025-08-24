class Solution {
public:
    int longestValidParentheses(string s) {
        int count = 0;
        stack<int>st;
        st.push(-1);

        if(s.size() == 0) return 0;

        for(int i = 0; i < s.size(); i++){
            if(s[i] == '('){
                st.push(i);
            }else{
                st.pop();
                if(st.empty()){
                    st.push(i);
                }else{
                    count = max(count, i - st.top());
                }
            }
        }

        return count;
    }
};