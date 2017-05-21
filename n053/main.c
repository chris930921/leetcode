// 53. Maximum Subarray

int maxSubArray(int* nums, int numsSize) {
    int max = 0x80000000;
    int sum = 0;
    
    // 使用貪婪法，參考 Kadane's Algorithm。
    // 由左至右一個一個加總數字到 sum 中。
    // 加完後判斷如果 sum 超過 max，使 max = sum。
    
    // 假設目前 sum = -1，而下一個數字 x = 1，
    // 兩者相加後 (sum + x) = 0，比數字 x 還要小 (0 < 1)，
    // 代表如果繼續加總下去，也不可能得到更大的 sum。
    // 所以捨棄前面加總的結果，使 sum = x = 1，直接重新計算新的 sum。
    for(int i = 0; i < numsSize; i++){
        sum = sum + nums[i];
        sum = (sum > nums[i]) ? sum : nums[i];
        max = (sum > max) ? sum : max;
        printf("%d, %d \n", sum, max);
    }    
    
    return max;
}