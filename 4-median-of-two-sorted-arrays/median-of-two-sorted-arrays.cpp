class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        // Brute Force
        // int p1 = 0;
        // int p2 = 0;
        // int size = nums1.size() + nums2.size();
        // vector<int> arr(size);
        // int i = 0;
        // float median = 0;

        // while(p1 < nums1.size() && p2 < nums2.size()){
        //     if(nums1[p1] <= nums2[p2]){
        //         arr[i] = nums1[p1];
        //         i++;
        //         p1++;
        //     }else{
        //         arr[i] = nums2[p2];
        //         i++;
        //         p2++;
        //     }
        // }

        // while(p1 < nums1.size()){
        //     arr[i] = nums1[p1];
        //     i++;
        //     p1++;
        // }

        // while(p2 < nums2.size()){
        //     arr[i] = nums2[p2];
        //     i++;
        //     p2++;
        // }

        // int low = 0;
        // int high = arr.size() - 1;
        // int mid = low + (high - low)/2;

        // if(arr.size()%2 == 0){
        //     median = (arr[mid] + arr[mid+1])/2.0;
        // }else{
        //     median = arr[mid];
        // }
        // return median;

        // Better Approach (Not storing the array)

        int p1 = 0;
        int p2 = 0;

        int size = nums1.size() + nums2.size();

        int index1 = size/2;
        int index1el = -1;
        int index2 = (size/2) - 1;
        int index2el = -1;

        int count = 0;

        while(p1 < nums1.size() && p2 < nums2.size()){
            if(nums1[p1] < nums2[p2]){
                if(count == index1) index1el = nums1[p1];
                if(count == index2) index2el = nums1[p1];
                count++;
                p1++;
            }else{
                if(count == index1) index1el = nums2[p2];
                if(count == index2) index2el = nums2[p2];
                count++;
                p2++;
            }
        } 

        while(p1 < nums1.size()){
            if(count == index1) index1el = nums1[p1];
            if(count == index2) index2el = nums1[p1];
            count++;
            p1++;
        }
        while(p2 < nums2.size()){
            if(count == index1) index1el = nums2[p2];
            if(count == index2) index2el = nums2[p2];
            count++;
            p2++;
        }

        if(size%2 != 0){
            return index1el;
        }

        return (double)(index1el + index2el)/ 2.0;
    }
};