class Solution {
public:
    int maxDepth(string s) {
        int count = 0;
        vector<int> nested;
  
        for(int i = 0; i < s.length(); i++){
            if(s[i] == '('){
                count++;
                nested.push_back(count);
            }
            if(s[i] == ')'){
                count--;
            }
        }
        if (nested.empty()) {
            return 0;
        }
        int high = *max_element(nested.begin(),nested.end());
        return high;
    }
};