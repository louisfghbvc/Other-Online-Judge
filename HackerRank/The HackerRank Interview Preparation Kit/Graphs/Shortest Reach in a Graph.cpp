// O(V+E). use res as visited array.
// remember the visited array is set as soon as seen not visited. same as dfs.
// otherwise, may duplicate. or more check.
// I think this should be medium.

class Graph {
    public:
        vector<vector<int>> g;
        int n;
        Graph(int n) {
            this->n = n;
            g.resize(n);
        }
    
        void add_edge(int u, int v) {
            g[u].push_back(v);
            g[v].push_back(u);
        }
    
        vector<int> shortest_reach(int start) {
            vector<int> res(n, -1);
            queue<pair<int, int>> q;
            q.push({start, 0});
            res[start] = 0;

            while(q.size()){
                auto [u, d] = q.front(); q.pop();
                for(int &v: g[u]){
                    if(res[v] == -1){ 
                        // visited set here. otherwise, may duplicate into queue.
                        res[v] = res[u] + 6;
                        q.push({v, d+1});
                    }
                }
            }

            return res;
        }
    
};
