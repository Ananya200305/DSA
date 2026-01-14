class Solution {
  public:
    int merge(vector<int> &arr, int low, int mid, int high){
        int j = mid + 1;
        
        int count = 0;
        
        for(int i = low; i <= mid; i++){
            while(j <= high && arr[i] > arr[j]){
                j++;
            }
            
            count += (j - (mid+1));
        }
        
        int left = low;
        int right = mid + 1;
        
        vector<int>temp;
        
        while(left <= mid && right <= high){
            if(arr[left] <= arr[right]){
                temp.push_back(arr[left++]);
            }else{
                temp.push_back(arr[right++]);
            }
        }
        
        while(left <= mid){
            temp.push_back(arr[left++]);
        }
        
        while(right <= high){
            temp.push_back(arr[right++]);
        }
        
        for(int i = low ; i <= high; i++){
            arr[i] = temp[i - low];
        }
        
        return count;
    }
    int mergeSort(vector<int> &arr, int low, int high){
        if(low >= high) return 0;
        
        int mid = low + (high - low)/2;
        
        int count = 0;
        
        count += mergeSort(arr, low, mid);
        count += mergeSort(arr, mid+1, high);
        count += merge(arr, low, mid, high);
        
        return count;
    }
    int inversionCount(vector<int> &arr) {
        return mergeSort(arr, 0, arr.size()-1);
    }
};