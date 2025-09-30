class Solution {
public:
    int romanToInt(string s) {
        map<int, int> pair;

        pair.insert({'I', 1});
        pair.insert({'V', 5});
        pair.insert({'X', 10});
        pair.insert({'L', 50});
        pair.insert({'C', 100});
        pair.insert({'D', 500});
        pair.insert({'M', 1000});

        int ans = 0;

        for(int i = 0; i < s.size(); i++){
            if(pair[s[i]] >= pair[s[i+1]]){
                ans += pair[s[i]];
            }else{
                ans -= pair[s[i]];
            }
        }

        return ans;
    }
};