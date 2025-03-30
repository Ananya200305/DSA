class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();

        if(n == 0) return 0;

        int max_product = nums[0];
        int current = nums[0];

        for(int i = 1; i < n; i++){
            if(current == 0){
                current = nums[i];
            }else{
                current = current * nums[i];
            }
            max_product = max(max_product, current);
        }

        current = nums[n-1];
        max_product = max(max_product, current);

        for(int i = n-2; i >= 0; i--){
            if(current == 0){
                current = nums[i];
            }else{
                current = current * nums[i];
            }
            max_product = max(max_product, current);
        }

        return max_product;
    }
};