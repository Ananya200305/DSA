class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int> mp(10,0);

        for(int i = 0; i < digits.size(); i++){
            mp[digits[i]]++;
        }

        vector<int> res;

        for(int i = 1; i <= 9; i++){
            if(mp[i] == 0) continue;
            mp[i]--;
            for(int j = 0; j <= 9; j++){
                if(mp[j] == 0) continue;
                mp[j]--;
                for(int k = 0; k <= 9; k=k+2){
                    if(mp[k] == 0) continue;
                    mp[k]--;
                    res.push_back(100*i + 10*j + k);
                    mp[k]++;
                }
                mp[j]++;
            }
            mp[i]++;
        }

        return res;
    }
};