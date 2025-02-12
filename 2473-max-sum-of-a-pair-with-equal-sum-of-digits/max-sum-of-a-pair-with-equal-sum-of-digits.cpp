class Solution {
public:
    int sumOfDigit(int n){
        int sum = 0;
        while(n != 0){
            int last = n%10;
            sum += last;
            n = n/10;
        }
        return sum;
    }
    int maximumSum(vector<int>& nums) {
        unordered_map<int,int> map;
        int largest = -1;

        for(int i = 0; i < nums.size(); i++){
            int sod = sumOfDigit(nums[i]);
            if(map.count(sod)){
                largest = max(largest,nums[i]+map[sod]);
                if(map[sod] < nums[i]){
                    map[sod] = nums[i];
                }
            }else{
                map[sod] = nums[i];
            }
        }

        return largest;
    }
};