class Solution {
private:
    int histogram(vector<int>& height){
        height.push_back(0);
        int mArea = 0;
        stack<int>st;

        for(int i = 0; i < height.size(); i++){
            while(!st.empty() && height[i] < height[st.top()]){
                int h = height[st.top()];
                st.pop();
                int w = st.empty() ? i : i - st.top() - 1;
                int area = h * w;
                mArea = max(mArea, area);
            }
            st.push(i);
        }
        return mArea;
    }
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty() || matrix[0].empty()){
            return 0;
        }

        int row = matrix.size();
        int col = matrix[0].size();

        int maxArea = 0;

        vector<int>height(col,0);

        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(matrix[i][j] == '1'){
                    height[j] += 1;
                }else{
                    height[j] = 0;
                }
            }

            maxArea = max(maxArea, histogram(height));
        }

        return maxArea;
    }
};