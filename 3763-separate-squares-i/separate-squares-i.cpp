class Solution {
public:
    double areaBelow(vector<vector<int>>& squares, double h){
        double sum = 0;
        for(auto& sq : squares){
            int x = sq[0];
            int y = sq[1];
            double l = sq[2];

            if(h <= y) continue;
            if(h >= (y+l)){
                sum += (l*l);
            }else{
                sum += (h-y)*l; 
            }
        }
        return sum;
    }
    double separateSquares(vector<vector<int>>& squares) {
        double y_min = INT_MAX;
        double y_max = INT_MIN;
        double totalArea = 0;

        for(auto& sq : squares){
            int x = sq[0];
            int y = sq[1];
            double l = sq[2];

            y_min = min(y_min, (double)y);
            y_max = max(y_max, (double)y+l);
            totalArea += (l*l);
        }

        double low = y_min;
        double high = y_max;
        while(high - low > 1e-5){
            double midLine = low + (high - low)/2;

            if(areaBelow(squares, midLine) < totalArea/2){
                low = midLine;
            }else{
                high = midLine;
            }
        }
        return low;
    }
};