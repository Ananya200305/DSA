class Solution {
public:
    vector<int> asteroidCollision(vector<int>& nums) {
        stack<int>st;
        vector<int> res;

        for(int i = 0 ; i < nums.size(); i++){
            if(nums[i] > 0){
                st.push(nums[i]);
            }else{
                while(!st.empty() && st.top() > 0 && abs(nums[i]) > st.top()){
                    st.pop();
                }
                if(!st.empty() && st.top() > 0 && abs(nums[i]) == st.top()){
                    st.pop();
                }else if(st.empty() || st.top() < 0){
                    st.push(nums[i]);
                }
            }
        }

        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }

        reverse(res.begin(), res.end());

        return res;
    }
};