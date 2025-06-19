class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> st;
        int n = nums.size();
        int i = 2*n-1;
        vector<int> nge(n);

        while(i >= 0){
            while(!st.empty() && st.top() <= nums[i%n]){
                st.pop();
            }
            if(i < n){
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