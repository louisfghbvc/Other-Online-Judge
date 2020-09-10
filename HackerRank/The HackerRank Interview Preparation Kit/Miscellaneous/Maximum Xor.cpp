// Like Trie, Build a INT tree.
// when search. if Highest bit set, go to that bit. thik about 3 bit, when 4 set(100), no matter go to back, max 011 => 3.
// Insert O(1). Search: O(1).

struct Node{
    Node* next[2];
    Node(){
        memset(next, 0, sizeof next);
    }
};

void insert(Node* root, int x){
    Node* tmp = root;
    for(int i = 31; i >= 0; --i){
        bool isSet = x&(1<<i) ? 1 : 0;
        if(tmp->next[isSet] == NULL){
            tmp->next[isSet] = new Node();
        }
        tmp = tmp->next[isSet];
    }
}

int searchMax(Node* root, int x){
    Node* tmp = root;
    int mx = 0;
    for(int i = 31; i >= 0 && tmp; --i){
        bool curBit = x&(1<<i) ? 1 : 0;
        bool need = x&(1<<i) ? 0 : 1;
        if(tmp->next[need]){
            mx |= (1<<i);
            tmp = tmp->next[need];
        }
        else tmp = tmp->next[curBit];
    }
    return mx;
}

// Complete the maxXor function below.
vector<int> maxXor(vector<int> arr, vector<int> queries) {
    Node* root = new Node();
    for(int x: arr) insert(root, x);

    vector<int> res;
    for(int q: queries){
        res.push_back(searchMax(root, q));
    }

    return res;
}
