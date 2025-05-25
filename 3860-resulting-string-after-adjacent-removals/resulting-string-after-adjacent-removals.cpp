class Solution {
public:
    string resultingString(string s) {
        string stack;

        for(char c : s){
            if(!stack.empty()){
                char top = stack.back();
                if(abs(c - top) == 1 || abs(c - top) == 25){
                    stack.pop_back();
                    continue;
                }
            }
            stack.push_back(c);
        }

        return stack;
    }
};