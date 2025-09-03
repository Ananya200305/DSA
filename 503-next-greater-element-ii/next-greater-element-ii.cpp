class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        int i = 2*n-1;
        vector<int>nge(n);
        stack<int>st;

        while(i >= 0){

            if(i < n){
                while(!st.empty() && nums[i%n] >= st.top()){
                    st.pop();
                }
                if(st.empty()){
                    nge[i] = -1;
                }else{
                    nge[i] = st.top();
                }
            }

            st.push(nums[i%n]);
            i--;
        }

        return nge;
    }
};