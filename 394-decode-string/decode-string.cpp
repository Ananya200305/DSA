class Solution {
public:
    string decodeString(string s) {
        stack<char>st;

        for(int i = 0 ;  i < s.size(); i++){
            if(s[i] == ']'){
                string temp;

                while(!st.empty() && isalpha(st.top())){
                    temp.push_back(st.top());
                    st.pop();
                }

                reverse(temp.begin(), temp.end());

                if(!st.empty() && st.top() == '[') st.pop();

                string numStr = "";
                while(!st.empty() && isdigit(st.top())){
                    numStr.push_back(st.top());
                    st.pop();
                }

                reverse(numStr.begin(), numStr.end());

                int num = numStr.empty() ? 1 : stoi(numStr);

                for(int k = 0; k < num; k++){
                    for(char c : temp){
                        st.push(c);
                    }
                }

            }else{
                st.push(s[i]);
            }
        }

        string res = "";

        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }

        reverse(res.begin(), res.end());

        return res;
    }
};