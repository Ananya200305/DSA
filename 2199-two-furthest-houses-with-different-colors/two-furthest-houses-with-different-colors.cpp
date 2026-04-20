class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n = colors.size();
        int ans = 0;

        for(int i = 0 ; i < colors.size(); i++){
            if(colors[0] != colors[i]){
                ans = max(i, ans);
            }
            if(colors[i] != colors[n-1-i]){
                ans = max(ans, n-1-i);
            }
        }

        return ans;
    }
};