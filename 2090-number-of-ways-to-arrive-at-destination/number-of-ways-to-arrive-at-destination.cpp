#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        const int MOD = 1e9 + 7;
        
        // Step 1: Create Adjacency List
        vector<vector<pair<int, int>>> graph(n);
        for (auto& road : roads) {
            int u = road[0], v = road[1], time = road[2];
            graph[u].push_back({v, time});
            graph[v].push_back({u, time});
        }

        // Step 2: Initialize Distance and Ways Arrays
        vector<long long> dist(n, LLONG_MAX);
        vector<int> ways(n, 0);
        dist[0] = 0;
        ways[0] = 1;

        // Step 3: Min-Heap (Priority Queue)
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        pq.push({0, 0}); // {time, node}

        // Step 4: Dijkstra's Algorithm
        while (!pq.empty()) {
            auto [curTime, node] = pq.top();
            pq.pop();

            if (curTime > dist[node]) continue;

            for (auto& [neighbor, time] : graph[node]) {
                long long newTime = curTime + time;

                // Found a shorter path
                if (newTime < dist[neighbor]) {
                    dist[neighbor] = newTime;
                    ways[neighbor] = ways[node]; // Inherit paths count
                    pq.push({newTime, neighbor});
                }
                // Found another shortest path
                else if (newTime == dist[neighbor]) {
                    ways[neighbor] = (ways[neighbor] + ways[node]) % MOD;
                }
            }
        }

        // Return the number of shortest paths to node (n-1)
        return ways[n - 1];
    }
};

