#include <bits/stdc++.h>

#define Fast cin.tie(0), ios::sync_with_stdio(0)
#define All(x) x.begin(), x.end()
#define louisfghbvc int t; cin >> t; for(int tt = 0; tt < t; ++tt)
#define sz(x) (int)(x).size()
#define sort_unique(x) sort(x.begin(), x.end()); x.erase(unique(x.begin(), x.end()));
using namespace std;
typedef long long LL;
typedef pair<LL, LL> ii;
typedef vector<LL> vi;

template<typename T> istream& operator>>(istream &is, vector<T> &v) { for(auto &it : v) is >> it; return is; }
template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << '{'; string sep = ""; for(const auto &x : v) os << sep << x, sep = ", "; return os << '}'; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }

void dbg_out() { cerr << " end.\n"; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

const int N = 1e5 + 5;
const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;
/**
Read problem statement carefully

**/

struct window{
    multiset<int> L, R;
    LL sumL = 0, sumR = 0;

    void add(int x){
        if(sz(L) && x <= *L.rbegin()){
            L.insert(x);
            sumL += x;
        }
        else{
            R.insert(x);
            sumR += x;
        }
        balance();
    }

    void balance(){
        if(L.size() == R.size()) return;
        if(L.size()+1 == R.size()) return;
        if(L.size() > R.size()){
            int val = *L.rbegin();
            sumL -= val;
            sumR += val;
            R.insert(val);
            L.erase(L.find(val));
        }
        else{
            int val = *R.begin();
            sumL += val;
            sumR -= val;
            L.insert(val);
            R.erase(R.begin());
        }
    }

    void pop(int x){
        if(sz(L) && x <= *L.rbegin()){
            L.erase(L.find(x));
            sumL -= x;
        }
        else if(sz(R) && x <= *R.rbegin()){
            R.erase(R.find(x));
            sumR -= x;
        }
        else{
            cout << "NO " << x << "\n";
        }
        balance();
    }

    int getMedian(){
        if(sz(L)+1 == sz(R))
            return *R.begin();
        return *L.rbegin();
    }

    LL getSum(){
        LL mid = getMedian();
        return mid * sz(L) - sumL + sumR - mid * sz(R);
    }
};

void solve(int T){
    int n, k;
    cin >> n >> k;
    vi arr(n);
    cin >> arr;

    window win;
    for(int i = 0; i < n; ++i){
        win.add(arr[i]);
        if(i+1 >= k){
            cout << win.getSum() << " ";
            win.pop(arr[i+1-k]);
        }
    }
    cout << "\n";
}

int main()
{
    Fast;
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    // louisfghbvc
        solve(1);
    return 0;
}

/**
Enjoy the problem.
**/
