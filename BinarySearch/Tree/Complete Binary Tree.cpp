// O(N).
bool solve(Tree* root) {
    if(!root) return true;
    queue<Tree*> q;
    q.push(root);
    bool noKid = false;
    while(q.size()){
        for(int S = q.size()-1; S >= 0; --S){
            auto cur = q.front(); q.pop();
            if(cur->left){
                if(noKid) return false;
                q.push(cur->left);
            }
            else{
                if(!noKid) noKid = true;
            }
            if(cur->right){
                if(noKid) return false;
                q.push(cur->right);
            }
            else{
                if(!noKid) noKid = true;
            }
        }
    }
    return true;
}

// use index. O(N).
bool solve(Tree* root) {
    if(!root) return true;
    queue<pair<Tree*, int> > q;
    q.push({root, 1});
    int n = 0;
    while(q.size()){
        for(int S = q.size()-1; S >= 0; --S){
            auto [cur, v] = q.front(); q.pop();
            if(n+1 != v) return false;
            n = v;
            if(cur->left) q.push({cur->left, v*2});
            if(cur->right) q.push({cur->right, v*2+1});
        }
    }
    return true;
}
