class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>>map;
        vector<vector<string>> res;
        string temp;

        for(int i = 0 ; i < strs.size(); i++){
            temp = strs[i];
            sort(begin(temp), end(temp));
            map[temp].push_back(strs[i]);
        }

        for(auto& p : map){
            res.push_back(p.second);
        }

        return res;
    }
};