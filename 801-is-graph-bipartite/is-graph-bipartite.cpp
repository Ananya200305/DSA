class Solution {
public:
    //bfs

    // bool check(int start, vector<vector<int>>& graph, vector<int>& color){
    //     queue<int>q;
    //     q.push(start);
    //     color[start] = 0;

    //     while(!q.empty()){
    //         int node = q.front();
    //         q.pop();

    //         for(auto it : graph[node]){
    //             if(color[it] == -1){
    //                 color[it] = !color[node];
    //                 q.push(it);
    //             }else if(color[it] == color[node]){
    //                 return false;
    //             }
    //         }
    //     }

    //     return true;
    // }

    // dfs
    bool check(int start, int col, vector<vector<int>>& graph, vector<int>& color){
        color[start] = col;

        for(auto it : graph[start]){
            if(color[it] == -1){
                if(!check(it, !col, graph, color)) return false;
            }else if(color[it] == color[start]){
                return false;
            }
        }

        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        vector<int>color(graph.size(), -1);

        // for(int i = 0 ; i < graph.size(); i++){
        //     if(color[i] == -1){
        //         if(!check(i, graph, color)){
        //             return false;
        //         }
        //     }
        // }

        for(int i = 0 ; i < graph.size(); i++){
            if(color[i] == -1){
                if(!check(i, 0, graph, color)){
                    return false;
                }
            }
        }

        return true;
    }
};