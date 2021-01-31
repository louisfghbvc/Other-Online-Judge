
// O(m2^k). simulate.

#include <bits/stdc++.h>

#define Fast cin.tie(0), ios::sync_with_stdio(0)
#define All(x) x.begin(), x.end()
#define louisfghbvc int t; cin >> t; while(t--)
#define sz(x) (int)(x).size()
using namespace std;
typedef long long LL;
typedef pair<LL, LL> ii;
typedef vector<LL> vi;

template<typename T> istream& operator>>(istream &is, vector<T> &v) { for(auto &it : v) is >> it; return is; }
template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << '{'; string sep = ""; for(const auto &x : v) os << sep << x, sep = ", "; return os << '}'; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }

void dbg_out() { cerr << " end.\n"; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

const int N = 3e5+5;
const int mod = 1e9+7;
/**
Read problem statement carefully
**/
vector<ii> arr;
vector<ii> can;
int n, m, k;
int mx = 0;
void dfs(int i, multiset<int> st){
    if(i == k){
        int res = 0;
        for(int j = 0; j < m; ++j){
            if(st.count(arr[j].first) && st.count(arr[j].second)) res++;
        }
        mx = max(mx, res);
        return;
    }

    st.insert(can[i].first);
    dfs(i+1, st);
    st.erase(st.find(can[i].first));

    st.insert(can[i].second);
    dfs(i+1, st);
}

void solve(){

    cin >> n >> m;

    for(int i = 0, a, b; i < m; ++i){
        cin >> a >> b;
        arr.push_back({a, b});
    }
    cin >> k;

    for(int i = 0, a, b; i < k; ++i){
        cin >> a >> b;
        can.push_back({a, b});
    }
    multiset<int> mp;
    dfs(0, mp);
    cout << mx << "\n";
}

int main()
{
    Fast;
    //louisfghbvc
        solve();
    return 0;
}

/**
enjoy the problem.
**/
