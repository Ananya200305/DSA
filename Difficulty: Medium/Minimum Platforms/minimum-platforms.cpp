class Solution {
  public:
    int minPlatform(vector<int>& arr, vector<int>& dep) {
        // code here
        int n = arr.size();
        int m = dep.size();
        
        sort(arr.begin(), arr.end());
        sort(dep.begin(), dep.end());
        
        int i = 0;
        int j = 0;
        int maxusedPlatform = 0;
        int usingPlatforms = 0;
        
        while(i < n && j < m){
            if(arr[i] <= dep[j]){
                i++;
                usingPlatforms++;
                maxusedPlatform = max(maxusedPlatform, usingPlatforms);
            }else{
                j++;
                usingPlatforms--;
            }
        }
        
        return maxusedPlatform;
    }
};
