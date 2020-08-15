// just sort and pick big odd.
// Straight Forward. because must pick longest 1. so greedy is ok.
// O(NlogN). Greedy

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<LL, LL> ii;
typedef vector<LL> vi;
const int N = 1e5+5;
//LL arr[N];
 
int main()
{
    int t;
    cin >> t;
    string s;
    while(t--){
        cin >> s;
        s += '0';
        priority_queue<int> pq;
        int fre = 0;
        for(auto &c: s){
            if(c == '0'){
                if(fre) pq.push(fre);
                fre = 0;
            }
            else fre++;
        }
        int res = 0;
        bool a = 1;
        while(pq.size()){
            if(a) res += pq.top();
            pq.pop();
            a ^= 1;
        }
        cout << res << endl;
    }
    return 0;
}
