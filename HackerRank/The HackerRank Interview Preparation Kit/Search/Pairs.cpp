// one pass. becuase only find the big k or small k.
// like prefix map, but only once. so use set.

int pairs(int k, vector<int> arr) {
    unordered_set<int> st;
    int n = arr.size(); 
    int res = 0;
    for(int x: arr){
        if(st.count(x+k)) res++;
        if(st.count(x-k)) res++;
        st.insert(x);
    }
    return res;
}
