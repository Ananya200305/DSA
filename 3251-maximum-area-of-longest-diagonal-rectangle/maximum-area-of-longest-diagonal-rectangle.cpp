class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int maxDiag = 0;
        int area = 0;

        for(int i = 0 ; i < dimensions.size(); i++){
            int length = dimensions[i][0];
            int width = dimensions[i][1];

            int diag = length*length + width*width;
            int currArea = length * width;

            if(diag > maxDiag || (diag == maxDiag && currArea > area)){
                maxDiag = diag;
                area = currArea;
            }
        }

        return area;
    }
};