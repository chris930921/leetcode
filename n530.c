/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int getMinDifferenceFromRoot(struct TreeNode* node, int rootValue){
    // 節點為空時，回傳 int 最大的正整數，不影響最小 difference 的比對。
    if(node == NULL){
        return 0x7FFFFFFF;
    }
    
    // 根節點 (rootValue) 和左子樹所有節點比對，找出最小的 difference。
    int leftMin = getMinDifferenceFromRoot(node->left, rootValue);
    // 根節點 (rootValue) 和右子樹所有節點比對，找出最小的 difference。
    int rightMin = getMinDifferenceFromRoot(node->right, rootValue);
    // 根節點 (rootValue) 和目前節點比對，產生一個 difference。
    int currentDifference = abs(node->val - rootValue);
    
    // 比較以上三種 difference，找出最小的 difference。
    if(leftMin < currentDifference){
        currentDifference = leftMin;
    }
    if(rightMin < currentDifference){
        currentDifference = rightMin;
    }
    
    // 回傳最小的 difference。
    return currentDifference;
}

int getMinimumDifference(struct TreeNode* root) {
    // 節點為空時，回傳 int 最大的正整數，不影響最小 difference 的比對。
    if(root == NULL){
        return 0x7FFFFFFF;
    }
    
    // 以左節點為根節點，找出左半部最小的 difference。
    int leftSubTreeMin = getMinimumDifference(root->left);
    // 以右節點為根節點，找出右半部最小的 difference。
    int rightSubTreeMin = getMinimumDifference(root->right);
    
    // 根節點和左子樹所有節點相比較，找出最小的 difference。
    int rootLeftMin = getMinDifferenceFromRoot(root->left, root->val);
    // 根節點和右子樹所有節點相比較，找出最小的 difference。
    int rootRightMin = getMinDifferenceFromRoot(root->right, root->val);
    
    // 比較以上四種 difference，找出最小的 difference。
    int minDifference = leftSubTreeMin;
    if(rightSubTreeMin < minDifference){
        minDifference = rightSubTreeMin;
    }
    if(rootLeftMin < minDifference){
        minDifference = rootLeftMin;
    }
    if(rootRightMin < minDifference){
        minDifference = rootRightMin;
    }
    
    // 回傳最小的 difference。
    return minDifference;
}