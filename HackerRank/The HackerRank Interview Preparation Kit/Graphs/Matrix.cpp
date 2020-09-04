// Use MST concept. sort from big to small. build big and use total - big
// because each machine can build as max as possible tree.
// O(MlogM).

const int N = 1e5+5; 
int p[N];

int find(int x){
    return p[x] < 0 ? x : p[x] = find(p[x]); 
}

// Complete the minTime function below.
int minTime(vector<vector<int>> roads, vector<int> machines) {
    memset(p, -1, sizeof p);
    sort(roads.begin(), roads.end(), [](vector<int> &a, vector<int> &b){
        return a[2] > b[2];
    });
    unordered_set<int> st(machines.begin(), machines.end());
    int total = 0, build = 0;
    for(auto &e: roads){
        total += e[2];
        int a = find(e[0]), b = find(e[1]);
        if(st.count(a) && st.count(b)) continue;
        if(a == b) continue;
        build += e[2];
        if(st.count(a)){
            p[b] = a;
        }
        else{
            p[a] = b;
        }
    }
    return total - build;
}

// Solution 2 dp, O(N).
