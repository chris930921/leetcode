// 437. Path Sum III

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

// 計算單個 node 下面有多少條符合 sum 的 path。
int countPath(struct TreeNode* node, int rootValue, int sum){
    if(node == NULL){
        return 0;
    }
    
    // 如果 result == sum，則 path 數量 + 1。
    int result = node->val + rootValue;
    int count = result == sum;
    
    // 繼續往左、右半邊找 path，要記得將前面節點相加的結果 result 往下傳。
    int leftCount = countPath(node->left, result, sum);
    int rightCount = countPath(node->right, result, sum);
    
    return count + leftCount + rightCount;
} 

// 計算全部 node 裡面有多少條符合 sum 的 path。
int pathSum(struct TreeNode* root, int sum) {
    if(root == NULL){
        return 0 ;
    }
    
    // 如果 root 的 value == sum，也算一條 path。
    int count = root->val == sum;
    // 找出左、右節點有多少 path。
    int leftCount = countPath(root->left, root->val, sum);
    int rightCount = countPath(root->right, root->val, sum);
    
    // 以左、右節點當作 root，找出 root 下面所有 node 的 path 數量。
    int leftSum = pathSum(root->left, sum);
    int rightSum = pathSum(root->right, sum);
    
    // 將全部結果加總，就是全部的 path 數量。
    return count + leftCount + rightCount + leftSum + rightSum;
}