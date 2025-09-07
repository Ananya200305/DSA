class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int>res;
        int i = 1;
        if(n % 2 == 0){
            while(res.size() != n){
                res.push_back(i);
                res.push_back(-i);
                i++;
            }
        }else{
            res.push_back(0);
            while(res.size() != n){
                res.push_back(i);
                res.push_back(-i);
                i++;
            }
        }

        return res;
    }
};