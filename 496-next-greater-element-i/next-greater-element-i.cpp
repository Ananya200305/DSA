class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int>nge;
        stack<int>st;
        vector<int>ans;

        for(int i = nums2.size()-1; i>= 0; i--){
            while(!st.empty() && nums2[i] >= st.top()){
                st.pop();
            }

            if(st.empty()){
                nge[nums2[i]] = -1;
            }else{
                nge[nums2[i]] = st.top();
            }

            st.push(nums2[i]);
        }

        for(int num : nums1){
            ans.push_back(nge[num]);
        }

        return ans;
    }
};