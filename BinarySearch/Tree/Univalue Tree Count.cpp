// O(N). dfs. careful the case.
int cnt;
bool dfs(Tree* root){
    if(!root) return true;
    bool left = dfs(root->left);
    bool right = dfs(root->right);
    if(left && right){
        if(root->left && root->left->val != root->val) return false;
        if(root->right && root->right->val != root->val) return false;
        cnt++;
        return true;
    }
    return false;
}

int solve(Tree* root) {
    cnt = 0;
    dfs(root);
    return cnt;
}
