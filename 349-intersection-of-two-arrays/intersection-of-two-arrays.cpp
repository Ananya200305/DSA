class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int>map;
        unordered_set<int> ans;

        if(nums1.size() < nums2.size()){
            for(int num : nums2){
                map[num]++;
            }

            for(int n : nums1){
                if(map.find(n) != map.end()){
                    ans.insert(n);
                }
            }
        }else{
            for(int num : nums1){
                map[num]++;
            }

            for(int n : nums2){
                if(map.find(n) != map.end()){
                    ans.insert(n);
                }
            }
        }
        return vector<int>(ans.begin(), ans.end());
    }
};