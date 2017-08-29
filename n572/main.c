// 572. Subtree of Another Tree

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool checkSubTree(struct TreeNode* s, struct TreeNode* t){
    // 都是 NULL 時代表結構相同，回傳 true。
    if(s == NULL && t == NULL){
        return true;
    }else if(s == NULL){
        return false;
    }else if(t == NULL){
        return false;
    }
    
    // 檢查左邊、右邊、目前節點是否相同。
    int isValueSame = s->val == t->val;
    int isLeftTreeSame = checkSubTree(s->left, t->left);
    int isRightTreeSame = checkSubTree(s->right, t->right);
    
    // 如果三個都是 true，代表結構相同，回傳 true。
    return isValueSame && isLeftTreeSame && isRightTreeSame;
}

// 走訪 Tree 裡每一個節點。
bool isSubtree(struct TreeNode* s, struct TreeNode* t) {
    if(s == NULL){
        return false;
    }
    
    // 將每一個節點作為 Root 和 SubtTree 比較。
    int isSubTree = checkSubTree(s, t);
    int isLeftSubTree = isSubtree(s->left, t);
    int isRightSubTree = isSubtree(s->right, t);
    
    // 如果有找到任何一個 SubTree，回傳 true。
    return isSubTree || isLeftSubTree || isRightSubTree;
}