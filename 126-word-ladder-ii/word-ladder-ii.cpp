class Solution {
public:
    unordered_map<string ,int> map;
    vector<vector<string>> ans;
    string b;

    void dfs(string word, vector<string>& seq){
        if(word == b){
            reverse(seq.begin(), seq.end());
            ans.push_back(seq);
            reverse(seq.begin(), seq.end());
            return;
        }

        int steps = map[word];

        for(int i = 0 ; i < word.size(); i++){
            char original = word[i];
            for(char c = 'a'; c <= 'z'; c++){
                word[i] = c;
                if(map.find(word) != map.end() && map[word] + 1 == steps){
                    seq.push_back(word);
                    dfs(word,seq);
                    seq.pop_back();
                }
            }
            word[i] = original;
        }

    }

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        // queue<vector<string>> q;
        // unordered_set<string>set(wordList.begin(), wordList.end());
        // vector<string> useOnLevel;
        // int level = 0;
        // vector<vector<string>> ans;

        // if(set.find(endWord) == set.end()) return {};

        // q.push({beginWord});

        // useOnLevel.push_back(beginWord);

        // while(!q.empty()){
        //     vector<string> words = q.front();
        //     q.pop();
        //     if(words.size() > level){
        //         level++;
        //         for(auto it : useOnLevel){
        //             set.erase(it);
        //         }
        //     }

        //     string w = words.back();

        //     if(w == endWord){
        //         if(ans.size() == 0){
        //             ans.push_back(words);
        //         }else if(ans[0].size() == words.size()){
        //             ans.push_back(words);
        //         }
        //     }

        //     for(int i = 0 ; i < w.size(); i++){
        //         char original = w[i];
        //         for(char c = 'a'; c <= 'z'; c++){
        //             w[i] = c;
        //             if(set.count(w) > 0){
        //                 words.push_back(w);
        //                 q.push(words);
        //                 useOnLevel.push_back(w);
        //                 words.pop_back();
        //             }
        //         }
        //         w[i] = original;
        //     }
        // }
        // return ans;

        unordered_set<string> set(wordList.begin(), wordList.end());
        queue<string>q;
        b = beginWord;
        q.push(beginWord);
        map[beginWord] = 1;
        int sz = beginWord.size();
        set.erase(beginWord);

        while(!q.empty()){
            string word = q.front();
            int step = map[word];
            q.pop();
            if(word == endWord) break;
            for(int i = 0 ; i < word.size(); i++){
                char original = word[i];
                for(char c = 'a'; c <= 'z'; c++){
                    word[i] = c;
                    if(set.count(word)){
                        q.push(word);
                        set.erase(word);
                        map[word] = step+1;
                    }
                }
                word[i] = original;
            }
        }

        if(map.find(endWord) != map.end()){
            vector<string>seq;
            seq.push_back(endWord);
            dfs(endWord, seq);
        }

        return ans;
    }
};