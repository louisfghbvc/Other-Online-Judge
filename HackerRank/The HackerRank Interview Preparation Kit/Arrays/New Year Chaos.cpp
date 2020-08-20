// main idea is from end to begin.
// because the small can be more than 2 in back position.
// but bigger number only can jump to at most 2.
// O(N).

void minimumBribes(vector<int> q) {
    int n = q.size();
    int res = 0;
    for(int i = n-1; i >= 0; --i){
        if(q[i] != i+1){
            if(i > 0 && q[i-1] == i+1){
                res++;
                swap(q[i-1], q[i]);
            }
            else if(i > 1 && q[i-2] == i+1){
                res += 2;
                q[i-2] = q[i-1];
                q[i-1] = q[i];
                q[i] = i+1;
            }
            else{
                puts("Too chaotic");
                return;
            }
        }
    }
    cout << res << "\n";
}
