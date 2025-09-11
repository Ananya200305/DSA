class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size() != goal.size()) return false;
        string main = s+s;
        return main.find(goal) != string::npos;
    }
};