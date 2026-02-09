class Solution {
  public:
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        int n = val.size();
        
        vector<pair<double, int>>map;
        
        for(int i = 0; i < n; i++){
            double cap = (double)val[i]/wt[i];
            map.push_back({cap,i});
        }
        
        sort(map.rbegin(), map.rend());
        
        int currWt = 0;
        double maxCap = 0.0;
        
        for(auto & p : map){
            int i = p.second;
            
            if(currWt + wt[i] <= capacity){
                currWt = currWt + wt[i];
                maxCap = maxCap + val[i];
            }else{
                int remain = capacity - currWt;
                maxCap += val[i] * ((double)(remain)/wt[i]);
                break;
            }
        }
        
        return round(maxCap * 1000000.0)/1000000.0;
    }
};
