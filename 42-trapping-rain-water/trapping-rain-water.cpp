class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0;
        int r = height.size()-1;

        int lMax = 0;
        int rMax = 0;

        int rain = 0;

        while(l < r){
            if(height[l] < height[r]){
                if(lMax < height[l]){
                    lMax = height[l];
                }else{
                    rain += lMax - height[l];
                }
                l++;
            }else{
                if(rMax < height[r]){
                    rMax = height[r];
                }else{
                    rain += rMax - height[r];
                }
                r--;
            }
        }

        return rain;
    }
};