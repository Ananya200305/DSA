
class Solution {
  public:
    void swapKth(vector<int> &arr, int k) {
        int n = arr.size();
        
        swap(arr[k-1], arr[n-k]);
    }
};
