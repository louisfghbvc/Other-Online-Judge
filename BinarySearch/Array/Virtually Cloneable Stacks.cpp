// O(1). simple implement.

class VirtuallyCloneableStacks {
    public:
    vector<int> sz;
    VirtuallyCloneableStacks() {
        sz.push_back(0);
    }

    void copyPush(int i) {
        sz.push_back(sz[i]+1);
    }

    void copyPop(int i) {
        sz.push_back(sz[i]-1);
    }

    int size(int i) {
        return sz[i];
    }
};
