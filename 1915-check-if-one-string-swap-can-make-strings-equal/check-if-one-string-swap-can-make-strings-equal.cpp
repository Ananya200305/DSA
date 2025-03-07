class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        vector<int> diff;

        for(int i = 0; i < s1.size(); i++){
            if(s1[i] != s2[i]){
                diff.push_back(i);
            }
        }
        if(diff.empty()){
            return true;
        }

        if(diff.size() == 2){
            swap(s1[diff[0]], s1[diff[1]]);
            return s1 == s2;
        }

        return false;
    }
};