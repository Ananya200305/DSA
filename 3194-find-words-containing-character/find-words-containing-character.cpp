class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int> res;

        int i = 0;

        for(string word : words){
            for(char ch : word){
                if(ch == x){
                    res.push_back(i);
                    break;
                }
            }
            i++;
        }

        return res;
    }
};