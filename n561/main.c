// 561. Array Partition I

// 用於快速排序的比對。
int compare(const void *value1, const void *value2){
    return *(int *)value1 - *(int *)value2;
}

int arrayPairSum(int* nums, int numsSize) {    
    // 使用 stdlib.h 的快速排序，泡沫排序法太慢。
    qsort((void *)nums, numsSize, sizeof(int), compare); 
    
    int sum = 0;
    for(int i = 0; i < numsSize; i += 2){
        sum += nums[i];
    }
    
    return sum;
}