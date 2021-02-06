// O(1).

class HitCounter {
    public:
    queue<int> q;
    HitCounter() {

    }

    void dump(int timestamp){
        while(q.size() && timestamp - q.front() > 60) q.pop();
    }

    void add(int timestamp) {
        q.push(timestamp);
    }

    int count(int timestamp) {
        dump(timestamp);
        return q.size();
    }
};
