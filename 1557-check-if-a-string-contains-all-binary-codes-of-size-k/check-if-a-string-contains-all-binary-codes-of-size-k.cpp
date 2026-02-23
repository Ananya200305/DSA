class Solution {
public:
    bool hasAllCodes(string s, int k) {
        unordered_set<string>set;

        for(int i = 0; i+k <= s.size(); i++){
            set.insert(s.substr(i, k));
        }

        return set.size() == (int)pow(2,k);
    }
};