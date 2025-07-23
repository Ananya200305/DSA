class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int score = 0;

        stack<char>st;

        if(x > y){
            for(int i = 0; i < s.size(); i++){
                if(!st.empty() && s[i] == 'b' && st.top() == 'a'){
                    score += x;
                    st.pop();
                }else{
                    st.push(s[i]);
                }
            }

            string temp = "";
            
            while(!st.empty()){
                temp += st.top();
                st.pop();
            }

            reverse(temp.begin(), temp.end());

            for(int i = 0; i < temp.size(); i++){
                if(!st.empty() && temp[i] == 'a' && st.top() == 'b'){
                    score += y;
                    st.pop();
                }else{
                    st.push(temp[i]);
                }
            }

        }else{
            for(int i = 0; i < s.size(); i++){
                if(!st.empty() && s[i] == 'a' && st.top() == 'b'){
                    score += y;
                    st.pop();
                }else{
                    st.push(s[i]);
                }
            }

            string temp = "";
            
            while(!st.empty()){
                temp += st.top();
                st.pop();
            }

            reverse(temp.begin(), temp.end());

            for(int i = 0; i < temp.size(); i++){
                if(!st.empty() && temp[i] == 'b' && st.top() == 'a'){
                    score += x;
                    st.pop();
                }else{
                    st.push(temp[i]);
                }
            }
        }
        return score;
    }
};