// 643. Maximum Average Subarray I

double findMaxAverage(int* nums, int numsSize, int k) {
    if(numsSize == 0){
        return 0;
    }
    
    int max = 0x80000000;
    int sum;
    for(int i = 0; i < numsSize - k + 1; i++){
        
        sum = 0;
        for(int j = 0; j < k; j++){
            sum += nums[i + j];
        }
        printf("\n");
        if(sum > max){
            max = sum;
        }
    }
    
    return (double)max / (double)k;
}