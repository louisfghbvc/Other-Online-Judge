// O(N). space O(N). use set.
// just count it and if both child have then return root.

/**
 * class Tree {
 *     public:
 *         int val;
 *         Tree *left;
 *         Tree *right;
 * };
 */
unordered_set<int> st;
Tree* dfs(Tree* root){
    if(!root) return NULL;
    if(st.count(root->val)) return root;
    Tree* left = dfs(root->left);
    Tree* right = dfs(root->right);
    if(left && right) return root;
    if(left) return left;
    return right;
}
Tree* solve(Tree* root, vector<int>& values) {
    st = unordered_set<int>(values.begin(), values.end());
    return dfs(root);
}
