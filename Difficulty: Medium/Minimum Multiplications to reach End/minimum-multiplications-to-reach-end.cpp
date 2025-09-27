// User function Template for C++

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        
        if(start == end) return 0;
        
        queue<pair<int, int>>q;
        q.push({start,0});
        
        vector<int> dist(100000, INT_MAX);
        dist[start] = 0;
        
        while(!q.empty()){
            int node = q.front().first;
            int steps = q.front().second;
            
            q.pop();
            
            for(int it : arr){
                int next = (node * it) % 100000;
                int newdist = steps + 1;
                
                if(newdist < dist[next]){
                    dist[next] = newdist;
                    
                    if(next == end) return steps + 1;
                    q.push({next, steps+1});
                }
            }
        }
        
        return -1;
    }
};
