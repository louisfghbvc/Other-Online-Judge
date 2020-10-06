// use stack to maintain state. tricky.
// O(N).

#include<bits/stdc++.h>
using namespace std;

int main() {
    int q, t, k;
    cin >> q;
    string s = "", w;
    stack<string> st;
    while(q--){
        cin >> t;
        if(t == 1){ // append
            cin >> w;
            st.push(s);
            s += w;
        }
        else if(t == 2){ // delete
            cin >> k;
            st.push(s);
            s.erase(s.size()-k, k); 
        }
        else if(t == 3){ // print
            cin >> k;
            cout << s[k-1] << "\n";
        }
        else{ // undo
            s = st.top(); st.pop();
        }
    }

    return 0;
}
