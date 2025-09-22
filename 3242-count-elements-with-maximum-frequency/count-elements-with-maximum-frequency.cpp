class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> map;

        for(int num : nums){
            map[num]++;
        }

        int m = 0;

        for(auto p : map){
            m = max(m, p.second);
        }

        int total = 0;

        for(auto p : map){
            if(p.second == m){
                total += p.second;
            }
        }

        return total;
    }
};