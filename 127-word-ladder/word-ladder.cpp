class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string, int>> q;

        q.push({beginWord, 1});

        unordered_set<string>set(wordList.begin(), wordList.end());
        set.erase(beginWord);

        while(!q.empty()){
            string word = q.front().first;
            int step = q.front().second;

            q.pop();

            if(word == endWord) return step;

            for(int i = 0; i < word.size(); i++){
                char original = word[i];
                for(char c = 'a'; c <= 'z'; c++){
                    word[i] = c;

                    if(set.find(word) != set.end()){
                        set.erase(word);
                        q.push({word, step+1});
                    }
                }
                word[i] = original;
            }
        }

        return 0;
    }
};