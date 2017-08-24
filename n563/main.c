// 563. Binary Tree Tilt

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int findSum(struct TreeNode* root) {
    if(root == NULL){
        return 0;
    }
    
    // 遞迴裡面要都是一樣的操作。
    // 一開始寫時一直想要把 child node 都加總，可是 root node 不加總，
    // 所以一直寫不順。
    int leftAll = findSum(root->left);
    int rightAll = findSum(root->right);
    
    return leftAll + rightAll + root->val;
}

int findTilt(struct TreeNode* root) {
    if(root == NULL){
        return 0;
    }
    
    // 算出左邊的加總。
    int leftSum = findSum(root->left);
    // 算出右邊的加總。
    int rightSum = findSum(root->right);
    
    // 算出這個節點的 tilt。
    int tilt = 0;
    if(leftSum >= rightSum){
        tilt = leftSum - rightSum;
    }else{
        tilt = rightSum - leftSum;
    }
    
    // 加上左邊全部的 tilt。
    int leftAll = findTilt(root->left);
    // 加上右邊全部的 tilt。
    int rightAll = findTilt(root->right); 
    
    return tilt + leftAll + rightAll;
}