// O(NlogN).

LLNode* mergeTwoList(LLNode* l, LLNode* r){
    LLNode *res = new LLNode(0);
    LLNode *dummy = res;
    while(l && r){
        if(l->val > r->val){
            res->next = new LLNode(r->val);
            r = r->next;
        }
        else{
            res->next = new LLNode(l->val);
            l = l->next;
        }
        res = res->next;
    }
    if(l) res->next = l;
    if(r) res->next = r;
    return dummy->next;
}

LLNode* dfs(LLNode* node){
    if(!node || !node->next) return node;
    LLNode* slow = node, *fast = node, *prev = NULL;
    while(fast && fast->next){
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    prev->next = NULL;
    LLNode *left = dfs(node);
    LLNode *right = dfs(slow);
    LLNode *res = mergeTwoList(left, right);
    return res;
}

LLNode* solve(LLNode* node) {
    return dfs(node);
}
