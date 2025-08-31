class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> v1(26,0);
        vector<int> v2 (26,0);

        for(char & ch : p){
            v1[ch - 'a']++;
        }

        vector<int>res;
        int i = 0; 
        int j = 0;
        int n = p.size();

        while(j < s.size()){
            if(j - i + 1 > n){
                v2[s[i] - 'a']--;
                i++;
            } 

            v2[s[j] - 'a']++;

            if(j >= n-1){
                if(v1 == v2) res.push_back(i);
            }

            j++;
        }

        return res;
    }
};