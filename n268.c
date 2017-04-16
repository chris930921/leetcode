// 268. Missing Number

// using only constant extra space
int missingNumber(int* nums, int numsSize) {
    // 宣告 flag 包含哪些狀態。
    int POSITIVE = 0;
    int NEGATIVE = 1;
    
    // 假設輸入為 [1, 0, 3]。
    // 取出第一個數值 1 轉絕對值，將 nums[1] 轉為負數，輸入變為 [1, -0, 3]。
    // 取出第二個數值 -0 轉絕對值，將 nums[0] 轉為負數，輸入變為 [-1, -0, 3]。
    // 取出第三個數值 3 轉絕對值，將 nums[3] 轉為負數。由於已經超過輸入的大小，所以跳過不做處理。
    
    // 因為 0 不能轉負數，所以使用額外空間 flag 作標記。
    // flag 標記為 NEGATIVE，表示 nums[1] 已變成負數，即 -0。
    
    // 首先預設 missing number 為 numsSize，因為如果輸入全部變為負數，代表 missing number 是最大的數值。
    // 例如輸入是 [0, 1, 2]，則處理後會變成 [-0, -1, -2]，所以 3 是 missing number。
    
    // 以上流程處理完後，目前輸入內容為 [-1, -0, 3]。
    // 取出 num[0] 為 -1，小於 0 所以數字 0 有出現過。
    // 取出 num[1] 為 -0，因為 0 無負號不能判斷，利用 flag 得知為 NEGATIVE，所以數字 1 有出現過。
    // 取出 num[2] 為 3，大於 0 所以數字 2 沒有出現過。
    
    int index = 0;
    int flag = POSITIVE;
    
    for(int i = 0; i < numsSize; i++){
        // 取出數值後轉絕對值
        int index = (nums[i] >= 0) ? nums[i] : -nums[i];
        
        // 超過輸入的大小，所以跳過不做處理。
        if(index >= numsSize){
            continue;
        }
        
        if(nums[index] == 0){
            // 因為 0 不能轉負數，所以使用額外空間 flag 作標記。
            flag = NEGATIVE;
        }else{
            // 將 nums[index] 轉為負數
            nums[index] = -nums[index];
        }
    }
    
    int result = numsSize;
    for(int i = 0; i < numsSize; i++){
        
        // 因為 0 無負號不能判斷，利用 flag 得知數字是否有出現過。
        if(nums[i] == 0){
            if(flag == POSITIVE){
                result = i;
                break;
            }
        }
        
        // 大於 0 所以數字沒有出現過，即 missing number。
        if(nums[i] > 0){
            result = i;
            break;
        }
    }
    
    return result;
}