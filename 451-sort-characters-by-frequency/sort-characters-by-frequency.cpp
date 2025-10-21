class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int>freq;

        for(int i = 0 ; i < s.size(); i++){
            freq[s[i]]++;
        }

        vector<pair<int , char>> freqArr;
        for(auto& p: freq){
            int f = p.second;
            int c = p.first;
            freqArr.push_back({f, c});
        }

        sort(freqArr.rbegin(), freqArr.rend());

        string res = "";
        
        for(auto r : freqArr){
            res.append(r.first, r.second);
        }

        return res;

    }
};