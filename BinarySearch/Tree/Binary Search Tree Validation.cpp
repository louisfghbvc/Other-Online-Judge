// Simple recursive. O(N).
/**
 * class Tree {
 *     public:
 *         int val;
 *         Tree *left;
 *         Tree *right;
 * };
 */
bool dfs(Tree* root, Tree* low = NULL, Tree* high = NULL) {
    if(!root) return true;
    if(low && root->val <= low->val) return false;
    if(high && root->val >= high->val) return false;
    return dfs(root->left, low, root) && dfs(root->right, root, high);
}
bool solve(Tree* root) {
    return dfs(root);
}
