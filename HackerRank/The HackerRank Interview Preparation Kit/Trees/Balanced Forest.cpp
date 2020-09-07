// O(N). Not my level. too hard.
// so many math...

#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);
const int N = 5e4+5;
vector<int> g[N];
long total, res;
unordered_set<long> done, path;
vector<long> sum;

void dfs(int u = 0, int p = -1){
    for(int v: g[u]){
        if(v != p){
            dfs(v, u);
            sum[u] += sum[v];
        }
    }
}

void solve(int u = 0, int p = -1){
    long cur = sum[u];
    //cout << u << " " << cur << "\n";
    long ans[2] = {3 * cur - total, (total-cur)/2 - cur};
    if(ans[0] >= 0){
        if(done.count(cur) || done.count(total - 2*cur)
            || path.count(2*cur) || path.count(total - cur)){
            res = min(res, ans[0]);
        }
    }
    if((total - cur)%2 == 0 && ans[1] >= 0){
        long tmp = (total-cur)/2;
        if(done.count(tmp) || path.count(tmp + cur)){
            res = min(res, ans[1]);
        }
    }
    cout << "after: " << u << " res:" << res << "\n";
    path.insert(cur);
    for(int v: g[u]){
        if(v != p){
            solve(v, u);
        }
    }
    path.erase(cur);
    done.insert(cur);
}

void init(int n){
    for(int i = 0; i < n; ++i) g[i].clear();
    total = 0;
    done.clear();
    path.clear();
}

// Complete the balancedForest function below.
long balancedForest(vector<long> c, vector<vector<int>> edges) {
    int n = c.size();
    sum = c;
    init(n);
    for(const auto&e: edges){
        g[e[0]-1].push_back(e[1]-1);
        g[e[1]-1].push_back(e[0]-1);
    }
    dfs();
    total = res = sum[0];
    solve();
    return res == total ? -1 : res;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        string c_temp_temp;
        getline(cin, c_temp_temp);

        vector<string> c_temp = split_string(c_temp_temp);

        vector<long> c(n);

        for (int i = 0; i < n; i++) {
            int c_item = stoi(c_temp[i]);

            c[i] = c_item;
        }

        vector<vector<int>> edges(n - 1);
        for (int i = 0; i < n - 1; i++) {
            edges[i].resize(2);

            for (int j = 0; j < 2; j++) {
                cin >> edges[i][j];
            }

            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        long result = balancedForest(c, edges);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
