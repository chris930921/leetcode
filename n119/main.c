// 119. Pascal's Triangle II

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getRow(int rowIndex, int* returnSize) {
    int size = rowIndex + 1;
    *returnSize = size;
    int* result = (int*)calloc(size, sizeof(int));
    
    result[0] = 1;
    for(int i = 1; i < size; i++){
        result[i] = 1;
        
        for(int j = i / 2; j > 0; j--){
            result[j] = result[j] + result[j-1];
            result[i-j] = result[j];
        }
    }
    
    return result;
}