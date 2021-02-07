// Use bit tree to do this magic things. offline process.
// O(NlogN).
// each operation O(logN).

int BIT[300005];
class PlaylistQueue {
    const int N = 3e5+5;
    void add(int x, int v){
        for(++x; x < N; x += x&-x)
            BIT[x] += v;
    }
    int sum(int x){
        int res = 0;
        for(++x; x; x -= x&-x)
            res += BIT[x];
        return res;
    }
    int getKth(int k){
        int l = 0, r = N;
        while(l < r){
            int mid = (l+r)/2;
            if(sum(mid) >= k) r = mid;
            else l = mid+1;
        }
        return l;
    }

public:
    unordered_map<int, string> mp;
    int n;
    PlaylistQueue(vector<string>& songs) {
        memset(BIT, 0, sizeof BIT);
        n = songs.size();
        for(int i = 0; i < n; ++i){
            mp[i] = songs[i];
            add(i, 1);
        }
    }

    string play(int i) {
        int idx = getKth(i+1);
        string res = mp[idx];
        add(idx, -1);
        add(n, 1);
        mp.erase(idx);
        mp[n++] = res;
        return res;
    }
};
