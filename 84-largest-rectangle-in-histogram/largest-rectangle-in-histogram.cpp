class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxArea = 0;
        heights.push_back(0);
        stack<int>st;

        for(int i = 0; i < heights.size(); i++){
            while(!st.empty() && heights[st.top()] > heights[i]){
                int h = heights[st.top()];
                st.pop();
                int w = st.empty() ? i : i - st.top() - 1;
                maxArea = max(maxArea, h*w);
            }
            st.push(i);
        }

        return maxArea;
    }
};