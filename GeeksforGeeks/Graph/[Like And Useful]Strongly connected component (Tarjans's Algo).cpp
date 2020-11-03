#include <bits/stdc++.h>
#define N 25
using namespace std;

int n, m, cur;
vector<int> g[N];
int dfn[N], low[N];
stack<int> st;
bool inst[N];

void dfs(int u){
    dfn[u] = low[u] = ++cur;
    st.push(u);
    inst[u] = true;

    for(int i = 0; i < g[u].size(); ++i){
        int v = g[u][i];
        if(!dfn[v]){
            dfs(v);
            low[u] = min(low[u], low[v]);
        }
        else if(inst[v])
            low[u] = min(low[u], dfn[v]);
    }

    if(dfn[u] == low[u]){
        bool f = true;
        int nxt;
        do{
            nxt = st.top(); st.pop();
            inst[nxt] = false;
            if(!f)
                cout << " ";
            cout << nxt;
            f = 0;
        }while(nxt != u);
        cout << ",";
    }
}

int main() {
    int t;
    cin >> t;
    while(t--){

        cin >> n >> m;
        for(int i = 0; i < n; ++i)
            g[i].clear();
        for(int i = 0; i < m; ++i){
            int a, b;
            cin >> a >> b;
            g[a].push_back(b);
        }

        cur = 0;
        memset(dfn, 0, sizeof dfn);
        memset(low, 0, sizeof low);
        memset(inst, 0, sizeof inst);

        for(int i = 0; i < n; ++i){
            if(!dfn[i]){
                dfs(i);
            }
        }
        cout << endl;
    }
	return 0;
}
