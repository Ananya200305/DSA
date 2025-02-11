class Solution {
public:
    string removeOccurrences(string s, string part) {
        // string result = "";
        // stack<char> st;
        // int i = 0;
        // for(int i = 0; i < s.length(); i++){
        //     st.push(s[i]);
            
        //     if(st.size() >= part.size()){
        //         string temp = "";
        //         stack<char> t;
        //         for(int j = 0 ; j < part.size(); j++){
        //             t.push(st.top());
        //             temp = st.top() + temp;
        //             st.pop();
        //         }

        //         if(temp != part){
        //             while(!t.empty()){
        //                 st.push(t.top());
        //                 t.pop();
        //             }
        //         }
        //     }
        // }
        // while(!st.empty()){
        //     result = st.top() + result;
        //     st.pop();
        // }
        // return result;

        while(s.length() > 0 && s.length() > s.find(part)){
            s.erase(s.find(part), part.length());
        }
        return s;
    }
};