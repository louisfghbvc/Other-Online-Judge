/**
 * class Tree {
 *     public:
 *         int val;
 *         Tree *left;
 *         Tree *right;
 * };
 */
class BSTIterator {
    private:
        vector<int> arr;
        int i;
    public:
    BSTIterator(Tree* root) {
        dfs(root);
        i = -1;
    }

    void dfs(Tree* root){
        if(!root) return;
        dfs(root->left);
        arr.push_back(root->val);
        dfs(root->right);
    }

    int next() {
        return arr[++i];
    }

    bool hasnext() {
        return i+1 < arr.size();
    }

    int prev() {
        return arr[--i];
    }

    bool hasprev() {
        return i-1 >= 0;
    }
};

// solution2 on the fly
