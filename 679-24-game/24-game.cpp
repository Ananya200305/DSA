class Solution {
const double mod = 1e-6; 
public:
    bool dfs(vector<double>& nums){
        if(nums.size() == 1){
            return fabs(nums[0] - 24.0) < mod;
        }

        for(int i = 0; i < nums.size(); i++){
            for(int j = 0; j < nums.size(); j++){
                if(i == j) continue;

                vector<double> next;
                for(int k = 0; k < nums.size(); k++){
                    if(k != i && k != j) next.push_back(nums[k]);
                }
                for(double val : compute(nums[i], nums[j])){
                    next.push_back(val);
                    if(dfs(next)) return true;
                    next.pop_back();
                }
            }
        }
        return false;
    }
    vector<double> compute(double i, double j){
        vector<double> res;
        res.push_back(i+j);
        res.push_back(i-j);
        res.push_back(j-i);
        res.push_back(i*j);
        if(fabs(j) > mod) res.push_back(i/j);
        if(fabs(i) > mod) res.push_back(j/i);
        return res;
    }
    bool judgePoint24(vector<int>& cards) {
        vector<double>nums;
        for(int n : cards){
            nums.push_back((double)n);
        }
        return dfs(nums);
    }
};