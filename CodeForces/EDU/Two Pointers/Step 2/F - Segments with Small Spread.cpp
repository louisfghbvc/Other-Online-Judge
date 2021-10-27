#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

const int N = 1e5+5;

multiset<LL> st;
void add(LL x){
    st.insert(x);
}
void remove(LL x){
    st.erase(st.find(x));
}
bool good(LL k){
    if(st.empty()) return true;
    return *st.rbegin() - *st.begin() <= k;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    LL n, k;
    cin >> n >> k;

    vector<LL> arr(n);
    for(int i = 0; i < n; ++i)
        cin >> arr[i];
    
    LL res = 0;
    for(int r = 0, l = 0; r < n; ++r){
        add(arr[r]);
        while(!good(k)){
            remove(arr[l]);
            l++;
        }
        res += r-l+1;
    }
    cout << res << "\n";
    
    return 0;
}


// use min-max stack as queue. trick
#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

const int N = 1e5+5;

struct myStack{
    vector<LL> s, mn = {LLONG_MAX}, mx = {LLONG_MIN};
    void push(LL x){
        s.push_back(x);
        mn.push_back(min(mn.back(), x));
        mx.push_back(max(x, mx.back()));
    }
    LL pop(){
        LL res = s.back();
        s.pop_back();
        mn.pop_back();
        mx.pop_back();
        return res;
    }
    LL getMin(){
       return mn.back(); 
    } 
    LL getMax(){
        return mx.back();
    }
    bool empty(){
        return s.empty();
    }
};

myStack s1, s2;
void add(LL x){
    s2.push(x);
}
void remove(LL x){
    if(s1.empty()){
        while(!s2.empty()) s1.push(s2.pop());
    }
    s1.pop();
}
bool good(LL k){
    return max(s1.getMax(), s2.getMax()) - min(s1.getMin(), s2.getMin()) <= k;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    LL n, k;
    cin >> n >> k;

    vector<LL> arr(n);
    for(int i = 0; i < n; ++i)
        cin >> arr[i];
    
    LL res = 0;
    for(int r = 0, l = 0; r < n; ++r){
        add(arr[r]);
        while(!good(k)){
            remove(arr[l]);
            l++;
        }
        res += r-l+1;
    }
    cout << res << "\n";
    
    return 0;
}
