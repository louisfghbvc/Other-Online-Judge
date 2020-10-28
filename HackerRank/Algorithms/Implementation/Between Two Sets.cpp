// Hard to understand problem statement. and it is really simple.
// O(NlogN)

int getTotalX(vector<int> a, vector<int> b) {
    int alcm = a[0];
    for(int i = 1; i < a.size(); ++i) alcm = (alcm*a[i])/__gcd(alcm, a[i]);
    
    int bgcd = b[0];
    for(int i = 1; i < b.size(); ++i) bgcd = __gcd(bgcd, b[i]);

    int cnt = 0;
    for(int fk = alcm; fk <= bgcd; fk += alcm){
        bool ok = 1;
        for(int x: b)
            if(x % fk) ok = 0;
        cnt += ok;
    }
    return cnt;
}
