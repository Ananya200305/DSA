class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        double maxDiag = 0;
        int maxArea = 0;

        for(int i = 0; i < dimensions.size(); i++){
            vector<int> dimension = dimensions[i];
            double diag = sqrt((dimension[0]*dimension[0]) + (dimension[1]*dimension[1]));
            if(diag > maxDiag || (diag == maxDiag) && (dimension[0]*dimension[1]) > maxArea){
                maxDiag = diag;
                maxArea = dimension[0]*dimension[1];
            }
        }

        return maxArea;
    }
};