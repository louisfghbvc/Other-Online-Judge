// A magic solution, sort by left and right.
// and one by one into queue. like sliding window.
// when current right position is not greater than now index left position, pop it.
// because must need to overlap. so that can join this cost.
// a priority queue maintain min value and right position 
// O(NlogN). this is also a dp problem.

#include <bits/stdc++.h>
#define N 100005
#define Li pair<long long, int>
typedef long long LL;
using namespace std;

struct node{
    int l, r;
    LL c;
    bool operator<(const node& n2){
        if(l == n2.l) return r < n2.r;
        return l < n2.l;
    }
}arr[N];

int main()
{
    int n, l;
    while(cin >> n >> l){
        for(int i= 0; i < n; ++i){
            cin >> arr[i].l >> arr[i].r >> arr[i].c;
        }
        sort(arr, arr+n);
        priority_queue<Li, vector<Li>, greater<Li> > pq;
        pq.push({0, 0});

        LL ans = LLONG_MAX;
        for(int i = 0; i < n; ++i){
            while(pq.size() && pq.top().second < arr[i].l) pq.pop();
            LL cost = arr[i].c + pq.top().first;
            pq.push({cost, arr[i].r});
            if(arr[i].r >= l){
                ans = min(ans, cost);
            }
        }
        cout << ans << endl;
    }
}
/**
5 5
0 1 1
1 2 1
2 3 2
2 4 3
3 5 1
8 10
0 2 1
2 3 1
0 4 1
0 2 1
3 7 1
0 10 1080
8 10 1
9 10 1
**/
