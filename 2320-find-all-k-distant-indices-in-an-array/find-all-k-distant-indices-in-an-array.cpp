class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int> res;
        vector<int>a;

        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == key){
                a.push_back(i);
            }
        }

        for(int i = 0 ; i < nums.size(); i++){
            for(int x : a){
                if(abs(i - x) <= k){
                    res.push_back(i);
                    break;
                }
            }
        }

        return res;
    }
};