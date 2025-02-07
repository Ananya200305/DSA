class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int, int> ballcolor;
        unordered_map<int, int> colorfreq;

        int n = queries.size();
        vector<int> ans(n);

        for(int i = 0; i < n; i++){
            int ball = queries[i][0];
            int color = queries[i][1];

            if(ballcolor.find(ball) != ballcolor.end()){
                int alreadyExisted = ballcolor[ball];
                colorfreq[alreadyExisted]--;

                if(colorfreq[alreadyExisted] == 0){
                    colorfreq.erase(alreadyExisted);
                }
            }

            ballcolor[ball] = color;
            colorfreq[color]++;
            ans[i] = colorfreq.size();
        }
        return ans;
    }
};