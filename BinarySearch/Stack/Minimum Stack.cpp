// time complexity O(1).

class MinimumStack {
    public:
    // origin, min
    stack<pair<int, int>> st;
    int mn;
    MinimumStack() {
        mn = INT_MAX;
    }

    void append(int val) {
        if(mn > val) mn = val;
        st.push({val, mn});
    }

    int peek() {
        return st.top().first;
    }

    int min() {
        return st.top().second;
    }

    int pop() {
        int val = st.top().first;
        st.pop();
        if(st.empty()) mn = INT_MAX;
        else mn = st.top().second;
        return val;
    }
};
