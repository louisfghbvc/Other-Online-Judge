// A shit problem. just chek previous line to see if '#'.
// And the statement not clear.
// See the example.
// ...###. the border from top: 3,2,1,1,2,1. has six borders, just check max..
// ...#...

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
 
void solve(){
    int n, m;
	cin >> n >> m;
	vector<string> g(n);
	int mx = 0;
	for(int i = 0; i < n; ++i)
		cin >> g[i];
 
	int res = 0;
 
	auto help = [&](){
		for(int i = 0; i < n; ++i){
			int mxl = 0, c = 0;
			for(int j = 0; j < m; ++j){
				if(i && g[i-1][j] == '#'){
					mxl = max(mxl, c);
					c = 0;
				}
				else if(g[i][j] == '#') c++;
				else{
					mxl = max(mxl, c);
					c = 0;
				}
			}
			if(c) mxl = max(mxl, c); 
			res = max(mxl, res);
		}
	};
	
	auto LR = [&](){
		for(int j = 0; j < m; ++j){
			int mxl = 0, c = 0;
			for(int i = 0; i < n; ++i){
				if(j && g[i][j-1] == '#'){
					mxl = max(mxl, c);
					c = 0;
				}
				else if(g[i][j] == '#') c++;
				else{
					mxl = max(mxl, c);
					c = 0;
				}
			}
			if(c) mxl = max(mxl, c); 
			res = max(mxl, res);
		}
	};
 
	help();
	reverse(All(g));
	help();
 
	LR();
	for(int i = 0; i < n; ++i) reverse(All(g[i]));
	LR();
 
	cout << res << "\n";
}
 
int main()
{
    Fast;
    louisfghbvc{
        solve();
    }
    return 0;
}
