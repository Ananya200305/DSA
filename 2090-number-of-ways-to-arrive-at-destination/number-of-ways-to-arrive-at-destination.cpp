class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        const int MOD = 1e9+7;

        vector<vector<pair<int, int>>> adj(n);

        for(auto r : roads){
            adj[r[0]].push_back({r[1], r[2]});
            adj[r[1]].push_back({r[0], r[2]});
        }

        priority_queue<vector<long long>, vector<vector<long long>>, greater<vector<long long>>> pq;
        pq.push({0,0});

        vector<long long> dist(n, LLONG_MAX);
        dist[0] = 0;

        vector<long long> ways(n,0);
        ways[0] = 1;

        while(!pq.empty()){
            auto top = pq.top();
            pq.pop();
            long long time = top[0];
            int node = top[1];

            if(time > dist[node]) continue;

            for(auto neigh : adj[node]){
                int next = neigh.first;
                int t = neigh.second;

                if(dist[node] + t < dist[next]){
                    dist[next] = dist[node] + t;
                    ways[next] = ways[node];
                    pq.push({dist[next], next});
                }else if(dist[node] + t == dist[next]){
                    ways[next] += (ways[node]) % MOD;
                }
            }
        }

        return ways[n-1] % MOD;
    }
};

