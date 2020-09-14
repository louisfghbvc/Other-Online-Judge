// Math. abs lemma |a| + |b| => max(|a+b|, |a-b|);
// proof |a|+|b| = max( (1)a+b, (2)a-b, (3)-a+b, (4)-a-b ) => (1)(4) merge, (2)(3) merge => max(|a+b|, |a-b|)

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

void dbg_out() { cerr << "\n"; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

const int N = 2e5+5;
const int mod = 1e9+7;

void solve(){
    int n, x, y;
    cin >> n;
    vi diff[2];
    for(int i = 0; i < n; ++i){
        cin >> x >> y;
        diff[0].push_back(x+y);
        diff[1].push_back(x-y);
    }
    for(int i = 0; i < 2; ++i)
        sort(All(diff[i]));
    cout << max(diff[0].back()-diff[0][0], diff[1].back()-diff[1][0]) << "\n";
}

int main()
{
    Fast;
    //louisfghbvc{
        solve();
    //}
    return 0;
}

// Longest pair, use convell hull algorithm.
// O(NlogN) + O(K^2). the is better than gra.
// use sort of (x,y). and build lower and upper hull.
// cross LL shiiiit WA so many times.

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

void dbg_out() { cerr << "\n"; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

const int N = 2e5+5;

struct p{
    LL x, y;
    bool operator<(const p &p2) const {
        return x < p2.x || (x == p2.x && y < p2.y);
    }
};

LL cross(p o, p a, p b){
    return (a.x-o.x)*(b.y-o.y) - (a.y-o.y)*(b.x-o.x);
}

LL dis(p a, p b){
    return abs(a.x-b.x) + abs(a.y-b.y);
}

vector<p> andrew(vector<p>& arr){
    sort(All(arr));
    int n = arr.size();
    vector<p> res(2*n);
    int k = 0;
    for(int i = 0; i < n; ++i){
        while(k > 1 && (cross(res[k-2], res[k-1], arr[i]) <= 0)) k--;
        res[k++] = arr[i];
    }
    for(int i = n-2, t = k; i >= 0; --i){
        while(k > t && (cross(res[k-2], res[k-1], arr[i]) <= 0)) k--;
        res[k++] = arr[i];
    }
    k--;
    res.resize(k);
    return res;
}

void solve(){
    int n;
    cin >> n;
    vector<p> arr(n);
    for(int i = 0; i < n; ++i){
        cin >> arr[i].x >> arr[i].y;
    }

    vector<p> res = andrew(arr);
    LL mx = 0;
    for(int i = 0; i < sz(res); ++i){
        for(int j = i+1; j < sz(res); ++j){
            mx = max(mx, dis(res[i], res[j]));
        }
    }
    cout << mx << "\n";
}

int main()
{
    Fast;
    //louisfghbvc{
        solve();
    //}
    return 0;
}

