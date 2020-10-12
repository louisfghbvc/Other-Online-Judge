// O(q).
// main idea is like garbage can, when can empty. bump it

#include<bits/stdc++.h>
using namespace std;

int main() {
    int q, type, x;
    cin >> q;
    stack<int> oldEle, newEle;

    auto dump = [&](){
        if(oldEle.empty())
            while(newEle.size()) oldEle.push(newEle.top()), newEle.pop();
        return 0;
    };

    while(q--){
        cin >> type;
        if(type == 1){ // enqueue
            cin >> x;
            newEle.push(x);
        }
        else if(type == 2){ // dequeue
            dump();
            oldEle.pop();
        }
        else{ // print front
            dump();
            cout << oldEle.top() << "\n";
        }
    }

    return 0;
}
