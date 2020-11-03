// 海龍公式.
// check 3 area. eps.
#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

struct point{
    double x, y;
    bool operator<(point p2){
        return (x < p2.x || (x == p2.x && y < p2.y));
    }
};

double dis(point a, point b){
    return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}

double area(point a, point b, point c){
    double s1 = dis(a, b);
    double s2 = dis(a, c);
    double s3 = dis(b, c);
    double s = (s1+s2+s3)/2.0;
    return sqrt(s*(s-s1)*(s-s2)*(s-s3));
}

void solve(){
    point arr[3];
    for(int i = 0; i < 3; ++i)
        cin >> arr[i].x >> arr[i].y;
    point e;
    cin >> e.x >> e.y;

    double res = area(arr[0], arr[1], arr[2]);

    double a1 = area(e, arr[0], arr[1]);
    double a2 = area(e, arr[1], arr[2]);
    double a3 = area(e, arr[0], arr[2]);

    if(a1+a2+a3 - res >= 1e-6){
        cout << "OUTSIDE\n";
    }
    else cout << "INSIDE\n";
}

int main() {
	int q;
	cin >> q;
	while(q--)
		solve();
	return 0;
}
/**
2
-1 0 1 0 0 1 3 3
-5 0 5 0 0 5 1 0
**/
