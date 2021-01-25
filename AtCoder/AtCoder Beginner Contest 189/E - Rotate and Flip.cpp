// Use linear algebra. O(N). use space to record matrix.
// so when u can not apply 2D, try 3D.

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

/**
op2 90
[0 -1 0]
[1  0 0]
[0  0 1]

op1
[0 1 0]
[-1 0 0]
[0 0 1]

op3
[-1 0 2p]
[0 1 0]
[0 0 1]

op4
[1 0 0]
[0 -1 2p]
[0 0 1]
**/

struct mat{
    vector<vi> a;
    mat(){
        a = vector<vi>(3, vi(3));
    }
};

mat mul(mat &a, mat &b){
    mat c;
    for(int i = 0; i < 3; ++i){
        for(int j = 0; j < 3; ++j){
            for(int k = 0; k < 3; ++k){
                c.a[i][j] += a.a[i][k]*b.a[k][j];
            }
        }
    }
    return c;
}

void solve(){
    LL n, m;
    cin >> n;
    vector<ii> arr;
    for(int i = 0, x, y; i < n; ++i){
        cin >> x >> y;
        arr.push_back({x, y});
    }

    cin >> m;
    mat op;
    op.a = {{1, 0, 0},
             {0, 1, 0},
             {0, 0, 1},
            };
    vector<mat> record = {op};
    for(LL i = 0, type, p; i < m; ++i){
        cin >> type;
        if(type == 1){
            op.a = {{0, 1, 0},
                    {-1, 0, 0},
                    {0, 0, 1},
                    };
        }
        else if(type == 2){
            op.a = {{0, -1, 0},
                    {1, 0, 0},
                    {0, 0, 1}
                    };
        }
        else if(type == 3){
            cin >> p;
            op.a = {{-1, 0, p*2},
                    {0, 1, 0},
                    {0, 0, 1}
                    };
        }
        else{
            cin >> p;
            op.a = {{1, 0, 0},
                    {0, -1, p*2},
                    {0, 0, 1}
                    };
        }
        record.push_back(mul(op, record.back()));
    }

    int q;
    cin >> q;
    int a, b;
    while(q--){
        cin >> a >> b;
        LL x = arr[b-1].first, y = arr[b-1].second;
        LL nx = record[a].a[0][0]*x + record[a].a[0][1]*y + record[a].a[0][2];
        LL ny = record[a].a[1][0]*x + record[a].a[1][1]*y + record[a].a[1][2];
        cout << nx << " " << ny << "\n";
    }
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
