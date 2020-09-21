// just maintain maximum stack, so that the top is maximum.
// O(N).

#include<bits/stdc++.h>
using namespace std;

stack<int> st;

void solve(int type = 0, int x = 0){
    cin >> type;
    if(type == 1){
        // push element
        cin >> x;
        if(st.empty()) st.push(x);
        else st.push(max(st.top(), x));
    }
    else if(type == 2){
        // delete top element
        st.pop();
    }
    else{
        // print maximum element
        cout << st.top() << "\n";
    }
}

int main() {
    int n;
    cin >> n;
    while(n--){
        solve();
    }
    return 0;
}
