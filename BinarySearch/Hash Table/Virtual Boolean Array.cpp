// Tricky. O(1). O(N)space.
// use a flag and clear to maintain state.

class BooleanArray {
    public:
    unordered_map<int, bool> mp;
    bool flag = 0;
    BooleanArray() {
    }

    void setTrue(int i) {
        mp[i] = 1;
    }

    void setFalse(int i) {
        mp[i] = 0;
    }

    void setAllTrue() {
        mp.clear();
        flag = 1;
    }

    void setAllFalse() {
        mp.clear();
        flag = 0;
    }

    bool getValue(int i) {
        if(mp.count(i)) return mp[i];
        return flag;
    }
};
