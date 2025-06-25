class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        long long sum = 0;
        vector<int> nse(n,n);
        vector<int> pse(n,-1);
        stack<int>st;
        const int MOD = 1e9 + 7;

        for(int i = 0; i < n; i++){
            while(!st.empty() && arr[st.top()] >= arr[i]){
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
            while(!st.empty() && arr[st.top()] > arr[i]){
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
            long long contain = (nse[i]-i) * (i - pse[i]);
            sum = (sum + (contain * arr[i])%MOD)%MOD;
        }
        
        return sum;
    }
};