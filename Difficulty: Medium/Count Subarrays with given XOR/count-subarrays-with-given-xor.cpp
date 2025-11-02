class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
        unordered_map<int, int>map;
        map[0] = 1;
        int x = 0;
        int count = 0;
        
        for(int i = 0; i < arr.size(); i++){
            x = x ^ arr[i];
            int rem = x ^ k;
            
            if(map.find(rem) != map.end()){
                count += map[rem];
            }
            
            map[x]++;
        }
        
        return count;
    }
};