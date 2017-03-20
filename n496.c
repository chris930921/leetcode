int* nextGreaterElement(int* findNums, int findNumsSize, int* nums, int numsSize, int* returnSize) {
    int* returnNums = (int*)malloc(sizeof(int) * findNumsSize);
    *returnSize = findNumsSize;
    
    for(int i = 0; i < findNumsSize; i++){
        returnNums[i] = -1;
        int flag = 0;
        int currentValue = findNums[i];
        for(int j = 0; j < numsSize; j++){
            int compareValue = nums[j];
            if(flag == 0){
                if(compareValue == currentValue){
                    flag = 1;
                }  
            }else if(flag == 1){
                if(compareValue > currentValue){
                    returnNums[i] = compareValue;
                    break;
                }  
            }
        }
    }
    
    return returnNums;
}