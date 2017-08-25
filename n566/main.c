// 566. Reshape the Matrix

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** matrixReshape(int** nums, int numsRowSize, int numsColSize, int r, int c, int** columnSizes, int* returnSize) {
    int allSize = numsRowSize * numsColSize;
    
    if(allSize != r*c){
        r = numsRowSize;
        c = numsColSize;
    }
    
    *returnSize = r;
    *columnSizes = (int*)calloc(r, sizeof(int));
    int** newNums = (int**)calloc(r, sizeof(int*));
    for(int i = 0; i < r; i++){
        newNums[i] = (int*)calloc(c, sizeof(int));
        (*columnSizes)[i] = c;
    }
    
    if(allSize != r*c){
        return nums;
    }

    for(int i = 0; i < allSize; i++){
        int oldRow = i / numsColSize;
        int oldColumn = i % numsColSize;

        int newRow = i / c;
        int newColumn = i % c;

        newNums[newRow][newColumn] = nums[oldRow][oldColumn];
    }
    return newNums;
}