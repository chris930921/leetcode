// 100. Same Tree

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
    // 如果兩個節點都不存在，就回傳 true。
    // 這個檢查如果是 true 就代表父節點的 val 是相同的，不用再檢查 p.val == q.val。
    if(p == NULL && q == NULL){
        return true;
    }
    
    // p 的節點不存在，q 的節點存在，回傳 false。
    if(p == NULL){
        return false;
    }
    
    // p 的節點存在，q 的節點存在，回傳 false。
    if(q == NULL){
        return false;
    }
    
    // p 和 q 的值不相同，回傳 false。
    if(p->val != q->val){
        return false;
    }
    
    // 檢查左、右兩子樹結構和數值是否相同。
    int result = isSameTree(p->left, q->left);
    result &= isSameTree(p->right, q->right);
    
    return result;
}