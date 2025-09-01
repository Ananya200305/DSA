class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();

        int prod = nums[0];
        int maxProd = nums[0];

        for(int i = 1; i < nums.size(); i++){
            if(prod == 0){
                prod = nums[i];
            }else{
                prod = prod * nums[i];
            }
            maxProd = max(maxProd, prod);
        }

        prod = nums[n-1];
        maxProd = max(maxProd, prod);

        for(int i = n-2; i >= 0; i--){
            if(prod == 0){
                prod = nums[i];
            }else{
                prod = prod * nums[i];
            }
            maxProd = max(maxProd, prod);
        }

        return maxProd;
    }
};