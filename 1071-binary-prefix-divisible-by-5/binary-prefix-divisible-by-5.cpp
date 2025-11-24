class Solution {
public:
    int helper(string &n){
        long long value = 0;
        for(char c : n){
            int bit = c - '0';
            value = (value * 2 + bit) % 5;
        }
        return value;
    }
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        string check = "";
        vector<bool>res;
        for(int i = 0; i < nums.size(); i++){
            check = check + char(nums[i] + '0');
            if(helper(check) == 0){
                res.push_back(true);
            }else{
                res.push_back(false);
            }
        }

        return res;
    }
};