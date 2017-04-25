int* twoSum(int* numbers, int numbersSize, int target, int* returnSize) {
    int* results = (int*)calloc(2, sizeof(int));
    
    int i = 0;
    int j = 0;
    for(i = 0; i < numbersSize; i++){
        for(j = i + 1; j < numbersSize; j++){
            if((numbers[i] + numbers[j]) == target){
                results[0] = i + 1;
                results[1] = j + 1;
            }
        }
    }
    
    *returnSize = 2;
    return results;
}