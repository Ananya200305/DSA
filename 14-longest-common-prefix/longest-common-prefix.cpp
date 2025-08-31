class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(), strs.end());

        string first = strs[0];
        string last = strs[strs.size()-1];

        int n = min(first.size(), last.size());

        int prefix = 0;

        for(int i = 0; i < n; i++){
            if(first[i] == last[i]){
                prefix++;
            }else{
                break;
            }
        }

        return first.substr(0,prefix);
    }
};