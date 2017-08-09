// 198. House Robber

int rob(int* nums, int numsSize) {
    int first = 0;
    int second = 0;
    
    for(int i = 0; i < numsSize; i++){
        if(i % 2){
            first += nums[i];
            first = (first > second) ? first : second;
        }else{
            second += nums[i];
            second = (first > second) ? first : second;
        }
    }
    
    return (first > second) ? first : second;
}