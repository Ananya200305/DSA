class Solution {
  public:
    int minPlatform(vector<int>& arr, vector<int>& dep) {
        int n = arr.size();
        int m = dep.size();
        
        sort(arr.begin(), arr.end());
        sort(dep.begin(), dep.end());
        
        int i = 0;
        int j = 0;
        
        int usingPlatform = 0;
        int maxUsed = 0;
        
        while(i < n && j < m){
            if(arr[i] <= dep[j]){
                i++;
                usingPlatform++;
                maxUsed = max(maxUsed, usingPlatform);
            }else{
                j++;
                usingPlatform--;
            }
        }
        
        return maxUsed;
    }
};
