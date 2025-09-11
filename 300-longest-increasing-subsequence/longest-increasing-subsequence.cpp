class Solution {
public:
    int binarySearch(vector<int>& res, int target){
        int left = 0;
        int right = res.size()-1;

        while(left <= right){
            int mid = left + (right - left)/2;
            if(res[mid] == target){
                return mid;
            }else if(res[mid] > target){
                right = mid - 1;
            }else{
                left = mid + 1;
            }
        }

        return left;
    }
    int lengthOfLIS(vector<int>& nums) {
        vector<int>res;

        for(int n : nums){
            if(res.empty() || res.back() < n){
                res.push_back(n);
            }else{
                int idx = binarySearch(res,n);
                res[idx] = n;
            }
        }

        return res.size();
    }
};