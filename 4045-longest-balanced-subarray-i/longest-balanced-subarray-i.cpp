class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n=nums.size();
        int maxLen =0;

        for(int i=0;i<n;i++){

            unordered_set<int>even;
            unordered_set<int>odd;

            for(int j=i;j<n;j++){
                int num=nums[j];
            if(num%2==0)
                even.insert(num);
            else
                odd.insert(num);
            if(even.size()==odd.size())
                maxLen = max(maxLen ,j-i+1);
            }
        }
    return maxLen;
    }
};