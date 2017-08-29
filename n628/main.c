// 628. Maximum Product of Three Numbers

// 用於快速排序的比對。
int compare(const void *value1, const void *value2){
    return *(int *)value1 - *(int *)value2;
}

int maximumProduct(int* nums, int numsSize) {
    // 使用 stdlib.h 的快速排序，泡沫排序法太慢。
    qsort((void *)nums, numsSize, sizeof(int), compare); 
    
    // 因為有負數，所以排序完後最大的可能性在兩種排列裡。
    // 第一種是最後三個正數乘起來。
    // 第二種是乘上兩個最小的負數和最大的正數。
    int firstValue = nums[numsSize - 1] * nums[numsSize - 2] * nums[numsSize - 3];
    int secondValue = nums[numsSize - 1] * nums[0] * nums[1];
    
    // 兩種都算出來後判斷哪個最大。
    if(firstValue >= secondValue){
        return firstValue;
    }else{
        return secondValue;
    }
}