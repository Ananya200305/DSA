class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        int i = 2*n-1;
        vector<int> nge(n);
        stack<int>st;

        while(i >= 0){
            while(!st.empty() && nums[st.top()] <= nums[i%n]){
                st.pop();
            }

            if(i < n){
                if(st.empty()){
                    nge[i] = -1;
                }else{
                    nge[i] = nums[st.top()];
                }
            }

            st.push(i%n);
            i--;
        }
        return nge;
    }
};