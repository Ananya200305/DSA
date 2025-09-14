class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<bool>count(26, false);

        for(char c : sentence){
            count[c - 'a'] = true;
        }

        for(bool b : count){
            if(b == false) return false;
        }

        return true;
    }
};