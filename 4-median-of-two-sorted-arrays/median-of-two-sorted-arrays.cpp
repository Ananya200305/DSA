class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int p1 = 0;
        int p2 = 0;
        int size = nums1.size() + nums2.size();
        vector<int> arr(size);
        int i = 0;
        float median = 0;

        while(p1 < nums1.size() && p2 < nums2.size()){
            if(nums1[p1] <= nums2[p2]){
                arr[i] = nums1[p1];
                i++;
                p1++;
            }else{
                arr[i] = nums2[p2];
                i++;
                p2++;
            }
        }

        while(p1 < nums1.size()){
            arr[i] = nums1[p1];
            i++;
            p1++;
        }

        while(p2 < nums2.size()){
            arr[i] = nums2[p2];
            i++;
            p2++;
        }

        int low = 0;
        int high = arr.size() - 1;
        int mid = low + (high - low)/2;

        if(arr.size()%2 == 0){
            median = (arr[mid] + arr[mid+1])/2.0;
        }else{
            median = arr[mid];
        }
        return median;
    }
};