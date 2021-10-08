// Dp, use BIT to optimize. O(NlogX)
class BIT{
public:
    void add(int x, int v){
        for(++x; x < N; x += x&-x)
            data[x] = (data[x] + v) % mod;
    }
    LL sum(int x){
        LL res = 0;
        for(++x; x; x -= x&-x)
            res = (data[x] + res) % mod;
        return res;
    }
private:
    LL data[N] = {};
} bt;


void solve(int T){
    int n;
    cin >> n;
    vi arr(n);
    cin >> arr;

    // compress
    auto tmp = arr;
    sort_unique(tmp);

    for(int x: arr){
        x = lower_bound(All(tmp), x) - tmp.begin();

        // number of strict smaller 
        bt.add(x, bt.sum(x-1));
        // for(int j = 0; j < i; ++j) if(arr[j] < arr[i]){
        //     dp[i] = (dp[i] + dp[j]) % mod;
        // }

        // new one, from cur index
        bt.add(x, 1);
    }

    cout << bt.sum(sz(tmp)-1) << "\n";
}
