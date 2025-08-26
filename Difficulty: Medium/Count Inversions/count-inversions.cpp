class Solution {
  public:
    int merge(vector<int> &arr, int left, int mid, int right){
        vector<int>temp;
        int count = 0;
        
        int low = left;
        int high = mid+1;
        
        while(low <= mid && high <= right){
            if(arr[low] <= arr[high]){
                temp.push_back(arr[low++]);
            }else{
                temp.push_back(arr[high++]);
                count += (mid - low + 1);
            }
        }
        
        while(low <= mid){
            temp.push_back(arr[low++]);
        }
        
        while(high <= right){
            temp.push_back(arr[high++]);
        }
        
        for(int i = left; i <= right; i++){
            arr[i] = temp[i-left];
        }
        
        return count;
    }
    
    int mergeSort(vector<int> &arr, int left, int right){
        if(left >= right) return 0;
        
        int count = 0;
        
        int mid = left + (right - left)/2;
        
        count += mergeSort(arr, left, mid);
        count += mergeSort(arr, mid+1, right);
        count += merge(arr, left, mid, right);
        
        return count;
    }
    int inversionCount(vector<int> &arr) {
        return mergeSort(arr,0,arr.size()-1);
    }
};