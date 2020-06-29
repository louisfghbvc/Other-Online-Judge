// trick is let alpha connect to num.
// watch out if first one is alpha, ans is 9, stick with this...
// and after look, shrink alpha to a number.
// O(N).

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int p[256];
int find(int x){
    return p[x] < 0 ? x : p[x] = find(p[x]);
}

void uni(int a, int b){
    a = find(a), b = find(b);
    if(a == b) return;
    if(isdigit(a) && isalpha(b)) p[b] = a;
    else p[a] = b;
}

int main()
{
    int n;
    string s1, s2;
    while(cin >> n){
        memset(p, -1, sizeof p);
        cin >> s1 >> s2;

        for(int i = 0; i < n; ++i){
            if(isdigit(s1[i]) && isdigit(s2[i])) continue;
            uni(s1[i], s2[i]);
        }

        LL ans = 1;
        if(isalpha(find(s1[0]))){
            ans = 9;
            uni('0', s1[0]);
        }

        for(int i = 1; i < n; ++i){
            if(isdigit(find(s1[i]))) continue;
            ans *= 10;
            uni('0', s1[i]);
        }

        cout << ans << endl;

    }
}
/**
4
1248
1Z48
3
XXX
YYY
6
PRBLMB
ARC027
**/
