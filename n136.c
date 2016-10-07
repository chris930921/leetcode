int singleNumber(int* nums, int numsSize) {
    int max = 0, value = 0;
    for(int i = 0; i < numsSize; i++){
        value = (nums[i] >= 0) ? nums[i] : -nums[i];
        max = (value > max) ? value : max;
    }
    max += 1;
    int* upList = (int*)malloc(sizeof(int) * max);
    int* downList = (int*)malloc(sizeof(int) * max);
    for(int i = 0; i < numsSize; i++){
        if(nums[i] < 0) downList[-nums[i]]++;
        else upList[nums[i]]++;
    }
    value = 0;
    for(int i = 0; i < max; i++){
        if(downList[i] == 1){
            value = -i;
            break;
        }else if(upList[i] == 1){
            value = i;
            break;
        }
    }
    return value;
}