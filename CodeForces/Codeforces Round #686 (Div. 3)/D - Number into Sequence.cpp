// WA 4 time ==.
// just use prime and get factor.
// and sort by number of prime.
// e.g 2*2*2*3*3*3*3 => 3*3*3*(2*2*2*3). last always can merge.
// here use dummy while loop.

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

const int mod = 1e9+7;
const int N = 1e5+5;

vi prime;
bool np[N];
void init(){
    for(int i = 2; i < N; ++i){
        if(!np[i]){
            prime.push_back(i);
            for(int j = i*2; j < N; j+=i)
                np[j] = 1;
        }
    }
}

void solve(){
    LL n;
    cin >> n;
    vi tmp;
    for(LL p: prime){
        if(p > n) break;
        while(n % p == 0){
            tmp.push_back(p);
            n /= p;
        }
    }
    if(n != 1) tmp.push_back(n);

    unordered_map<int, int> mp;
    for(int x: tmp) mp[x]++;

    sort(All(tmp), [&](int a, int b){
            return mp[a] > mp[b];
         });

    bool ch = 1;
    while(ch){
        ch = 0;
        if(sz(tmp) == 1) break;
        for(int i = sz(tmp)-2; i >= 0; --i){
            if(tmp[i+1] % tmp[i] != 0){
                tmp[i] *= tmp[i+1];
                tmp.erase(tmp.begin()+i+1);
                ch = 1;
                break;
            }
        }
    }

    cout << sz(tmp) << "\n";
    for(int i = 0; i < sz(tmp); ++i)
        cout << tmp[i] << " \n"[i==sz(tmp)-1];

}

int main()
{
    Fast;
    init();
    louisfghbvc
        solve();
    return 0;
}
