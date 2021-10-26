// solution1, use map and stack
// each opertion is O(1)

class LastValueMap {
public:

    unordered_map<int, int> mp;
    stack<int> st; // record key order

    LastValueMap() {

    }

    void set(int key, int value) {
        mp[key] = value;
        st.push(key);
    }

    void remove(int key) {
        mp.erase(key);
    }

    int getLast() {
        while(!mp.count(st.top())) st.pop();
        return mp[st.top()];
    }
};

// solution2 use list and map
class LastValueMap {
public:

    list<pair<int, int>> mp; // record data

    // int -> iterator
    unordered_map<int, list<pair<int, int>>::iterator> it_map; 

    LastValueMap() {

    }

    void set(int key, int value) {
        remove(key);
        mp.push_back({key, value});
        it_map[key] = prev(mp.end());
    }

    void remove(int key) {
        auto p = it_map.find(key);
        if(p != it_map.end()){
            mp.erase(p->second);
            it_map.erase(p);
        }
    }

    int getLast() {
        return mp.back().second;
    }
};
