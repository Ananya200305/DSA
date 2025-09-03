class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        unordered_map<int, int>nge;
        vector<int>ans;
        stack<int>st;

        for(int i = nums2.size()-1; i >= 0; i--){
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

        for(int i = 0; i < n ; i++){
            ans.push_back(nge[nums1[i]]);
        }

        return ans;
    }
};