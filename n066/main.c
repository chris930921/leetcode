// 66. Plus One

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize) {
    if(digitsSize == 0){
        digits[0] = 1;
        *returnSize = 1;
        return digits;
    }
    
    int i = digitsSize - 1;
    digits[i] += 1;
    
    
    for(i = i - 1; i >= 0; i--){
        if(digits[i + 1] == 10){
            digits[i + 1] = 0;
            digits[i] += 1;
        }
    }
    
    int* result = digits;
    *returnSize = digitsSize;
    if(digits[0] == 10){
        digits[0] = 0;
        result = (int*)calloc(digitsSize + 1, sizeof(int));
        result[0] = 1;
        for(int j = 0; j < digitsSize; j++){
            result[j+1] = digits[j];
        }
        *returnSize += 1;
    }
    
    return result;
}