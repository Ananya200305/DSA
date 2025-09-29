class Solution {
public:
    int binarysearch(vector<int>& res, int target){
        int l = 0 ;
        int r = res.size()-1;

        while(l <= r){
            int mid = l + (r-l)/2;
            if(res[mid] == target){
                return mid;
            }else if(res[mid] > target){
                r = mid -1;
            }else{
                l = mid + 1;
            }
        }

        return l;
    }
    int lengthOfLIS(vector<int>& nums) {
        vector<int>res;

        for(int n : nums){
            if(res.empty() || res.back() < n){
                res.push_back(n);
            }else{
                int idx = binarysearch(res, n);
                res[idx] = n;
            }
        }

        return res.size();
    }
};