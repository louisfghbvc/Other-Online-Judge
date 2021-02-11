// O(N). u can use two stack.
/**
 * class Tree {
 *     public:
 *         int val;
 *         Tree *left;
 *         Tree *right;
 * };
 */
vector<int> solve(Tree* root) {
    vector<int> res;
    if(!root) return res;
    queue<Tree*> q;
    q.push(root);
    int left = true;
    while(q.size()){
        vector<int> tmp;
        for(int S = q.size()-1; S >= 0; --S){
            Tree* cur = q.front(); q.pop();
            tmp.push_back(cur->val);
            if(cur->left) q.push(cur->left);
            if(cur->right) q.push(cur->right);
        }
        if(!left) reverse(tmp.begin(), tmp.end());
        res.insert(res.end(), tmp.begin(), tmp.end());
        left ^= 1;
    }
    return res;
}
