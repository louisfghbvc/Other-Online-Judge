// Just bullshit, this is very slow.
// so next time, try to brute force
// insert is logN but worse is N
// O(qN)

#include <bits/stdc++.h>
using namespace std;

vector<int> st;

int main()
{
    int q, t, x;
    while(cin >> q){
        while(q--){
            cin >> t >> x;
            if(t == 1){
                st.insert(lower_bound(st.begin(), st.end(), x), x);
            }else {
                int target = st[x-1];
                cout << target << endl;
                st.erase(st.begin()+x-1);
            }
        }

    }
}
/**
5
1 11
1 29
1 89
2 2
2 2
**/
