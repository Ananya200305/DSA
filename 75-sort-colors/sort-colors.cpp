class Solution {
public:
    void sortColors(vector<int>& nums) {
        const char red = 0;
        const char white = 1;
        const char blue = 2;

        int l = 0;
        int m = 0;
        int r = nums.size() - 1;

        while(m <= r){
            switch(nums[m]){
                case red:
                    swap(nums[l],nums[m]);
                    l++;
                    m++;
                    break;
                case white :
                    m++;
                    break;
                case blue :
                    swap(nums[m], nums[r]);
                    r--;
                    break;
            }
        }
    }
};