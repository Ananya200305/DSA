class Solution {
public:
    long long minSub(vector<int>& nums){

        int n = nums.size();

        long long sum = 0;

        vector<int>pse(n,-1);
        vector<int>nse(n,n);

        stack<int>st;

        for(int i = 0; i < n; i++){
            while(!st.empty() && nums[st.top()] >= nums[i]){
                st.pop();
            }
            if(st.empty()){
                pse[i] = -1;
            }else{
                pse[i] = st.top();
            }
            st.push(i);
        }

        while(!st.empty()){
            st.pop();
        }

        for(int i = n-1; i >= 0; i--){
            while(!st.empty() && nums[st.top()] > nums[i]){
                st.pop();
            }
            if(st.empty()){
                nse[i] = n;
            }else{
                nse[i] = st.top();
            }
            st.push(i);
        }

        for(int i = 0; i < n; i++){
            long long container = (nse[i] - i) * (i - pse[i]);
            sum += (container * nums[i]);
        }

        return sum;
    }

    long long maxSub(vector<int>& nums){

        int n = nums.size();

        long long sum = 0;

        vector<int>pge(n,-1);
        vector<int>nge(n,n);

        stack<int>st;

        for(int i = 0; i < n; i++){
            while(!st.empty() && nums[st.top()] <= nums[i]){
                st.pop();
            }
            if(st.empty()){
                pge[i] = -1;
            }else{
                pge[i] = st.top();
            }
            st.push(i);
        }

        while(!st.empty()){
            st.pop();
        }

        for(int i = n-1; i >= 0; i--){
            while(!st.empty() && nums[st.top()] < nums[i]){
                st.pop();
            }
            if(st.empty()){
                nge[i] = n;
            }else{
                nge[i] = st.top();
            }
            st.push(i);
        }

        for(int i = 0; i < n; i++){
            long long container = (nge[i] - i) * (i - pge[i]);
            sum += (container * nums[i]);
        }

        return sum;
    }

    long long subArrayRanges(vector<int>& nums) {

        long long minSum = minSub(nums);
        long long maxSum = maxSub(nums);

        return maxSum - minSum;
    }
};