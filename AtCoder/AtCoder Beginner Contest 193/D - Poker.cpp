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

const int N = 2e3+5;
const int inf = 0x3f3f3f3f;
/**
Read problem statement carefully
**/

LL pow10[10];
int cnt[10];
void init(){
    pow10[0] = 1;
    for(int i = 1; i < 10; ++i)
        pow10[i] = pow10[i-1]*10;
}

bool cal(string s, string t){
    int sf[10] = {};
    int tf[10] = {};
    for(char c: s) sf[c-'0']++;
    for(char c: t) tf[c-'0']++;

    LL sscore = 0, tscore = 0;
    for(int i = 1; i < 10; ++i){
        sscore += i * pow10[sf[i]];
        tscore += i * pow10[tf[i]];
    }

    //dbg_out(s, t, sscore, tscore);

    return sscore > tscore;
}

void solve(){
    int k;
    string s, t;
    cin >> k >> s >> t;
    for(int i = 1; i < 10; ++i) cnt[i] = k;
    for(int i = 0; i < 4; ++i){
        cnt[s[i]-'0']--;
        cnt[t[i]-'0']--;
    }

    double win = 0;
    for(int i = 1; i < 10; ++i){
        if(cnt[i] > 0){
            double p = (double)cnt[i]/(9*k-8);
            cnt[i]--;
            s[4] = (char)('0' + i);
            for(int j = 1; j < 10; ++j){
                if(cnt[j] > 0){
                    t[4] = (char)('0' + j);
                    if(cal(s, t)){
                        win += p*cnt[j]/(9*k-9);
                    }
                    t[4] = '#';
                }
            }
            cnt[i]++;
            s[4] = '#';
        }
    }

    printf("%.12f\n", win);
}

int main()
{
    Fast;
    init();
    //louisfghbvc
        solve();
    return 0;
}

/**
Enjoy the problem.
**/
