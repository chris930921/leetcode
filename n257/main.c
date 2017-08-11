// 257. Binary Tree Paths

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
typedef struct NodeList{
    int value;
    struct NodeList* next;
} NodeList;

typedef struct StringList{
    char* str;
    struct StringList* next;
} StringList;

void visit(struct TreeNode* node, int depth, NodeList* currentNode, StringList** results){
    if(node == NULL){
        return;
    }
    
    NodeList* newNode = (NodeList*)calloc(1, sizeof(NodeList));
    newNode->value = node->val;
    newNode->next = currentNode;
    currentNode = newNode;
    
    NodeList* test = newNode;
    while(test){
        printf("%d ", test->value);
        test = test->next;
    }
    printf("\n");
    
    if(node->left == NULL && node->right == NULL){
        int size = (depth + 1) * 5;
        char* tmp;
        char* firstBuffer = (char*)calloc(size, sizeof(char));
        char* secondBuffer = (char*)calloc(size, sizeof(char));
        sprintf(firstBuffer, "%d", currentNode->value);
        currentNode = currentNode->next;
        while(currentNode){
            sprintf(secondBuffer, "%d->%s", currentNode->value, firstBuffer);
            currentNode = currentNode->next;
            tmp = firstBuffer;
            firstBuffer = secondBuffer;
            secondBuffer = tmp;
        }
        
        StringList* node = (StringList*)calloc(1, sizeof(StringList));
        node->str = firstBuffer;
        node->next = *results;
        *results = node;
    }
    
    visit(node->left, depth + 1, newNode, results);
    visit(node->right, depth + 1, newNode, results);
    
    return;
}

char** binaryTreePaths(struct TreeNode* root, int* returnSize) {
    StringList* resultsList = NULL;
    visit(root, 0, NULL, &resultsList);
    
    StringList* current = resultsList;
    while(current){
        printf("%s\n", current->str);
        (*returnSize)++;
        current = current->next;
    }
    
    current = resultsList;
    char** results = (char**)calloc(*returnSize, sizeof(char*));
    for(int i = 0; i < *returnSize; i++){
        results[i] = resultsList->str;
        resultsList = resultsList->next;
    }
    
    return results;
}