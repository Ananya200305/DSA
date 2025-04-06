class Solution {
public:
    void backtrack(vector<string>& result, string current, int n){
        if(current.size() == n){
            result.push_back(current);
            return;
        }

        backtrack(result, current + "1", n);

        if(current.empty() || current.back() != '0'){
            backtrack(result,current+"0",n);
        }
    }
    vector<string> validStrings(int n) {
        vector<string> result;
        backtrack(result,"",n);
        return result;
    }
};