class Solution {
public:
    int minDeletion(string s, int k) {
        unordered_map<char,int>mp;
        int result = 0;

        for(char ch : s){
            mp[ch]++;
        }

        if(mp.size() <= 0){
            return 0;
        }

        vector<int> freq;
        for(auto& entry : mp){
            freq.push_back(entry.second);
        }

        sort(freq.begin(), freq.end());

        int todel = mp.size() - k;

        for(int i = 0 ; i < todel; i++){
            result += freq[i];
        }

        return result;
    }
};