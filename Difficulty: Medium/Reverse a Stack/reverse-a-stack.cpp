class Solution {
  public:
    void reverseStack(stack<int> &st) {
        vector<int>res;
        while(!st.empty()){
            int t = st.top();
            st.pop();
            res.push_back(t);
        }
        
        // reverse(res.begin(), res.end());
        
        for(int i = 0 ; i < res.size(); i++){
            st.push(res[i]);
        }
    }
};