class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n+1);

        for(auto t : times){
            adj[t[0]].push_back({t[1], t[2]});
        }

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({0, k});

        vector<int> dist(n+1, INT_MAX);
        dist[k] = 0;

        while(!pq.empty()){
            auto top = pq.top();
            int time = top[0];
            int node = top[1];

            pq.pop();

            if(time > dist[node]) continue;

            for(auto neigh : adj[node]){
                int stop = neigh.first;
                int t = neigh.second;

                if(dist[node] + t < dist[stop]){
                    dist[stop] = dist[node] + t;
                    pq.push({dist[stop], stop});
                }
            }
        }

        int ans = 0;

        for(int i = 1 ; i <= n; i++){
            if(dist[i] == INT_MAX) return -1;
            ans = max(ans, dist[i]);
        }

        return ans;
    }
};