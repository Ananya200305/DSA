class Solution {
public:
    int maxDifference(string s) {
        int maxfreq = 0;
        int minfreq = INT_MAX;

        vector<int> mp(26);

        for(int i = 0; i < s.size(); i++){
            mp[s[i]-'a']++;
        }

        for(int i = 0; i < 26; i++){
            if(mp[i] != 0 && mp[i] % 2 == 0){
                minfreq = min(minfreq, mp[i]);
            }else{
                maxfreq = max(maxfreq,mp[i]);
            }
        }

        return maxfreq - minfreq;
    }
};