class Solution {
public:
    vector<vector<string>> res;
    vector<string> curr;

    bool check(string &s, int left, int right){
        while(left < right){
            if(s[left++] != s[right-- ]){
                return false;
            }
        }
        return true;
    }

    void backtrack(string &s, int start){
        if(start == s.length()){
            res.push_back(curr);
            return;
        }

        for(int end = start ; end < s.length(); end++){
            if(check(s,start,end)){
                curr.push_back(s.substr(start,end-start+1));
                backtrack(s,end+1);
                curr.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        backtrack(s,0);
        return res;
    }
};