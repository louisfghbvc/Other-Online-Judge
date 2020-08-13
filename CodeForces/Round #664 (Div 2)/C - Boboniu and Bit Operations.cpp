// a bit harder. find after & and. | max.
// use set. rolling.
// but just enum all case. because. the bit is 10.
// O(NM10*10). WA 1 time. j = 0 type 1... so shit.

#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef long long LL;
int n, m;
 
int main()
{
    cin >> n >> m;
    vi a(n), b(m);
    for(int i = 0; i < n; ++i) cin >> a[i];
    for(int i = 0; i < m; ++i) cin >> b[i];
 
    set<int> st;
    for(int j = 0; j < m; ++j){
        st.insert(a[0]&b[j]);
    }
    for(int i = 1; i < n; ++i){
        set<int> ns;
        for(int j = 0; j < m; ++j){
            ns.insert(a[i]&b[j]);
        }
        set<int> ts;
        for(auto &x: st){
            for(auto &y: ns){
                ts.insert(x|y);
            }
        }
        st = ts;
    }
    cout << *st.begin() << endl;
    return 0;
}
