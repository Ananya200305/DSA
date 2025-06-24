class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        // int n = heights.size();
        // vector<int>nse(n);
        // vector<int>pse(n);
        // stack<int>st;

        // for(int i = 0; i < n; i++){
        //     while(!st.empty() && heights[i] <= heights[st.top()]){
        //         st.pop();
        //     }
        //     if(st.empty()){
        //         pse[i] = -1;
        //     }else{
        //         pse[i] = st.top();
        //     }
        //     st.push(i);
        // }

        // while(!st.empty()){
        //     st.pop();
        // }

        // for(int i = n-1; i >= 0; i--){
        //     while(!st.empty() && heights[i] <= heights[st.top()]){
        //         st.pop();
        //     }
        //     if(st.empty()){
        //         nse[i] = n;
        //     }else{
        //         nse[i] = st.top();
        //     }
        //     st.push(i);
        // }

        // int maxArea = 0;

        // for(int i = 0; i < nse.size(); i++){
        //     int width = nse[i] - pse[i] - 1;
        //     int area = heights[i] * width;
        //     maxArea = max(maxArea, area);
        // }

        // return maxArea;



        // OPTIMIZED 

        heights.push_back(0);
        stack<int>st;
        int maxArea = 0;

        for(int i = 0 ; i < heights.size(); i++){
            while(!st.empty() && heights[i] < heights[st.top()]){
                int height = heights[st.top()];
                st.pop();
                int width = st.empty() ? i : i - st.top() - 1;
                int area = height * width ;
                maxArea = max(maxArea, area);
            }
            st.push(i);
        }

        return maxArea;
    }
};