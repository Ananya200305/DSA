class Solution {
public:
    int romanToInt(string s) {
        map<char,int> pair;
        int ans = 0;
        pair.insert({'I',1});
        pair.insert({'V',5});
        pair.insert({'X',10});
        pair.insert({'L',50});
        pair.insert({'C',100});
        pair.insert({'D',500});
        pair.insert({'M',1000});

        for(int i = 0; i < s.length(); i++){
            if(i == s.length()-1){
                ans += pair[s[i]]; 
            }else if(pair[s[i]] >= pair[s[i+1]]){
                ans += pair[s[i]];
            }else{
                ans -= pair[s[i]];
            }
        }
        return ans;
    }
};