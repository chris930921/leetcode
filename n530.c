int getMinimumDifference(struct TreeNode* root) {
    if(root->left == NULL && root->right == NULL){
        // Max positive value of int.
        return 0x7fffffff;
    }
    
    int resultLeft = 0x7fffffff;
    if(root->left != 0){
        int diffLeft = abs(root->val - root->left->val);
        int minLeft = getMinimumDifference(root->left);
        
        if(minLeft > diffLeft){
            resultLeft = diffLeft;
        }else{
            resultLeft = minLeft;
        }
    }
    
    int resultRight = 0x7fffffff;
    if(root->right != 0){
        int minRight = abs(root->val - root->right->val);
        int diffRight = getMinimumDifference(root->right);
        
        if(minRight > diffRight){
            resultRight = diffRight;
        }else{
            resultRight = minRight;
        }
    }
    
    if(resultLeft > resultRight){
        return resultRight;
    }else{
        return resultLeft;
    }
}