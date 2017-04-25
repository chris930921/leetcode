// 453. Minimum Moves to Equal Array Elements

int minMoves(int* nums, int numsSize) {
    // 把 n-1 個數值 +1 的相反意思，就是每次都只有一個數值 -1。
    // 為了向上求得平衡，每次都會有除了最大值以外的數值 +1，直到所有數值相等。
    // 如果轉換成向下求得平衡，就是每次只有最大值會 -1，直到所有數值相等。
    // 所以向下求平衡就不用考慮要選擇哪兩個數值 +1 的問題了。
    
    // 找出最小值。
    int min = 0x7FFFFFFF;
    for(int i = 0; i < numsSize; i++){
        if(nums[i] < min){
            min = nums[i];
        }
    }
    
    // 將所有數值減去最小值，最後加總。
    long remainder = 0;
    for(int i = 0; i < numsSize; i++){
        remainder += (nums[i] - min);
    }
    
    // 回傳加總結果。
    return remainder;
}