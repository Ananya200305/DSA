class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int, int> mp;
        int maxLen = -1;

        for(int i = 0; i < arr.size(); i++){
            mp[arr[i]]++;
        }

        for(const auto& pair : mp){
            if(pair.first == pair.second){
                maxLen = max(maxLen, pair.first);
            }
        }

        return maxLen;
    }
};