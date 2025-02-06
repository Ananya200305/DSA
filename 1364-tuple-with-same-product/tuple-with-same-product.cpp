class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int count = 0;
        unordered_map<int,int> productPairs;
        int n = nums.size();
        
 
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int product = nums[i] * nums[j];
                count += productPairs[product] * 8;
                productPairs[product]++;
            }
        }
        return count; 
    }
};
